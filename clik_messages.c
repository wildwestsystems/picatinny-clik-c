#include "clik_messages.h"
#include <string.h>

static inline uint16_t read_u16(const uint8_t *p) {
    return ((uint16_t)p[0] << 8) | p[1];
}

static inline void write_u16(uint8_t *p, uint16_t val) {
    p[0] = (uint8_t)(val >> 8); p[1] = (uint8_t)(val);
}

static inline uint32_t read_u32(const uint8_t *p) {
    return ((uint32_t)p[0] << 24) | ((uint32_t)p[1] << 16) | ((uint32_t)p[2] << 8) | p[3];
}

static inline void write_u32(uint8_t *p, uint32_t val) {
    p[0] = (uint8_t)(val >> 24); p[1] = (uint8_t)(val >> 16);
    p[2] = (uint8_t)(val >> 8); p[3] = (uint8_t)(val);
}

int clik_get_payload_status_req_pack(const clik_get_payload_status_req_t *msg, uint8_t *payload, uint8_t *payload_len) {
    size_t idx = 0;
    (void)msg;  /* Unused */
    *payload_len = 0;
    return CLIK_OK;
}

int clik_get_payload_status_req_unpack(clik_get_payload_status_req_t *msg, const uint8_t *payload, uint8_t payload_len) {
    size_t idx = 0;
    (void)payload_len;  /* May be unused */
    (void)msg;  /* Unused */
    (void)payload;  /* Unused */
    return CLIK_OK;
}

int clik_get_payload_status_req_to_frame(const clik_get_payload_status_req_t *msg, uint8_t *frame,
                          size_t frame_size, uint8_t sync_code) {
    uint8_t payload[CLIK_MAX_PAYLOAD_SIZE];
    uint8_t payload_len;
    int result = clik_get_payload_status_req_pack(msg, payload, &payload_len);
    if (result != CLIK_OK) return result;
    return clik_pack_frame(frame, frame_size, 0x0000, payload, payload_len, sync_code);
}

int clik_get_payload_status_req_from_frame(clik_get_payload_status_req_t *msg, const uint8_t *frame,
                            size_t frame_len, uint8_t *sync_code) {
    uint16_t message_id;
    const uint8_t *payload;
    uint8_t payload_len;
    int result = clik_unpack_frame(frame, frame_len, &message_id, sync_code, &payload, &payload_len);
    if (result != CLIK_OK) return result;
    if (message_id != 0x0000) return CLIK_ERR_INVALID_PARAM;
    return clik_get_payload_status_req_unpack(msg, payload, payload_len);
}

int clik_get_payload_status_resp_pack(const clik_get_payload_status_resp_t *msg, uint8_t *payload, uint8_t *payload_len) {
    size_t idx = 0;
    payload[idx++] = msg->error_code;
    payload[idx++] = msg->status;
    payload[idx++] = msg->available_net_interfaces;
    payload[idx++] = msg->active_net_interfaces;
    payload[idx++] = msg->number_of_functions;
    /* Array function_states (dynamic) */
    size_t function_states_count = msg->function_states_len;
    memcpy(payload + idx, msg->function_states, function_states_count);
    idx += function_states_count;
    *payload_len = (uint8_t)idx;
    return CLIK_OK;
}

int clik_get_payload_status_resp_unpack(clik_get_payload_status_resp_t *msg, const uint8_t *payload, uint8_t payload_len) {
    size_t idx = 0;
    (void)payload_len;  /* May be unused */
    msg->error_code = (clik_response_code_t)payload[idx++];
    msg->status = (clik_payload_status_t)payload[idx++];
    msg->available_net_interfaces = payload[idx++];
    msg->active_net_interfaces = payload[idx++];
    msg->number_of_functions = payload[idx++];
    size_t function_states_count = msg->number_of_functions;
    msg->function_states_len = (uint8_t)function_states_count;
    memcpy(msg->function_states, payload + idx, function_states_count);
    idx += function_states_count;
    return CLIK_OK;
}

int clik_get_payload_status_resp_to_frame(const clik_get_payload_status_resp_t *msg, uint8_t *frame,
                          size_t frame_size, uint8_t sync_code) {
    uint8_t payload[CLIK_MAX_PAYLOAD_SIZE];
    uint8_t payload_len;
    int result = clik_get_payload_status_resp_pack(msg, payload, &payload_len);
    if (result != CLIK_OK) return result;
    return clik_pack_frame(frame, frame_size, 0x0000, payload, payload_len, sync_code);
}

int clik_get_payload_status_resp_from_frame(clik_get_payload_status_resp_t *msg, const uint8_t *frame,
                            size_t frame_len, uint8_t *sync_code) {
    uint16_t message_id;
    const uint8_t *payload;
    uint8_t payload_len;
    int result = clik_unpack_frame(frame, frame_len, &message_id, sync_code, &payload, &payload_len);
    if (result != CLIK_OK) return result;
    if (message_id != 0x0000) return CLIK_ERR_INVALID_PARAM;
    return clik_get_payload_status_resp_unpack(msg, payload, payload_len);
}

int clik_get_payload_identifier_req_pack(const clik_get_payload_identifier_req_t *msg, uint8_t *payload, uint8_t *payload_len) {
    size_t idx = 0;
    (void)msg;  /* Unused */
    *payload_len = 0;
    return CLIK_OK;
}

int clik_get_payload_identifier_req_unpack(clik_get_payload_identifier_req_t *msg, const uint8_t *payload, uint8_t payload_len) {
    size_t idx = 0;
    (void)payload_len;  /* May be unused */
    (void)msg;  /* Unused */
    (void)payload;  /* Unused */
    return CLIK_OK;
}

int clik_get_payload_identifier_req_to_frame(const clik_get_payload_identifier_req_t *msg, uint8_t *frame,
                          size_t frame_size, uint8_t sync_code) {
    uint8_t payload[CLIK_MAX_PAYLOAD_SIZE];
    uint8_t payload_len;
    int result = clik_get_payload_identifier_req_pack(msg, payload, &payload_len);
    if (result != CLIK_OK) return result;
    return clik_pack_frame(frame, frame_size, 0x0001, payload, payload_len, sync_code);
}

int clik_get_payload_identifier_req_from_frame(clik_get_payload_identifier_req_t *msg, const uint8_t *frame,
                            size_t frame_len, uint8_t *sync_code) {
    uint16_t message_id;
    const uint8_t *payload;
    uint8_t payload_len;
    int result = clik_unpack_frame(frame, frame_len, &message_id, sync_code, &payload, &payload_len);
    if (result != CLIK_OK) return result;
    if (message_id != 0x0001) return CLIK_ERR_INVALID_PARAM;
    return clik_get_payload_identifier_req_unpack(msg, payload, payload_len);
}

int clik_get_payload_identifier_resp_pack(const clik_get_payload_identifier_resp_t *msg, uint8_t *payload, uint8_t *payload_len) {
    size_t idx = 0;
    payload[idx++] = msg->error_code;
    write_u16(payload + idx, msg->uid);
    idx += 2;
    /* cstring identifier */
    size_t identifier_len = strlen(msg->identifier);
    memcpy(payload + idx, msg->identifier, identifier_len);
    idx += identifier_len;
    payload[idx++] = 0;  /* null terminator */
    /* cstring version */
    size_t version_len = strlen(msg->version);
    memcpy(payload + idx, msg->version, version_len);
    idx += version_len;
    payload[idx++] = 0;  /* null terminator */
    *payload_len = (uint8_t)idx;
    return CLIK_OK;
}

