#ifndef CLIK_RUNTIME_H
#define CLIK_RUNTIME_H

#include <stdint.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

#define CLIK_HEADER_SIZE 2
extern const uint8_t CLIK_HEADER[CLIK_HEADER_SIZE];

#define CLIK_MAX_PAYLOAD_SIZE 255
#define CLIK_FRAME_OVERHEAD 7  /* header(2) + id(2) + sync(1) + len(1) + cks(1) */
#define CLIK_MAX_FRAME_SIZE (CLIK_FRAME_OVERHEAD + CLIK_MAX_PAYLOAD_SIZE)

typedef enum {
    CLIK_OK = 0,
    CLIK_ERR_TOO_SHORT = -1,
    CLIK_ERR_BAD_HEADER = -2,
    CLIK_ERR_LENGTH_MISMATCH = -3,
    CLIK_ERR_BAD_CHECKSUM = -4,
    CLIK_ERR_BUFFER_TOO_SMALL = -5,
    CLIK_ERR_INVALID_PARAM = -6,
} clik_error_t;

/* Calculate checksum for data buffer */
uint8_t clik_checksum(const uint8_t *data, size_t len);

/* Pack a message into a frame buffer
 * Returns frame size on success, negative error code on failure */
int clik_pack_frame(uint8_t *frame_buf, size_t frame_buf_size,
                    uint16_t message_id, const uint8_t *payload,
                    uint8_t payload_len, uint8_t sync_code);

/* Unpack a frame buffer into message components
 * Returns CLIK_OK on success, negative error code on failure */
int clik_unpack_frame(const uint8_t *frame, size_t frame_len,
                      uint16_t *message_id, uint8_t *sync_code,
                      const uint8_t **payload, uint8_t *payload_len);

/* Streaming frame parser */
#define CLIK_FRAMER_BUFFER_SIZE 512
typedef struct {
    uint8_t buffer[CLIK_FRAMER_BUFFER_SIZE];
    size_t write_pos;
} clik_framer_t;

void clik_framer_init(clik_framer_t *framer);
void clik_framer_clear(clik_framer_t *framer);
void clik_framer_push_byte(clik_framer_t *framer, uint8_t byte);
void clik_framer_push_bytes(clik_framer_t *framer, const uint8_t *data, size_t len);
int clik_framer_next_frame(clik_framer_t *framer, uint16_t *message_id,
                           uint8_t *sync_code, uint8_t *payload,
                           uint8_t *payload_len);

#ifdef __cplusplus
}
#endif

#endif /* CLIK_RUNTIME_H */
