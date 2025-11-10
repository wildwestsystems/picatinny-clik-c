#include "clik_runtime.h"
#include <string.h>

const uint8_t CLIK_HEADER[CLIK_HEADER_SIZE] = { 0xAA, 0x55 };

static inline uint16_t read_u16(const uint8_t *p) {
    return ((uint16_t)p[0] << 8) | p[1];
}

static inline void write_u16(uint8_t *p, uint16_t val) {
    p[0] = (uint8_t)(val >> 8);
    p[1] = (uint8_t)(val);
}

uint8_t clik_checksum(const uint8_t *data, size_t len) {
    uint32_t sum = 0;
    for (size_t i = 0; i < len; i++) {
        sum += data[i];
    }
    return (uint8_t)(sum % 256);
}

int clik_pack_frame(uint8_t *frame_buf, size_t frame_buf_size,
                    uint16_t message_id, const uint8_t *payload,
                    uint8_t payload_len, uint8_t sync_code) {
    size_t frame_size = CLIK_HEADER_SIZE + 2 + 1 + 1 + payload_len + 1;
    if (frame_buf_size < frame_size) {
        return CLIK_ERR_BUFFER_TOO_SMALL;
    }
    size_t idx = 0;
    memcpy(frame_buf + idx, CLIK_HEADER, CLIK_HEADER_SIZE);
    idx += CLIK_HEADER_SIZE;
    write_u16(frame_buf + idx, message_id);
    idx += 2;
    frame_buf[idx++] = sync_code;
    frame_buf[idx++] = payload_len;
    if (payload_len > 0) {
        memcpy(frame_buf + idx, payload, payload_len);
        idx += payload_len;
    }
    frame_buf[idx] = clik_checksum(frame_buf, idx);
    return (int)frame_size;
}

int clik_unpack_frame(const uint8_t *frame, size_t frame_len,
                      uint16_t *message_id, uint8_t *sync_code,
                      const uint8_t **payload, uint8_t *payload_len) {
    size_t min_size = CLIK_HEADER_SIZE + 2 + 1 + 1 + 1;
    if (frame_len < min_size) {
        return CLIK_ERR_TOO_SHORT;
    }
    if (memcmp(frame, CLIK_HEADER, CLIK_HEADER_SIZE) != 0) {
        return CLIK_ERR_BAD_HEADER;
    }
    size_t idx = CLIK_HEADER_SIZE;
    *message_id = read_u16(frame + idx);
    idx += 2;
    *sync_code = frame[idx++];
    *payload_len = frame[idx++];
    size_t expected_len = CLIK_HEADER_SIZE + 2 + 1 + 1 + *payload_len + 1;
    if (frame_len != expected_len) {
        return CLIK_ERR_LENGTH_MISMATCH;
    }
    *payload = frame + idx;
    idx += *payload_len;
    uint8_t cks = frame[idx];
    uint8_t calc_cks = clik_checksum(frame, idx);
    if (cks != calc_cks) {
        return CLIK_ERR_BAD_CHECKSUM;
    }
    return CLIK_OK;
}

void clik_framer_init(clik_framer_t *framer) {
    framer->write_pos = 0;
}

void clik_framer_clear(clik_framer_t *framer) {
    framer->write_pos = 0;
}

void clik_framer_push_byte(clik_framer_t *framer, uint8_t byte) {
    if (framer->write_pos < CLIK_FRAMER_BUFFER_SIZE) {
        framer->buffer[framer->write_pos++] = byte;
    }
}

void clik_framer_push_bytes(clik_framer_t *framer, const uint8_t *data, size_t len) {
    for (size_t i = 0; i < len && framer->write_pos < CLIK_FRAMER_BUFFER_SIZE; i++) {
        framer->buffer[framer->write_pos++] = data[i];
    }
}

int clik_framer_next_frame(clik_framer_t *framer, uint16_t *message_id,
                           uint8_t *sync_code, uint8_t *payload,
                           uint8_t *payload_len) {
    while (1) {
        if (framer->write_pos < CLIK_HEADER_SIZE + 2 + 2) {
            return 0;  /* Need more data */
        }
        /* Find header */
        size_t header_pos = (size_t)-1;
        for (size_t i = 0; i <= framer->write_pos - CLIK_HEADER_SIZE; i++) {
            if (memcmp(framer->buffer + i, CLIK_HEADER, CLIK_HEADER_SIZE) == 0) {
                header_pos = i;
                break;
            }
        }
        if (header_pos == (size_t)-1) {
            /* No header found, keep last few bytes */
            if (framer->write_pos > CLIK_HEADER_SIZE - 1) {
                size_t keep = CLIK_HEADER_SIZE - 1;
                memmove(framer->buffer, framer->buffer + framer->write_pos - keep, keep);
                framer->write_pos = keep;
            }
            return 0;
        }
        /* Discard bytes before header */
        if (header_pos > 0) {
            memmove(framer->buffer, framer->buffer + header_pos, framer->write_pos - header_pos);
            framer->write_pos -= header_pos;
        }
        /* Check if we have enough for length field */
        if (framer->write_pos < CLIK_HEADER_SIZE + 2 + 1 + 1) {
            return 0;
        }
        size_t len_offset = CLIK_HEADER_SIZE + 2 + 1;
        uint8_t len = framer->buffer[len_offset];
        size_t total = CLIK_HEADER_SIZE + 2 + 1 + 1 + len + 1;
        if (framer->write_pos < total) {
            return 0;  /* Need more data */
        }
        /* Try to unpack */
        const uint8_t *payload_ptr;
        int result = clik_unpack_frame(framer->buffer, total, message_id,
                                       sync_code, &payload_ptr, payload_len);
        if (result == CLIK_OK) {
            memcpy(payload, payload_ptr, *payload_len);
            memmove(framer->buffer, framer->buffer + total, framer->write_pos - total);
            framer->write_pos -= total;
            return 1;  /* Frame found */
        } else {
            /* Bad frame, skip one byte and retry */
            memmove(framer->buffer, framer->buffer + 1, framer->write_pos - 1);
            framer->write_pos--;
        }
    }
}