int clik_get_payload_identifier_resp_unpack(clik_get_payload_identifier_resp_t *msg, const uint8_t *payload, uint8_t payload_len) {
    size_t idx = 0;
    (void)payload_len;  /* May be unused */
    msg->error_code = (clik_response_code_t)payload[idx++];
    msg->uid = read_u16(payload + idx);
    idx += 2;
    /* cstring identifier */
    size_t identifier_len = 0;
    while (idx + identifier_len < payload_len && payload[idx + identifier_len] != 0) {
        identifier_len++;
    }
    memcpy(msg->identifier, payload + idx, identifier_len);
    msg->identifier[identifier_len] = 0;
    idx += identifier_len + 1;  /* +1 for null terminator */
    /* cstring version */
    size_t version_len = 0;
    while (idx + version_len < payload_len && payload[idx + version_len] != 0) {
        version_len++;
    }
    memcpy(msg->version, payload + idx, version_len);
    msg->version[version_len] = 0;
    idx += version_len + 1;  /* +1 for null terminator */
    return CLIK_OK;
}

int clik_get_payload_identifier_resp_to_frame(const clik_get_payload_identifier_resp_t *msg, uint8_t *frame,
                          size_t frame_size, uint8_t sync_code) {
    uint8_t payload[CLIK_MAX_PAYLOAD_SIZE];
    uint8_t payload_len;
    int result = clik_get_payload_identifier_resp_pack(msg, payload, &payload_len);
    if (result != CLIK_OK) return result;
    return clik_pack_frame(frame, frame_size, 0x0001, payload, payload_len, sync_code);
}

int clik_get_payload_identifier_resp_from_frame(clik_get_payload_identifier_resp_t *msg, const uint8_t *frame,
                            size_t frame_len, uint8_t *sync_code) {
    uint16_t message_id;
    const uint8_t *payload;
    uint8_t payload_len;
    int result = clik_unpack_frame(frame, frame_len, &message_id, sync_code, &payload, &payload_len);
    if (result != CLIK_OK) return result;
    if (message_id != 0x0001) return CLIK_ERR_INVALID_PARAM;
    return clik_get_payload_identifier_resp_unpack(msg, payload, payload_len);
}

int clik_get_payload_system_config_req_pack(const clik_get_payload_system_config_req_t *msg, uint8_t *payload, uint8_t *payload_len) {
    size_t idx = 0;
    (void)msg;  /* Unused */
    *payload_len = 0;
    return CLIK_OK;
}

int clik_get_payload_system_config_req_unpack(clik_get_payload_system_config_req_t *msg, const uint8_t *payload, uint8_t payload_len) {
    size_t idx = 0;
    (void)payload_len;  /* May be unused */
    (void)msg;  /* Unused */
    (void)payload;  /* Unused */
    return CLIK_OK;
}

int clik_get_payload_system_config_req_to_frame(const clik_get_payload_system_config_req_t *msg, uint8_t *frame,
                          size_t frame_size, uint8_t sync_code) {
    uint8_t payload[CLIK_MAX_PAYLOAD_SIZE];
    uint8_t payload_len;
    int result = clik_get_payload_system_config_req_pack(msg, payload, &payload_len);
    if (result != CLIK_OK) return result;
    return clik_pack_frame(frame, frame_size, 0x0002, payload, payload_len, sync_code);
}

int clik_get_payload_system_config_req_from_frame(clik_get_payload_system_config_req_t *msg, const uint8_t *frame,
                            size_t frame_len, uint8_t *sync_code) {
    uint16_t message_id;
    const uint8_t *payload;
    uint8_t payload_len;
    int result = clik_unpack_frame(frame, frame_len, &message_id, sync_code, &payload, &payload_len);
    if (result != CLIK_OK) return result;
    if (message_id != 0x0002) return CLIK_ERR_INVALID_PARAM;
    return clik_get_payload_system_config_req_unpack(msg, payload, payload_len);
}

int clik_get_payload_system_config_resp_pack(const clik_get_payload_system_config_resp_t *msg, uint8_t *payload, uint8_t *payload_len) {
    size_t idx = 0;
    payload[idx++] = msg->error_code;
    payload[idx++] = msg->mpc;
    write_u16(payload + idx, msg->mpw);
    idx += 2;
    payload[idx++] = msg->safety_discretes_monitored;
    *payload_len = (uint8_t)idx;
    return CLIK_OK;
}

int clik_get_payload_system_config_resp_unpack(clik_get_payload_system_config_resp_t *msg, const uint8_t *payload, uint8_t payload_len) {
    size_t idx = 0;
    (void)payload_len;  /* May be unused */
    msg->error_code = (clik_response_code_t)payload[idx++];
    msg->mpc = payload[idx++];
    msg->mpw = read_u16(payload + idx);
    idx += 2;
    msg->safety_discretes_monitored = payload[idx++];
    return CLIK_OK;
}

int clik_get_payload_system_config_resp_to_frame(const clik_get_payload_system_config_resp_t *msg, uint8_t *frame,
                          size_t frame_size, uint8_t sync_code) {
    uint8_t payload[CLIK_MAX_PAYLOAD_SIZE];
    uint8_t payload_len;
    int result = clik_get_payload_system_config_resp_pack(msg, payload, &payload_len);
    if (result != CLIK_OK) return result;
    return clik_pack_frame(frame, frame_size, 0x0002, payload, payload_len, sync_code);
}

int clik_get_payload_system_config_resp_from_frame(clik_get_payload_system_config_resp_t *msg, const uint8_t *frame,
                            size_t frame_len, uint8_t *sync_code) {
    uint16_t message_id;
    const uint8_t *payload;
    uint8_t payload_len;
    int result = clik_unpack_frame(frame, frame_len, &message_id, sync_code, &payload, &payload_len);
    if (result != CLIK_OK) return result;
    if (message_id != 0x0002) return CLIK_ERR_INVALID_PARAM;
    return clik_get_payload_system_config_resp_unpack(msg, payload, payload_len);
}

int clik_get_payload_network_config_req_pack(const clik_get_payload_network_config_req_t *msg, uint8_t *payload, uint8_t *payload_len) {
    size_t idx = 0;
    payload[idx++] = msg->interface_index;
    *payload_len = (uint8_t)idx;
    return CLIK_OK;
}

int clik_get_payload_network_config_req_unpack(clik_get_payload_network_config_req_t *msg, const uint8_t *payload, uint8_t payload_len) {
    size_t idx = 0;
    (void)payload_len;  /* May be unused */
    msg->interface_index = payload[idx++];
    return CLIK_OK;
}

int clik_get_payload_network_config_req_to_frame(const clik_get_payload_network_config_req_t *msg, uint8_t *frame,
                          size_t frame_size, uint8_t sync_code) {
    uint8_t payload[CLIK_MAX_PAYLOAD_SIZE];
    uint8_t payload_len;
    int result = clik_get_payload_network_config_req_pack(msg, payload, &payload_len);
    if (result != CLIK_OK) return result;
    return clik_pack_frame(frame, frame_size, 0x0003, payload, payload_len, sync_code);
}

int clik_get_payload_network_config_req_from_frame(clik_get_payload_network_config_req_t *msg, const uint8_t *frame,
                            size_t frame_len, uint8_t *sync_code) {
    uint16_t message_id;
    const uint8_t *payload;
    uint8_t payload_len;
    int result = clik_unpack_frame(frame, frame_len, &message_id, sync_code, &payload, &payload_len);
    if (result != CLIK_OK) return result;
    if (message_id != 0x0003) return CLIK_ERR_INVALID_PARAM;
    return clik_get_payload_network_config_req_unpack(msg, payload, payload_len);
}

int clik_get_payload_network_config_resp_pack(const clik_get_payload_network_config_resp_t *msg, uint8_t *payload, uint8_t *payload_len) {
    size_t idx = 0;
    payload[idx++] = msg->error_code;
    payload[idx++] = msg->interface_index;
    payload[idx++] = msg->interface_enabled;
    /* Array ip_address (fixed size 4) */
    memcpy(payload + idx, msg->ip_address, 4);
    idx += 4;
    payload[idx++] = msg->subnet_bits;
    *payload_len = (uint8_t)idx;
    return CLIK_OK;
}

int clik_get_payload_network_config_resp_unpack(clik_get_payload_network_config_resp_t *msg, const uint8_t *payload, uint8_t payload_len) {
    size_t idx = 0;
    (void)payload_len;  /* May be unused */
    msg->error_code = (clik_response_code_t)payload[idx++];
    msg->interface_index = payload[idx++];
    msg->interface_enabled = payload[idx++];
    /* Array ip_address (fixed size 4) */
    memcpy(msg->ip_address, payload + idx, 4);
    idx += 4;
    msg->subnet_bits = payload[idx++];
    return CLIK_OK;
}

int clik_get_payload_network_config_resp_to_frame(const clik_get_payload_network_config_resp_t *msg, uint8_t *frame,
                          size_t frame_size, uint8_t sync_code) {
    uint8_t payload[CLIK_MAX_PAYLOAD_SIZE];
    uint8_t payload_len;
    int result = clik_get_payload_network_config_resp_pack(msg, payload, &payload_len);
    if (result != CLIK_OK) return result;
    return clik_pack_frame(frame, frame_size, 0x0003, payload, payload_len, sync_code);
}

int clik_get_payload_network_config_resp_from_frame(clik_get_payload_network_config_resp_t *msg, const uint8_t *frame,
                            size_t frame_len, uint8_t *sync_code) {
    uint16_t message_id;
    const uint8_t *payload;
    uint8_t payload_len;
    int result = clik_unpack_frame(frame, frame_len, &message_id, sync_code, &payload, &payload_len);
    if (result != CLIK_OK) return result;
    if (message_id != 0x0003) return CLIK_ERR_INVALID_PARAM;
    return clik_get_payload_network_config_resp_unpack(msg, payload, payload_len);
}

int clik_set_function_state_req_pack(const clik_set_function_state_req_t *msg, uint8_t *payload, uint8_t *payload_len) {
    size_t idx = 0;
    payload[idx++] = msg->function_index;
    payload[idx++] = msg->activate_function;
    *payload_len = (uint8_t)idx;
    return CLIK_OK;
}

int clik_set_function_state_req_unpack(clik_set_function_state_req_t *msg, const uint8_t *payload, uint8_t payload_len) {
    size_t idx = 0;
    (void)payload_len;  /* May be unused */
    msg->function_index = payload[idx++];
    msg->activate_function = payload[idx++];
    return CLIK_OK;
}

int clik_set_function_state_req_to_frame(const clik_set_function_state_req_t *msg, uint8_t *frame,
                          size_t frame_size, uint8_t sync_code) {
    uint8_t payload[CLIK_MAX_PAYLOAD_SIZE];
    uint8_t payload_len;
    int result = clik_set_function_state_req_pack(msg, payload, &payload_len);
    if (result != CLIK_OK) return result;
    return clik_pack_frame(frame, frame_size, 0x0004, payload, payload_len, sync_code);
}

int clik_set_function_state_req_from_frame(clik_set_function_state_req_t *msg, const uint8_t *frame,
                            size_t frame_len, uint8_t *sync_code) {
    uint16_t message_id;
    const uint8_t *payload;
    uint8_t payload_len;
    int result = clik_unpack_frame(frame, frame_len, &message_id, sync_code, &payload, &payload_len);
    if (result != CLIK_OK) return result;
    if (message_id != 0x0004) return CLIK_ERR_INVALID_PARAM;
    return clik_set_function_state_req_unpack(msg, payload, payload_len);
}

int clik_set_function_state_resp_pack(const clik_set_function_state_resp_t *msg, uint8_t *payload, uint8_t *payload_len) {
    size_t idx = 0;
    payload[idx++] = msg->error_code;
    *payload_len = (uint8_t)idx;
    return CLIK_OK;
}

int clik_set_function_state_resp_unpack(clik_set_function_state_resp_t *msg, const uint8_t *payload, uint8_t payload_len) {
    size_t idx = 0;
    (void)payload_len;  /* May be unused */
    msg->error_code = (clik_response_code_t)payload[idx++];
    return CLIK_OK;
}

int clik_set_function_state_resp_to_frame(const clik_set_function_state_resp_t *msg, uint8_t *frame,
                          size_t frame_size, uint8_t sync_code) {
    uint8_t payload[CLIK_MAX_PAYLOAD_SIZE];
    uint8_t payload_len;
    int result = clik_set_function_state_resp_pack(msg, payload, &payload_len);
    if (result != CLIK_OK) return result;
    return clik_pack_frame(frame, frame_size, 0x0004, payload, payload_len, sync_code);
}

int clik_set_function_state_resp_from_frame(clik_set_function_state_resp_t *msg, const uint8_t *frame,
                            size_t frame_len, uint8_t *sync_code) {
    uint16_t message_id;
    const uint8_t *payload;
    uint8_t payload_len;
    int result = clik_unpack_frame(frame, frame_len, &message_id, sync_code, &payload, &payload_len);
    if (result != CLIK_OK) return result;
    if (message_id != 0x0004) return CLIK_ERR_INVALID_PARAM;
    return clik_set_function_state_resp_unpack(msg, payload, payload_len);
}

int clik_set_payload_network_config_req_pack(const clik_set_payload_network_config_req_t *msg, uint8_t *payload, uint8_t *payload_len) {
    size_t idx = 0;
    payload[idx++] = msg->interface_index;
    payload[idx++] = msg->interface_enabled;
    /* Array ip_address (fixed size 4) */
    memcpy(payload + idx, msg->ip_address, 4);
    idx += 4;
    payload[idx++] = msg->subnet_bits;
    *payload_len = (uint8_t)idx;
    return CLIK_OK;
}

int clik_set_payload_network_config_req_unpack(clik_set_payload_network_config_req_t *msg, const uint8_t *payload, uint8_t payload_len) {
    size_t idx = 0;
    (void)payload_len;  /* May be unused */
    msg->interface_index = payload[idx++];
    msg->interface_enabled = payload[idx++];
    /* Array ip_address (fixed size 4) */
    memcpy(msg->ip_address, payload + idx, 4);
    idx += 4;
    msg->subnet_bits = payload[idx++];
    return CLIK_OK;
}

int clik_set_payload_network_config_req_to_frame(const clik_set_payload_network_config_req_t *msg, uint8_t *frame,
                          size_t frame_size, uint8_t sync_code) {
    uint8_t payload[CLIK_MAX_PAYLOAD_SIZE];
    uint8_t payload_len;
    int result = clik_set_payload_network_config_req_pack(msg, payload, &payload_len);
    if (result != CLIK_OK) return result;
    return clik_pack_frame(frame, frame_size, 0x0005, payload, payload_len, sync_code);
}

int clik_set_payload_network_config_req_from_frame(clik_set_payload_network_config_req_t *msg, const uint8_t *frame,
                            size_t frame_len, uint8_t *sync_code) {
    uint16_t message_id;
    const uint8_t *payload;
    uint8_t payload_len;
    int result = clik_unpack_frame(frame, frame_len, &message_id, sync_code, &payload, &payload_len);
    if (result != CLIK_OK) return result;
    if (message_id != 0x0005) return CLIK_ERR_INVALID_PARAM;
    return clik_set_payload_network_config_req_unpack(msg, payload, payload_len);
}

int clik_set_payload_network_config_resp_pack(const clik_set_payload_network_config_resp_t *msg, uint8_t *payload, uint8_t *payload_len) {
    size_t idx = 0;
    payload[idx++] = msg->error_code;
    *payload_len = (uint8_t)idx;
    return CLIK_OK;
}

int clik_set_payload_network_config_resp_unpack(clik_set_payload_network_config_resp_t *msg, const uint8_t *payload, uint8_t payload_len) {
    size_t idx = 0;
    (void)payload_len;  /* May be unused */
    msg->error_code = (clik_response_code_t)payload[idx++];
    return CLIK_OK;
}

int clik_set_payload_network_config_resp_to_frame(const clik_set_payload_network_config_resp_t *msg, uint8_t *frame,
                          size_t frame_size, uint8_t sync_code) {
    uint8_t payload[CLIK_MAX_PAYLOAD_SIZE];
    uint8_t payload_len;
    int result = clik_set_payload_network_config_resp_pack(msg, payload, &payload_len);
    if (result != CLIK_OK) return result;
    return clik_pack_frame(frame, frame_size, 0x0005, payload, payload_len, sync_code);
}

int clik_set_payload_network_config_resp_from_frame(clik_set_payload_network_config_resp_t *msg, const uint8_t *frame,
                            size_t frame_len, uint8_t *sync_code) {
    uint16_t message_id;
    const uint8_t *payload;
    uint8_t payload_len;
    int result = clik_unpack_frame(frame, frame_len, &message_id, sync_code, &payload, &payload_len);
    if (result != CLIK_OK) return result;
    if (message_id != 0x0005) return CLIK_ERR_INVALID_PARAM;
    return clik_set_payload_network_config_resp_unpack(msg, payload, payload_len);
}

int clik_set_payload_network_state_req_pack(const clik_set_payload_network_state_req_t *msg, uint8_t *payload, uint8_t *payload_len) {
    size_t idx = 0;
    payload[idx++] = msg->interface_index;
    payload[idx++] = msg->network_state;
    *payload_len = (uint8_t)idx;
    return CLIK_OK;
}

int clik_set_payload_network_state_req_unpack(clik_set_payload_network_state_req_t *msg, const uint8_t *payload, uint8_t payload_len) {
    size_t idx = 0;
    (void)payload_len;  /* May be unused */
    msg->interface_index = payload[idx++];
    msg->network_state = payload[idx++];
    return CLIK_OK;
}

int clik_set_payload_network_state_req_to_frame(const clik_set_payload_network_state_req_t *msg, uint8_t *frame,
                          size_t frame_size, uint8_t sync_code) {
    uint8_t payload[CLIK_MAX_PAYLOAD_SIZE];
    uint8_t payload_len;
    int result = clik_set_payload_network_state_req_pack(msg, payload, &payload_len);
    if (result != CLIK_OK) return result;
    return clik_pack_frame(frame, frame_size, 0x0006, payload, payload_len, sync_code);
}

int clik_set_payload_network_state_req_from_frame(clik_set_payload_network_state_req_t *msg, const uint8_t *frame,
                            size_t frame_len, uint8_t *sync_code) {
    uint16_t message_id;
    const uint8_t *payload;
    uint8_t payload_len;
    int result = clik_unpack_frame(frame, frame_len, &message_id, sync_code, &payload, &payload_len);
    if (result != CLIK_OK) return result;
    if (message_id != 0x0006) return CLIK_ERR_INVALID_PARAM;
    return clik_set_payload_network_state_req_unpack(msg, payload, payload_len);
}

int clik_set_payload_network_state_resp_pack(const clik_set_payload_network_state_resp_t *msg, uint8_t *payload, uint8_t *payload_len) {
    size_t idx = 0;
    payload[idx++] = msg->error_code;
    *payload_len = (uint8_t)idx;
    return CLIK_OK;
}

int clik_set_payload_network_state_resp_unpack(clik_set_payload_network_state_resp_t *msg, const uint8_t *payload, uint8_t payload_len) {
    size_t idx = 0;
    (void)payload_len;  /* May be unused */
    msg->error_code = (clik_response_code_t)payload[idx++];
    return CLIK_OK;
}

int clik_set_payload_network_state_resp_to_frame(const clik_set_payload_network_state_resp_t *msg, uint8_t *frame,
                          size_t frame_size, uint8_t sync_code) {
    uint8_t payload[CLIK_MAX_PAYLOAD_SIZE];
    uint8_t payload_len;
    int result = clik_set_payload_network_state_resp_pack(msg, payload, &payload_len);
    if (result != CLIK_OK) return result;
    return clik_pack_frame(frame, frame_size, 0x0006, payload, payload_len, sync_code);
}

int clik_set_payload_network_state_resp_from_frame(clik_set_payload_network_state_resp_t *msg, const uint8_t *frame,
                            size_t frame_len, uint8_t *sync_code) {
    uint16_t message_id;
    const uint8_t *payload;
    uint8_t payload_len;
    int result = clik_unpack_frame(frame, frame_len, &message_id, sync_code, &payload, &payload_len);
    if (result != CLIK_OK) return result;
    if (message_id != 0x0006) return CLIK_ERR_INVALID_PARAM;
    return clik_set_payload_network_state_resp_unpack(msg, payload, payload_len);
}

int clik_get_platform_status_req_pack(const clik_get_platform_status_req_t *msg, uint8_t *payload, uint8_t *payload_len) {
    size_t idx = 0;
    (void)msg;  /* Unused */
    *payload_len = 0;
    return CLIK_OK;
}

int clik_get_platform_status_req_unpack(clik_get_platform_status_req_t *msg, const uint8_t *payload, uint8_t payload_len) {
    size_t idx = 0;
    (void)payload_len;  /* May be unused */
    (void)msg;  /* Unused */
    (void)payload;  /* Unused */
    return CLIK_OK;
}

int clik_get_platform_status_req_to_frame(const clik_get_platform_status_req_t *msg, uint8_t *frame,
                          size_t frame_size, uint8_t sync_code) {
    uint8_t payload[CLIK_MAX_PAYLOAD_SIZE];
    uint8_t payload_len;
    int result = clik_get_platform_status_req_pack(msg, payload, &payload_len);
    if (result != CLIK_OK) return result;
    return clik_pack_frame(frame, frame_size, 0x0000, payload, payload_len, sync_code);
}

int clik_get_platform_status_req_from_frame(clik_get_platform_status_req_t *msg, const uint8_t *frame,
                            size_t frame_len, uint8_t *sync_code) {
    uint16_t message_id;
    const uint8_t *payload;
    uint8_t payload_len;
    int result = clik_unpack_frame(frame, frame_len, &message_id, sync_code, &payload, &payload_len);
    if (result != CLIK_OK) return result;
    if (message_id != 0x0000) return CLIK_ERR_INVALID_PARAM;
    return clik_get_platform_status_req_unpack(msg, payload, payload_len);
}

int clik_get_platform_status_resp_pack(const clik_get_platform_status_resp_t *msg, uint8_t *payload, uint8_t *payload_len) {
    size_t idx = 0;
    payload[idx++] = msg->error_code;
    payload[idx++] = msg->payloads_supported;
    payload[idx++] = msg->payloads_connected;
    payload[idx++] = msg->status;
    write_u16(payload + idx, msg->platform_voltage);
    idx += 2;
    write_u16(payload + idx, msg->platform_current_draw);
    idx += 2;
    write_u16(payload + idx, msg->clik_voltage);
    idx += 2;
    write_u16(payload + idx, msg->clik_current_draw);
    idx += 2;
    *payload_len = (uint8_t)idx;
    return CLIK_OK;
}

int clik_get_platform_status_resp_unpack(clik_get_platform_status_resp_t *msg, const uint8_t *payload, uint8_t payload_len) {
    size_t idx = 0;
    (void)payload_len;  /* May be unused */
    msg->error_code = (clik_response_code_t)payload[idx++];
    msg->payloads_supported = payload[idx++];
    msg->payloads_connected = payload[idx++];
    msg->status = payload[idx++];
    msg->platform_voltage = read_u16(payload + idx);
    idx += 2;
    msg->platform_current_draw = read_u16(payload + idx);
    idx += 2;
    msg->clik_voltage = read_u16(payload + idx);
    idx += 2;
    msg->clik_current_draw = read_u16(payload + idx);
    idx += 2;
    return CLIK_OK;
}

int clik_get_platform_status_resp_to_frame(const clik_get_platform_status_resp_t *msg, uint8_t *frame,
                          size_t frame_size, uint8_t sync_code) {
    uint8_t payload[CLIK_MAX_PAYLOAD_SIZE];
    uint8_t payload_len;
    int result = clik_get_platform_status_resp_pack(msg, payload, &payload_len);
    if (result != CLIK_OK) return result;
    return clik_pack_frame(frame, frame_size, 0x0000, payload, payload_len, sync_code);
}

int clik_get_platform_status_resp_from_frame(clik_get_platform_status_resp_t *msg, const uint8_t *frame,
                            size_t frame_len, uint8_t *sync_code) {
    uint16_t message_id;
    const uint8_t *payload;
    uint8_t payload_len;
    int result = clik_unpack_frame(frame, frame_len, &message_id, sync_code, &payload, &payload_len);
    if (result != CLIK_OK) return result;
    if (message_id != 0x0000) return CLIK_ERR_INVALID_PARAM;
    return clik_get_platform_status_resp_unpack(msg, payload, payload_len);
}

int clik_get_platform_identifier_req_pack(const clik_get_platform_identifier_req_t *msg, uint8_t *payload, uint8_t *payload_len) {
    size_t idx = 0;
    (void)msg;  /* Unused */
    *payload_len = 0;
    return CLIK_OK;
}

int clik_get_platform_identifier_req_unpack(clik_get_platform_identifier_req_t *msg, const uint8_t *payload, uint8_t payload_len) {
    size_t idx = 0;
    (void)payload_len;  /* May be unused */
    (void)msg;  /* Unused */
    (void)payload;  /* Unused */
    return CLIK_OK;
}

int clik_get_platform_identifier_req_to_frame(const clik_get_platform_identifier_req_t *msg, uint8_t *frame,
                          size_t frame_size, uint8_t sync_code) {
    uint8_t payload[CLIK_MAX_PAYLOAD_SIZE];
    uint8_t payload_len;
    int result = clik_get_platform_identifier_req_pack(msg, payload, &payload_len);
    if (result != CLIK_OK) return result;
    return clik_pack_frame(frame, frame_size, 0x0001, payload, payload_len, sync_code);
}

int clik_get_platform_identifier_req_from_frame(clik_get_platform_identifier_req_t *msg, const uint8_t *frame,
                            size_t frame_len, uint8_t *sync_code) {
    uint16_t message_id;
    const uint8_t *payload;
    uint8_t payload_len;
    int result = clik_unpack_frame(frame, frame_len, &message_id, sync_code, &payload, &payload_len);
    if (result != CLIK_OK) return result;
    if (message_id != 0x0001) return CLIK_ERR_INVALID_PARAM;
    return clik_get_platform_identifier_req_unpack(msg, payload, payload_len);
}

int clik_get_platform_identifier_resp_pack(const clik_get_platform_identifier_resp_t *msg, uint8_t *payload, uint8_t *payload_len) {
    size_t idx = 0;
    payload[idx++] = msg->error_code;
    write_u16(payload + idx, msg->uid);
    idx += 2;
    /* cstring identifier */
    size_t identifier_len = strlen(msg->identifier);
    memcpy(payload + idx, msg->identifier, identifier_len);
    idx += identifier_len;
    payload[idx++] = 0;  /* null terminator */
    /* cstring version */
    size_t version_len = strlen(msg->version);
    memcpy(payload + idx, msg->version, version_len);
    idx += version_len;
    payload[idx++] = 0;  /* null terminator */
    *payload_len = (uint8_t)idx;
    return CLIK_OK;
}

int clik_get_platform_identifier_resp_unpack(clik_get_platform_identifier_resp_t *msg, const uint8_t *payload, uint8_t payload_len) {
    size_t idx = 0;
    (void)payload_len;  /* May be unused */
    msg->error_code = (clik_response_code_t)payload[idx++];
    msg->uid = read_u16(payload + idx);
    idx += 2;
    /* cstring identifier */
    size_t identifier_len = 0;
    while (idx + identifier_len < payload_len && payload[idx + identifier_len] != 0) {
        identifier_len++;
    }
    memcpy(msg->identifier, payload + idx, identifier_len);
    msg->identifier[identifier_len] = 0;
    idx += identifier_len + 1;  /* +1 for null terminator */
    /* cstring version */
    size_t version_len = 0;
    while (idx + version_len < payload_len && payload[idx + version_len] != 0) {
        version_len++;
    }
    memcpy(msg->version, payload + idx, version_len);
    msg->version[version_len] = 0;
    idx += version_len + 1;  /* +1 for null terminator */
    return CLIK_OK;
}

int clik_get_platform_identifier_resp_to_frame(const clik_get_platform_identifier_resp_t *msg, uint8_t *frame,
                          size_t frame_size, uint8_t sync_code) {
    uint8_t payload[CLIK_MAX_PAYLOAD_SIZE];
    uint8_t payload_len;
    int result = clik_get_platform_identifier_resp_pack(msg, payload, &payload_len);
    if (result != CLIK_OK) return result;
    return clik_pack_frame(frame, frame_size, 0x0001, payload, payload_len, sync_code);
}

int clik_get_platform_identifier_resp_from_frame(clik_get_platform_identifier_resp_t *msg, const uint8_t *frame,
                            size_t frame_len, uint8_t *sync_code) {
    uint16_t message_id;
    const uint8_t *payload;
    uint8_t payload_len;
    int result = clik_unpack_frame(frame, frame_len, &message_id, sync_code, &payload, &payload_len);
    if (result != CLIK_OK) return result;
    if (message_id != 0x0001) return CLIK_ERR_INVALID_PARAM;
    return clik_get_platform_identifier_resp_unpack(msg, payload, payload_len);
}

int clik_get_platform_system_config_req_pack(const clik_get_platform_system_config_req_t *msg, uint8_t *payload, uint8_t *payload_len) {
    size_t idx = 0;
    (void)msg;  /* Unused */
    *payload_len = 0;
    return CLIK_OK;
}

int clik_get_platform_system_config_req_unpack(clik_get_platform_system_config_req_t *msg, const uint8_t *payload, uint8_t payload_len) {
    size_t idx = 0;
    (void)payload_len;  /* May be unused */
    (void)msg;  /* Unused */
    (void)payload;  /* Unused */
    return CLIK_OK;
}

int clik_get_platform_system_config_req_to_frame(const clik_get_platform_system_config_req_t *msg, uint8_t *frame,
                          size_t frame_size, uint8_t sync_code) {
    uint8_t payload[CLIK_MAX_PAYLOAD_SIZE];
    uint8_t payload_len;
    int result = clik_get_platform_system_config_req_pack(msg, payload, &payload_len);
    if (result != CLIK_OK) return result;
    return clik_pack_frame(frame, frame_size, 0x0002, payload, payload_len, sync_code);
}

int clik_get_platform_system_config_req_from_frame(clik_get_platform_system_config_req_t *msg, const uint8_t *frame,
                            size_t frame_len, uint8_t *sync_code) {
    uint16_t message_id;
    const uint8_t *payload;
    uint8_t payload_len;
    int result = clik_unpack_frame(frame, frame_len, &message_id, sync_code, &payload, &payload_len);
    if (result != CLIK_OK) return result;
    if (message_id != 0x0002) return CLIK_ERR_INVALID_PARAM;
    return clik_get_platform_system_config_req_unpack(msg, payload, payload_len);
}

int clik_get_platform_system_config_resp_pack(const clik_get_platform_system_config_resp_t *msg, uint8_t *payload, uint8_t *payload_len) {
    size_t idx = 0;
    payload[idx++] = msg->error_code;
    payload[idx++] = msg->mac;
    write_u16(payload + idx, msg->apw);
    idx += 2;
    *payload_len = (uint8_t)idx;
    return CLIK_OK;
}

int clik_get_platform_system_config_resp_unpack(clik_get_platform_system_config_resp_t *msg, const uint8_t *payload, uint8_t payload_len) {
    size_t idx = 0;
    (void)payload_len;  /* May be unused */
    msg->error_code = (clik_response_code_t)payload[idx++];
    msg->mac = payload[idx++];
    msg->apw = read_u16(payload + idx);
    idx += 2;
    return CLIK_OK;
}

int clik_get_platform_system_config_resp_to_frame(const clik_get_platform_system_config_resp_t *msg, uint8_t *frame,
                          size_t frame_size, uint8_t sync_code) {
    uint8_t payload[CLIK_MAX_PAYLOAD_SIZE];
    uint8_t payload_len;
    int result = clik_get_platform_system_config_resp_pack(msg, payload, &payload_len);
    if (result != CLIK_OK) return result;
    return clik_pack_frame(frame, frame_size, 0x0002, payload, payload_len, sync_code);
}

int clik_get_platform_system_config_resp_from_frame(clik_get_platform_system_config_resp_t *msg, const uint8_t *frame,
                            size_t frame_len, uint8_t *sync_code) {
    uint16_t message_id;
    const uint8_t *payload;
    uint8_t payload_len;
    int result = clik_unpack_frame(frame, frame_len, &message_id, sync_code, &payload, &payload_len);
    if (result != CLIK_OK) return result;
    if (message_id != 0x0002) return CLIK_ERR_INVALID_PARAM;
    return clik_get_platform_system_config_resp_unpack(msg, payload, payload_len);
}

int clik_get_platform_network_config_req_pack(const clik_get_platform_network_config_req_t *msg, uint8_t *payload, uint8_t *payload_len) {
    size_t idx = 0;
    payload[idx++] = msg->interface_index;
    *payload_len = (uint8_t)idx;
    return CLIK_OK;
}

int clik_get_platform_network_config_req_unpack(clik_get_platform_network_config_req_t *msg, const uint8_t *payload, uint8_t payload_len) {
    size_t idx = 0;
    (void)payload_len;  /* May be unused */
    msg->interface_index = payload[idx++];
    return CLIK_OK;
}

int clik_get_platform_network_config_req_to_frame(const clik_get_platform_network_config_req_t *msg, uint8_t *frame,
                          size_t frame_size, uint8_t sync_code) {
    uint8_t payload[CLIK_MAX_PAYLOAD_SIZE];
    uint8_t payload_len;
    int result = clik_get_platform_network_config_req_pack(msg, payload, &payload_len);
    if (result != CLIK_OK) return result;
    return clik_pack_frame(frame, frame_size, 0x0003, payload, payload_len, sync_code);
}

int clik_get_platform_network_config_req_from_frame(clik_get_platform_network_config_req_t *msg, const uint8_t *frame,
                            size_t frame_len, uint8_t *sync_code) {
    uint16_t message_id;
    const uint8_t *payload;
    uint8_t payload_len;
    int result = clik_unpack_frame(frame, frame_len, &message_id, sync_code, &payload, &payload_len);
    if (result != CLIK_OK) return result;
    if (message_id != 0x0003) return CLIK_ERR_INVALID_PARAM;
    return clik_get_platform_network_config_req_unpack(msg, payload, payload_len);
}

int clik_get_platform_network_config_resp_pack(const clik_get_platform_network_config_resp_t *msg, uint8_t *payload, uint8_t *payload_len) {
    size_t idx = 0;
    payload[idx++] = msg->error_code;
    payload[idx++] = msg->interface_index;
    /* Array ip_address (fixed size 4) */
    memcpy(payload + idx, msg->ip_address, 4);
    idx += 4;
    payload[idx++] = msg->subnet_bits;
    write_u16(payload + idx, msg->udp_port);
    idx += 2;
    *payload_len = (uint8_t)idx;
    return CLIK_OK;
}

int clik_get_platform_network_config_resp_unpack(clik_get_platform_network_config_resp_t *msg, const uint8_t *payload, uint8_t payload_len) {
    size_t idx = 0;
    (void)payload_len;  /* May be unused */
    msg->error_code = (clik_response_code_t)payload[idx++];
    msg->interface_index = payload[idx++];
    /* Array ip_address (fixed size 4) */
    memcpy(msg->ip_address, payload + idx, 4);
    idx += 4;
    msg->subnet_bits = payload[idx++];
    msg->udp_port = read_u16(payload + idx);
    idx += 2;
    return CLIK_OK;
}

int clik_get_platform_network_config_resp_to_frame(const clik_get_platform_network_config_resp_t *msg, uint8_t *frame,
                          size_t frame_size, uint8_t sync_code) {
    uint8_t payload[CLIK_MAX_PAYLOAD_SIZE];
    uint8_t payload_len;
    int result = clik_get_platform_network_config_resp_pack(msg, payload, &payload_len);
    if (result != CLIK_OK) return result;
    return clik_pack_frame(frame, frame_size, 0x0003, payload, payload_len, sync_code);
}

int clik_get_platform_network_config_resp_from_frame(clik_get_platform_network_config_resp_t *msg, const uint8_t *frame,
                            size_t frame_len, uint8_t *sync_code) {
    uint16_t message_id;
    const uint8_t *payload;
    uint8_t payload_len;
    int result = clik_unpack_frame(frame, frame_len, &message_id, sync_code, &payload, &payload_len);
    if (result != CLIK_OK) return result;
    if (message_id != 0x0003) return CLIK_ERR_INVALID_PARAM;
    return clik_get_platform_network_config_resp_unpack(msg, payload, payload_len);
}

int clik_set_platform_power_req_pack(const clik_set_platform_power_req_t *msg, uint8_t *payload, uint8_t *payload_len) {
    size_t idx = 0;
    payload[idx++] = msg->power_state;
    *payload_len = (uint8_t)idx;
    return CLIK_OK;
}

int clik_set_platform_power_req_unpack(clik_set_platform_power_req_t *msg, const uint8_t *payload, uint8_t payload_len) {
    size_t idx = 0;
    (void)payload_len;  /* May be unused */
    msg->power_state = payload[idx++];
    return CLIK_OK;
}

int clik_set_platform_power_req_to_frame(const clik_set_platform_power_req_t *msg, uint8_t *frame,
                          size_t frame_size, uint8_t sync_code) {
    uint8_t payload[CLIK_MAX_PAYLOAD_SIZE];
    uint8_t payload_len;
    int result = clik_set_platform_power_req_pack(msg, payload, &payload_len);
    if (result != CLIK_OK) return result;
    return clik_pack_frame(frame, frame_size, 0x0004, payload, payload_len, sync_code);
}

int clik_set_platform_power_req_from_frame(clik_set_platform_power_req_t *msg, const uint8_t *frame,
                            size_t frame_len, uint8_t *sync_code) {
    uint16_t message_id;
    const uint8_t *payload;
    uint8_t payload_len;
    int result = clik_unpack_frame(frame, frame_len, &message_id, sync_code, &payload, &payload_len);
    if (result != CLIK_OK) return result;
    if (message_id != 0x0004) return CLIK_ERR_INVALID_PARAM;
    return clik_set_platform_power_req_unpack(msg, payload, payload_len);
}

int clik_set_platform_power_resp_pack(const clik_set_platform_power_resp_t *msg, uint8_t *payload, uint8_t *payload_len) {
    size_t idx = 0;
    payload[idx++] = msg->error_code;
    *payload_len = (uint8_t)idx;
    return CLIK_OK;
}

int clik_set_platform_power_resp_unpack(clik_set_platform_power_resp_t *msg, const uint8_t *payload, uint8_t payload_len) {
    size_t idx = 0;
    (void)payload_len;  /* May be unused */
    msg->error_code = (clik_response_code_t)payload[idx++];
    return CLIK_OK;
}

int clik_set_platform_power_resp_to_frame(const clik_set_platform_power_resp_t *msg, uint8_t *frame,
                          size_t frame_size, uint8_t sync_code) {
    uint8_t payload[CLIK_MAX_PAYLOAD_SIZE];
    uint8_t payload_len;
    int result = clik_set_platform_power_resp_pack(msg, payload, &payload_len);
    if (result != CLIK_OK) return result;
    return clik_pack_frame(frame, frame_size, 0x0004, payload, payload_len, sync_code);
}

int clik_set_platform_power_resp_from_frame(clik_set_platform_power_resp_t *msg, const uint8_t *frame,
                            size_t frame_len, uint8_t *sync_code) {
    uint16_t message_id;
    const uint8_t *payload;
    uint8_t payload_len;
    int result = clik_unpack_frame(frame, frame_len, &message_id, sync_code, &payload, &payload_len);
    if (result != CLIK_OK) return result;
    if (message_id != 0x0004) return CLIK_ERR_INVALID_PARAM;
    return clik_set_platform_power_resp_unpack(msg, payload, payload_len);
}

int clik_get_payload_channel_status_req_pack(const clik_get_payload_channel_status_req_t *msg, uint8_t *payload, uint8_t *payload_len) {
    size_t idx = 0;
    (void)msg;  /* Unused */
    *payload_len = 0;
    return CLIK_OK;
}

int clik_get_payload_channel_status_req_unpack(clik_get_payload_channel_status_req_t *msg, const uint8_t *payload, uint8_t payload_len) {
    size_t idx = 0;
    (void)payload_len;  /* May be unused */
    (void)msg;  /* Unused */
    (void)payload;  /* Unused */
    return CLIK_OK;
}

int clik_get_payload_channel_status_req_to_frame(const clik_get_payload_channel_status_req_t *msg, uint8_t *frame,
                          size_t frame_size, uint8_t sync_code) {
    uint8_t payload[CLIK_MAX_PAYLOAD_SIZE];
    uint8_t payload_len;
    int result = clik_get_payload_channel_status_req_pack(msg, payload, &payload_len);
    if (result != CLIK_OK) return result;
    return clik_pack_frame(frame, frame_size, 0x0000, payload, payload_len, sync_code);
}

int clik_get_payload_channel_status_req_from_frame(clik_get_payload_channel_status_req_t *msg, const uint8_t *frame,
                            size_t frame_len, uint8_t *sync_code) {
    uint16_t message_id;
    const uint8_t *payload;
    uint8_t payload_len;
    int result = clik_unpack_frame(frame, frame_len, &message_id, sync_code, &payload, &payload_len);
    if (result != CLIK_OK) return result;
    if (message_id != 0x0000) return CLIK_ERR_INVALID_PARAM;
    return clik_get_payload_channel_status_req_unpack(msg, payload, payload_len);
}

int clik_get_payload_channel_status_resp_pack(const clik_get_payload_channel_status_resp_t *msg, uint8_t *payload, uint8_t *payload_len) {
    size_t idx = 0;
    payload[idx++] = msg->error_code;
    payload[idx++] = msg->payload_connected;
    write_u16(payload + idx, msg->payload_voltage);
    idx += 2;
    write_u16(payload + idx, msg->payload_current_draw);
    idx += 2;
    payload[idx++] = msg->payload_channel_status;
    *payload_len = (uint8_t)idx;
    return CLIK_OK;
}

int clik_get_payload_channel_status_resp_unpack(clik_get_payload_channel_status_resp_t *msg, const uint8_t *payload, uint8_t payload_len) {
    size_t idx = 0;
    (void)payload_len;  /* May be unused */
    msg->error_code = (clik_response_code_t)payload[idx++];
    msg->payload_connected = payload[idx++];
    msg->payload_voltage = read_u16(payload + idx);
    idx += 2;
    msg->payload_current_draw = read_u16(payload + idx);
    idx += 2;
    msg->payload_channel_status = (clik_channel_status_t)payload[idx++];
    return CLIK_OK;
}

int clik_get_payload_channel_status_resp_to_frame(const clik_get_payload_channel_status_resp_t *msg, uint8_t *frame,
                          size_t frame_size, uint8_t sync_code) {
    uint8_t payload[CLIK_MAX_PAYLOAD_SIZE];
    uint8_t payload_len;
    int result = clik_get_payload_channel_status_resp_pack(msg, payload, &payload_len);
    if (result != CLIK_OK) return result;
    return clik_pack_frame(frame, frame_size, 0x0000, payload, payload_len, sync_code);
}

int clik_get_payload_channel_status_resp_from_frame(clik_get_payload_channel_status_resp_t *msg, const uint8_t *frame,
                            size_t frame_len, uint8_t *sync_code) {
    uint16_t message_id;
    const uint8_t *payload;
    uint8_t payload_len;
    int result = clik_unpack_frame(frame, frame_len, &message_id, sync_code, &payload, &payload_len);
    if (result != CLIK_OK) return result;
    if (message_id != 0x0000) return CLIK_ERR_INVALID_PARAM;
    return clik_get_payload_channel_status_resp_unpack(msg, payload, payload_len);
}

int clik_get_payload_channel_power_config_req_pack(const clik_get_payload_channel_power_config_req_t *msg, uint8_t *payload, uint8_t *payload_len) {
    size_t idx = 0;
    (void)msg;  /* Unused */
    *payload_len = 0;
    return CLIK_OK;
}

int clik_get_payload_channel_power_config_req_unpack(clik_get_payload_channel_power_config_req_t *msg, const uint8_t *payload, uint8_t payload_len) {
    size_t idx = 0;
    (void)payload_len;  /* May be unused */
    (void)msg;  /* Unused */
    (void)payload;  /* Unused */
    return CLIK_OK;
}

int clik_get_payload_channel_power_config_req_to_frame(const clik_get_payload_channel_power_config_req_t *msg, uint8_t *frame,
                          size_t frame_size, uint8_t sync_code) {
    uint8_t payload[CLIK_MAX_PAYLOAD_SIZE];
    uint8_t payload_len;
    int result = clik_get_payload_channel_power_config_req_pack(msg, payload, &payload_len);
    if (result != CLIK_OK) return result;
    return clik_pack_frame(frame, frame_size, 0x0001, payload, payload_len, sync_code);
}

int clik_get_payload_channel_power_config_req_from_frame(clik_get_payload_channel_power_config_req_t *msg, const uint8_t *frame,
                            size_t frame_len, uint8_t *sync_code) {
    uint16_t message_id;
    const uint8_t *payload;
    uint8_t payload_len;
    int result = clik_unpack_frame(frame, frame_len, &message_id, sync_code, &payload, &payload_len);
    if (result != CLIK_OK) return result;
    if (message_id != 0x0001) return CLIK_ERR_INVALID_PARAM;
    return clik_get_payload_channel_power_config_req_unpack(msg, payload, payload_len);
}

int clik_get_payload_channel_power_config_resp_pack(const clik_get_payload_channel_power_config_resp_t *msg, uint8_t *payload, uint8_t *payload_len) {
    size_t idx = 0;
    payload[idx++] = msg->error_code;
    write_u16(payload + idx, msg->current_limit);
    idx += 2;
    payload[idx++] = msg->power_options;
    *payload_len = (uint8_t)idx;
    return CLIK_OK;
}

int clik_get_payload_channel_power_config_resp_unpack(clik_get_payload_channel_power_config_resp_t *msg, const uint8_t *payload, uint8_t payload_len) {
    size_t idx = 0;
    (void)payload_len;  /* May be unused */
    msg->error_code = (clik_response_code_t)payload[idx++];
    msg->current_limit = read_u16(payload + idx);
    idx += 2;
    msg->power_options = (clik_power_options_t)payload[idx++];
    return CLIK_OK;
}

int clik_get_payload_channel_power_config_resp_to_frame(const clik_get_payload_channel_power_config_resp_t *msg, uint8_t *frame,
                          size_t frame_size, uint8_t sync_code) {
    uint8_t payload[CLIK_MAX_PAYLOAD_SIZE];
    uint8_t payload_len;
    int result = clik_get_payload_channel_power_config_resp_pack(msg, payload, &payload_len);
    if (result != CLIK_OK) return result;
    return clik_pack_frame(frame, frame_size, 0x0001, payload, payload_len, sync_code);
}

int clik_get_payload_channel_power_config_resp_from_frame(clik_get_payload_channel_power_config_resp_t *msg, const uint8_t *frame,
                            size_t frame_len, uint8_t *sync_code) {
    uint16_t message_id;
    const uint8_t *payload;
    uint8_t payload_len;
    int result = clik_unpack_frame(frame, frame_len, &message_id, sync_code, &payload, &payload_len);
    if (result != CLIK_OK) return result;
    if (message_id != 0x0001) return CLIK_ERR_INVALID_PARAM;
    return clik_get_payload_channel_power_config_resp_unpack(msg, payload, payload_len);
}

int clik_set_payload_channel_power_req_pack(const clik_set_payload_channel_power_req_t *msg, uint8_t *payload, uint8_t *payload_len) {
    size_t idx = 0;
    payload[idx++] = msg->power_state;
    *payload_len = (uint8_t)idx;
    return CLIK_OK;
}

int clik_set_payload_channel_power_req_unpack(clik_set_payload_channel_power_req_t *msg, const uint8_t *payload, uint8_t payload_len) {
    size_t idx = 0;
    (void)payload_len;  /* May be unused */
    msg->power_state = payload[idx++];
    return CLIK_OK;
}

int clik_set_payload_channel_power_req_to_frame(const clik_set_payload_channel_power_req_t *msg, uint8_t *frame,
                          size_t frame_size, uint8_t sync_code) {
    uint8_t payload[CLIK_MAX_PAYLOAD_SIZE];
    uint8_t payload_len;
    int result = clik_set_payload_channel_power_req_pack(msg, payload, &payload_len);
    if (result != CLIK_OK) return result;
    return clik_pack_frame(frame, frame_size, 0x0002, payload, payload_len, sync_code);
}

int clik_set_payload_channel_power_req_from_frame(clik_set_payload_channel_power_req_t *msg, const uint8_t *frame,
                            size_t frame_len, uint8_t *sync_code) {
    uint16_t message_id;
    const uint8_t *payload;
    uint8_t payload_len;
    int result = clik_unpack_frame(frame, frame_len, &message_id, sync_code, &payload, &payload_len);
    if (result != CLIK_OK) return result;
    if (message_id != 0x0002) return CLIK_ERR_INVALID_PARAM;
    return clik_set_payload_channel_power_req_unpack(msg, payload, payload_len);
}

int clik_set_payload_channel_power_resp_pack(const clik_set_payload_channel_power_resp_t *msg, uint8_t *payload, uint8_t *payload_len) {
    size_t idx = 0;
    payload[idx++] = msg->error_code;
    *payload_len = (uint8_t)idx;
    return CLIK_OK;
}

int clik_set_payload_channel_power_resp_unpack(clik_set_payload_channel_power_resp_t *msg, const uint8_t *payload, uint8_t payload_len) {
    size_t idx = 0;
    (void)payload_len;  /* May be unused */
    msg->error_code = (clik_response_code_t)payload[idx++];
    return CLIK_OK;
}

int clik_set_payload_channel_power_resp_to_frame(const clik_set_payload_channel_power_resp_t *msg, uint8_t *frame,
                          size_t frame_size, uint8_t sync_code) {
    uint8_t payload[CLIK_MAX_PAYLOAD_SIZE];
    uint8_t payload_len;
    int result = clik_set_payload_channel_power_resp_pack(msg, payload, &payload_len);
    if (result != CLIK_OK) return result;
    return clik_pack_frame(frame, frame_size, 0x0002, payload, payload_len, sync_code);
}

int clik_set_payload_channel_power_resp_from_frame(clik_set_payload_channel_power_resp_t *msg, const uint8_t *frame,
                            size_t frame_len, uint8_t *sync_code) {
    uint16_t message_id;
    const uint8_t *payload;
    uint8_t payload_len;
    int result = clik_unpack_frame(frame, frame_len, &message_id, sync_code, &payload, &payload_len);
    if (result != CLIK_OK) return result;
    if (message_id != 0x0002) return CLIK_ERR_INVALID_PARAM;
    return clik_set_payload_channel_power_resp_unpack(msg, payload, payload_len);
}

int clik_set_payload_channel_current_limit_req_pack(const clik_set_payload_channel_current_limit_req_t *msg, uint8_t *payload, uint8_t *payload_len) {
    size_t idx = 0;
    payload[idx++] = msg->current_limit;
    *payload_len = (uint8_t)idx;
    return CLIK_OK;
}

int clik_set_payload_channel_current_limit_req_unpack(clik_set_payload_channel_current_limit_req_t *msg, const uint8_t *payload, uint8_t payload_len) {
    size_t idx = 0;
    (void)payload_len;  /* May be unused */
    msg->current_limit = payload[idx++];
    return CLIK_OK;
}

int clik_set_payload_channel_current_limit_req_to_frame(const clik_set_payload_channel_current_limit_req_t *msg, uint8_t *frame,
                          size_t frame_size, uint8_t sync_code) {
    uint8_t payload[CLIK_MAX_PAYLOAD_SIZE];
    uint8_t payload_len;
    int result = clik_set_payload_channel_current_limit_req_pack(msg, payload, &payload_len);
    if (result != CLIK_OK) return result;
    return clik_pack_frame(frame, frame_size, 0x0003, payload, payload_len, sync_code);
}

int clik_set_payload_channel_current_limit_req_from_frame(clik_set_payload_channel_current_limit_req_t *msg, const uint8_t *frame,
                            size_t frame_len, uint8_t *sync_code) {
    uint16_t message_id;
    const uint8_t *payload;
    uint8_t payload_len;
    int result = clik_unpack_frame(frame, frame_len, &message_id, sync_code, &payload, &payload_len);
    if (result != CLIK_OK) return result;
    if (message_id != 0x0003) return CLIK_ERR_INVALID_PARAM;
    return clik_set_payload_channel_current_limit_req_unpack(msg, payload, payload_len);
}

int clik_set_payload_channel_current_limit_resp_pack(const clik_set_payload_channel_current_limit_resp_t *msg, uint8_t *payload, uint8_t *payload_len) {
    size_t idx = 0;
    payload[idx++] = msg->error_code;
    *payload_len = (uint8_t)idx;
    return CLIK_OK;
}

int clik_set_payload_channel_current_limit_resp_unpack(clik_set_payload_channel_current_limit_resp_t *msg, const uint8_t *payload, uint8_t payload_len) {
    size_t idx = 0;
    (void)payload_len;  /* May be unused */
    msg->error_code = (clik_response_code_t)payload[idx++];
    return CLIK_OK;
}

int clik_set_payload_channel_current_limit_resp_to_frame(const clik_set_payload_channel_current_limit_resp_t *msg, uint8_t *frame,
                          size_t frame_size, uint8_t sync_code) {
    uint8_t payload[CLIK_MAX_PAYLOAD_SIZE];
    uint8_t payload_len;
    int result = clik_set_payload_channel_current_limit_resp_pack(msg, payload, &payload_len);
    if (result != CLIK_OK) return result;
    return clik_pack_frame(frame, frame_size, 0x0003, payload, payload_len, sync_code);
}

int clik_set_payload_channel_current_limit_resp_from_frame(clik_set_payload_channel_current_limit_resp_t *msg, const uint8_t *frame,
                            size_t frame_len, uint8_t *sync_code) {
    uint16_t message_id;
    const uint8_t *payload;
    uint8_t payload_len;
    int result = clik_unpack_frame(frame, frame_len, &message_id, sync_code, &payload, &payload_len);
    if (result != CLIK_OK) return result;
    if (message_id != 0x0003) return CLIK_ERR_INVALID_PARAM;
    return clik_set_payload_channel_current_limit_resp_unpack(msg, payload, payload_len);
}

