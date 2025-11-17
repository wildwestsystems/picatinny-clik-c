#ifndef CLIK_MESSAGES_H
#define CLIK_MESSAGES_H

#include <stdint.h>
#include "clik_types.h"
#include "clik_runtime.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Message ID: 0x0000 - GetPayloadStatus Request */
typedef struct {
    uint8_t _dummy;  /* Empty struct not allowed in C */
} clik_get_payload_status_req_t;

int clik_get_payload_status_req_pack(
    const clik_get_payload_status_req_t *msg, uint8_t *payload, uint8_t *payload_len);

int clik_get_payload_status_req_unpack(
    clik_get_payload_status_req_t *msg, const uint8_t *payload, uint8_t payload_len);

int clik_get_payload_status_req_to_frame(
    const clik_get_payload_status_req_t *msg, uint8_t *frame, size_t frame_size,
    uint8_t sync_code);

int clik_get_payload_status_req_from_frame(
    clik_get_payload_status_req_t *msg, const uint8_t *frame, size_t frame_len,
    uint8_t *sync_code);

/* Message ID: 0x0000 - GetPayloadStatus Response */
typedef struct {
    clik_response_code_t error_code;
    clik_payload_status_t status;
    uint8_t available_net_interfaces;
    uint8_t active_net_interfaces;
    uint8_t number_of_functions;
    uint8_t function_states_len;
    clik_function_state_t function_states[CLIK_MAX_PAYLOAD_SIZE];  /* Dynamic array */
} clik_get_payload_status_resp_t;

int clik_get_payload_status_resp_pack(
    const clik_get_payload_status_resp_t *msg, uint8_t *payload, uint8_t *payload_len);

int clik_get_payload_status_resp_unpack(
    clik_get_payload_status_resp_t *msg, const uint8_t *payload, uint8_t payload_len);

int clik_get_payload_status_resp_to_frame(
    const clik_get_payload_status_resp_t *msg, uint8_t *frame, size_t frame_size,
    uint8_t sync_code);

int clik_get_payload_status_resp_from_frame(
    clik_get_payload_status_resp_t *msg, const uint8_t *frame, size_t frame_len,
    uint8_t *sync_code);

/* Message ID: 0x0001 - GetPayloadIdentifier Request */
typedef struct {
    uint8_t _dummy;  /* Empty struct not allowed in C */
} clik_get_payload_identifier_req_t;

int clik_get_payload_identifier_req_pack(
    const clik_get_payload_identifier_req_t *msg, uint8_t *payload, uint8_t *payload_len);

int clik_get_payload_identifier_req_unpack(
    clik_get_payload_identifier_req_t *msg, const uint8_t *payload, uint8_t payload_len);

int clik_get_payload_identifier_req_to_frame(
    const clik_get_payload_identifier_req_t *msg, uint8_t *frame, size_t frame_size,
    uint8_t sync_code);

int clik_get_payload_identifier_req_from_frame(
    clik_get_payload_identifier_req_t *msg, const uint8_t *frame, size_t frame_len,
    uint8_t *sync_code);

/* Message ID: 0x0001 - GetPayloadIdentifier Response */
typedef struct {
    clik_response_code_t error_code;
    uint16_t uid;
    char identifier[33];  /* +1 for null terminator */
    char version[17];  /* +1 for null terminator */
} clik_get_payload_identifier_resp_t;

int clik_get_payload_identifier_resp_pack(
    const clik_get_payload_identifier_resp_t *msg, uint8_t *payload, uint8_t *payload_len);

int clik_get_payload_identifier_resp_unpack(
    clik_get_payload_identifier_resp_t *msg, const uint8_t *payload, uint8_t payload_len);

int clik_get_payload_identifier_resp_to_frame(
    const clik_get_payload_identifier_resp_t *msg, uint8_t *frame, size_t frame_size,
    uint8_t sync_code);

int clik_get_payload_identifier_resp_from_frame(
    clik_get_payload_identifier_resp_t *msg, const uint8_t *frame, size_t frame_len,
    uint8_t *sync_code);

/* Message ID: 0x0002 - GetPayloadSystemConfig Request */
typedef struct {
    uint8_t _dummy;  /* Empty struct not allowed in C */
} clik_get_payload_system_config_req_t;

int clik_get_payload_system_config_req_pack(
    const clik_get_payload_system_config_req_t *msg, uint8_t *payload, uint8_t *payload_len);

int clik_get_payload_system_config_req_unpack(
    clik_get_payload_system_config_req_t *msg, const uint8_t *payload, uint8_t payload_len);

int clik_get_payload_system_config_req_to_frame(
    const clik_get_payload_system_config_req_t *msg, uint8_t *frame, size_t frame_size,
    uint8_t sync_code);

int clik_get_payload_system_config_req_from_frame(
    clik_get_payload_system_config_req_t *msg, const uint8_t *frame, size_t frame_len,
    uint8_t *sync_code);

/* Message ID: 0x0002 - GetPayloadSystemConfig Response */
typedef struct {
    clik_response_code_t error_code;
    uint8_t mpc;
    uint16_t mpw;
    uint8_t safety_discretes_monitored;
} clik_get_payload_system_config_resp_t;

int clik_get_payload_system_config_resp_pack(
    const clik_get_payload_system_config_resp_t *msg, uint8_t *payload, uint8_t *payload_len);

int clik_get_payload_system_config_resp_unpack(
    clik_get_payload_system_config_resp_t *msg, const uint8_t *payload, uint8_t payload_len);

int clik_get_payload_system_config_resp_to_frame(
    const clik_get_payload_system_config_resp_t *msg, uint8_t *frame, size_t frame_size,
    uint8_t sync_code);

int clik_get_payload_system_config_resp_from_frame(
    clik_get_payload_system_config_resp_t *msg, const uint8_t *frame, size_t frame_len,
    uint8_t *sync_code);

/* Message ID: 0x0003 - GetPayloadNetworkConfig Request */
typedef struct {
    uint8_t interface_index;
} clik_get_payload_network_config_req_t;

int clik_get_payload_network_config_req_pack(
    const clik_get_payload_network_config_req_t *msg, uint8_t *payload, uint8_t *payload_len);

int clik_get_payload_network_config_req_unpack(
    clik_get_payload_network_config_req_t *msg, const uint8_t *payload, uint8_t payload_len);

int clik_get_payload_network_config_req_to_frame(
    const clik_get_payload_network_config_req_t *msg, uint8_t *frame, size_t frame_size,
    uint8_t sync_code);

int clik_get_payload_network_config_req_from_frame(
    clik_get_payload_network_config_req_t *msg, const uint8_t *frame, size_t frame_len,
    uint8_t *sync_code);

/* Message ID: 0x0003 - GetPayloadNetworkConfig Response */
typedef struct {
    clik_response_code_t error_code;
    uint8_t interface_index;
    uint8_t interface_enabled;
    uint8_t ip_address[4];
    uint8_t subnet_bits;
} clik_get_payload_network_config_resp_t;

int clik_get_payload_network_config_resp_pack(
    const clik_get_payload_network_config_resp_t *msg, uint8_t *payload, uint8_t *payload_len);

int clik_get_payload_network_config_resp_unpack(
    clik_get_payload_network_config_resp_t *msg, const uint8_t *payload, uint8_t payload_len);

int clik_get_payload_network_config_resp_to_frame(
    const clik_get_payload_network_config_resp_t *msg, uint8_t *frame, size_t frame_size,
    uint8_t sync_code);

int clik_get_payload_network_config_resp_from_frame(
    clik_get_payload_network_config_resp_t *msg, const uint8_t *frame, size_t frame_len,
    uint8_t *sync_code);

/* Message ID: 0x0004 - SetFunctionState Request */
typedef struct {
    uint8_t function_index;
    uint8_t activate_function;
} clik_set_function_state_req_t;

int clik_set_function_state_req_pack(
    const clik_set_function_state_req_t *msg, uint8_t *payload, uint8_t *payload_len);

int clik_set_function_state_req_unpack(
    clik_set_function_state_req_t *msg, const uint8_t *payload, uint8_t payload_len);

int clik_set_function_state_req_to_frame(
    const clik_set_function_state_req_t *msg, uint8_t *frame, size_t frame_size,
    uint8_t sync_code);

int clik_set_function_state_req_from_frame(
    clik_set_function_state_req_t *msg, const uint8_t *frame, size_t frame_len,
    uint8_t *sync_code);

/* Message ID: 0x0004 - SetFunctionState Response */
typedef struct {
    clik_response_code_t error_code;
} clik_set_function_state_resp_t;

int clik_set_function_state_resp_pack(
    const clik_set_function_state_resp_t *msg, uint8_t *payload, uint8_t *payload_len);

int clik_set_function_state_resp_unpack(
    clik_set_function_state_resp_t *msg, const uint8_t *payload, uint8_t payload_len);

int clik_set_function_state_resp_to_frame(
    const clik_set_function_state_resp_t *msg, uint8_t *frame, size_t frame_size,
    uint8_t sync_code);

int clik_set_function_state_resp_from_frame(
    clik_set_function_state_resp_t *msg, const uint8_t *frame, size_t frame_len,
    uint8_t *sync_code);

/* Message ID: 0x0005 - SetPayloadNetworkConfig Request */
typedef struct {
    uint8_t interface_index;
    uint8_t interface_enabled;
    uint8_t ip_address[4];
    uint8_t subnet_bits;
} clik_set_payload_network_config_req_t;

int clik_set_payload_network_config_req_pack(
    const clik_set_payload_network_config_req_t *msg, uint8_t *payload, uint8_t *payload_len);

int clik_set_payload_network_config_req_unpack(
    clik_set_payload_network_config_req_t *msg, const uint8_t *payload, uint8_t payload_len);

int clik_set_payload_network_config_req_to_frame(
    const clik_set_payload_network_config_req_t *msg, uint8_t *frame, size_t frame_size,
    uint8_t sync_code);

int clik_set_payload_network_config_req_from_frame(
    clik_set_payload_network_config_req_t *msg, const uint8_t *frame, size_t frame_len,
    uint8_t *sync_code);

/* Message ID: 0x0005 - SetPayloadNetworkConfig Response */
typedef struct {
    clik_response_code_t error_code;
} clik_set_payload_network_config_resp_t;

int clik_set_payload_network_config_resp_pack(
    const clik_set_payload_network_config_resp_t *msg, uint8_t *payload, uint8_t *payload_len);

int clik_set_payload_network_config_resp_unpack(
    clik_set_payload_network_config_resp_t *msg, const uint8_t *payload, uint8_t payload_len);

int clik_set_payload_network_config_resp_to_frame(
    const clik_set_payload_network_config_resp_t *msg, uint8_t *frame, size_t frame_size,
    uint8_t sync_code);

int clik_set_payload_network_config_resp_from_frame(
    clik_set_payload_network_config_resp_t *msg, const uint8_t *frame, size_t frame_len,
    uint8_t *sync_code);

/* Message ID: 0x0006 - SetPayloadNetworkState Request */
typedef struct {
    uint8_t interface_index;
    uint8_t network_state;
} clik_set_payload_network_state_req_t;

int clik_set_payload_network_state_req_pack(
    const clik_set_payload_network_state_req_t *msg, uint8_t *payload, uint8_t *payload_len);

int clik_set_payload_network_state_req_unpack(
    clik_set_payload_network_state_req_t *msg, const uint8_t *payload, uint8_t payload_len);

int clik_set_payload_network_state_req_to_frame(
    const clik_set_payload_network_state_req_t *msg, uint8_t *frame, size_t frame_size,
    uint8_t sync_code);

int clik_set_payload_network_state_req_from_frame(
    clik_set_payload_network_state_req_t *msg, const uint8_t *frame, size_t frame_len,
    uint8_t *sync_code);

/* Message ID: 0x0006 - SetPayloadNetworkState Response */
typedef struct {
    clik_response_code_t error_code;
} clik_set_payload_network_state_resp_t;

int clik_set_payload_network_state_resp_pack(
    const clik_set_payload_network_state_resp_t *msg, uint8_t *payload, uint8_t *payload_len);

int clik_set_payload_network_state_resp_unpack(
    clik_set_payload_network_state_resp_t *msg, const uint8_t *payload, uint8_t payload_len);

int clik_set_payload_network_state_resp_to_frame(
    const clik_set_payload_network_state_resp_t *msg, uint8_t *frame, size_t frame_size,
    uint8_t sync_code);

int clik_set_payload_network_state_resp_from_frame(
    clik_set_payload_network_state_resp_t *msg, const uint8_t *frame, size_t frame_len,
    uint8_t *sync_code);

/* Message ID: 0x0000 - GetPlatformStatus Request */
typedef struct {
    uint8_t _dummy;  /* Empty struct not allowed in C */
} clik_get_platform_status_req_t;

int clik_get_platform_status_req_pack(
    const clik_get_platform_status_req_t *msg, uint8_t *payload, uint8_t *payload_len);

int clik_get_platform_status_req_unpack(
    clik_get_platform_status_req_t *msg, const uint8_t *payload, uint8_t payload_len);

int clik_get_platform_status_req_to_frame(
    const clik_get_platform_status_req_t *msg, uint8_t *frame, size_t frame_size,
    uint8_t sync_code);

int clik_get_platform_status_req_from_frame(
    clik_get_platform_status_req_t *msg, const uint8_t *frame, size_t frame_len,
    uint8_t *sync_code);

/* Message ID: 0x0000 - GetPlatformStatus Response */
typedef struct {
    clik_response_code_t error_code;
    uint8_t payloads_supported;
    uint8_t payloads_connected;
    uint8_t status;
    uint16_t platform_voltage;
    uint16_t platform_current_draw;
    uint16_t clik_voltage;
    uint16_t clik_current_draw;
} clik_get_platform_status_resp_t;

int clik_get_platform_status_resp_pack(
    const clik_get_platform_status_resp_t *msg, uint8_t *payload, uint8_t *payload_len);

int clik_get_platform_status_resp_unpack(
    clik_get_platform_status_resp_t *msg, const uint8_t *payload, uint8_t payload_len);

int clik_get_platform_status_resp_to_frame(
    const clik_get_platform_status_resp_t *msg, uint8_t *frame, size_t frame_size,
    uint8_t sync_code);

int clik_get_platform_status_resp_from_frame(
    clik_get_platform_status_resp_t *msg, const uint8_t *frame, size_t frame_len,
    uint8_t *sync_code);

/* Message ID: 0x0001 - GetPlatformIdentifier Request */
typedef struct {
    uint8_t _dummy;  /* Empty struct not allowed in C */
} clik_get_platform_identifier_req_t;

int clik_get_platform_identifier_req_pack(
    const clik_get_platform_identifier_req_t *msg, uint8_t *payload, uint8_t *payload_len);

int clik_get_platform_identifier_req_unpack(
    clik_get_platform_identifier_req_t *msg, const uint8_t *payload, uint8_t payload_len);

int clik_get_platform_identifier_req_to_frame(
    const clik_get_platform_identifier_req_t *msg, uint8_t *frame, size_t frame_size,
    uint8_t sync_code);

int clik_get_platform_identifier_req_from_frame(
    clik_get_platform_identifier_req_t *msg, const uint8_t *frame, size_t frame_len,
    uint8_t *sync_code);

/* Message ID: 0x0001 - GetPlatformIdentifier Response */
typedef struct {
    clik_response_code_t error_code;
    uint16_t uid;
    char identifier[33];  /* +1 for null terminator */
    char version[17];  /* +1 for null terminator */
} clik_get_platform_identifier_resp_t;

int clik_get_platform_identifier_resp_pack(
    const clik_get_platform_identifier_resp_t *msg, uint8_t *payload, uint8_t *payload_len);

int clik_get_platform_identifier_resp_unpack(
    clik_get_platform_identifier_resp_t *msg, const uint8_t *payload, uint8_t payload_len);

int clik_get_platform_identifier_resp_to_frame(
    const clik_get_platform_identifier_resp_t *msg, uint8_t *frame, size_t frame_size,
    uint8_t sync_code);

int clik_get_platform_identifier_resp_from_frame(
    clik_get_platform_identifier_resp_t *msg, const uint8_t *frame, size_t frame_len,
    uint8_t *sync_code);

/* Message ID: 0x0002 - GetPlatformSystemConfig Request */
typedef struct {
    uint8_t _dummy;  /* Empty struct not allowed in C */
} clik_get_platform_system_config_req_t;

int clik_get_platform_system_config_req_pack(
    const clik_get_platform_system_config_req_t *msg, uint8_t *payload, uint8_t *payload_len);

int clik_get_platform_system_config_req_unpack(
    clik_get_platform_system_config_req_t *msg, const uint8_t *payload, uint8_t payload_len);

int clik_get_platform_system_config_req_to_frame(
    const clik_get_platform_system_config_req_t *msg, uint8_t *frame, size_t frame_size,
    uint8_t sync_code);

int clik_get_platform_system_config_req_from_frame(
    clik_get_platform_system_config_req_t *msg, const uint8_t *frame, size_t frame_len,
    uint8_t *sync_code);

/* Message ID: 0x0002 - GetPlatformSystemConfig Response */
typedef struct {
    clik_response_code_t error_code;
    uint8_t mac;
    uint16_t apw;
} clik_get_platform_system_config_resp_t;

int clik_get_platform_system_config_resp_pack(
    const clik_get_platform_system_config_resp_t *msg, uint8_t *payload, uint8_t *payload_len);

int clik_get_platform_system_config_resp_unpack(
    clik_get_platform_system_config_resp_t *msg, const uint8_t *payload, uint8_t payload_len);

int clik_get_platform_system_config_resp_to_frame(
    const clik_get_platform_system_config_resp_t *msg, uint8_t *frame, size_t frame_size,
    uint8_t sync_code);

int clik_get_platform_system_config_resp_from_frame(
    clik_get_platform_system_config_resp_t *msg, const uint8_t *frame, size_t frame_len,
    uint8_t *sync_code);

/* Message ID: 0x0003 - GetPlatformNetworkConfig Request */
typedef struct {
    uint8_t interface_index;
} clik_get_platform_network_config_req_t;

int clik_get_platform_network_config_req_pack(
    const clik_get_platform_network_config_req_t *msg, uint8_t *payload, uint8_t *payload_len);

int clik_get_platform_network_config_req_unpack(
    clik_get_platform_network_config_req_t *msg, const uint8_t *payload, uint8_t payload_len);

int clik_get_platform_network_config_req_to_frame(
    const clik_get_platform_network_config_req_t *msg, uint8_t *frame, size_t frame_size,
    uint8_t sync_code);

int clik_get_platform_network_config_req_from_frame(
    clik_get_platform_network_config_req_t *msg, const uint8_t *frame, size_t frame_len,
    uint8_t *sync_code);

/* Message ID: 0x0003 - GetPlatformNetworkConfig Response */
typedef struct {
    clik_response_code_t error_code;
    uint8_t interface_index;
    uint8_t ip_address[4];
    uint8_t subnet_bits;
    uint16_t udp_port;
} clik_get_platform_network_config_resp_t;

int clik_get_platform_network_config_resp_pack(
    const clik_get_platform_network_config_resp_t *msg, uint8_t *payload, uint8_t *payload_len);

int clik_get_platform_network_config_resp_unpack(
    clik_get_platform_network_config_resp_t *msg, const uint8_t *payload, uint8_t payload_len);

int clik_get_platform_network_config_resp_to_frame(
    const clik_get_platform_network_config_resp_t *msg, uint8_t *frame, size_t frame_size,
    uint8_t sync_code);

int clik_get_platform_network_config_resp_from_frame(
    clik_get_platform_network_config_resp_t *msg, const uint8_t *frame, size_t frame_len,
    uint8_t *sync_code);

/* Message ID: 0x0004 - SetPlatformPower Request */
typedef struct {
    uint8_t power_state;
} clik_set_platform_power_req_t;

int clik_set_platform_power_req_pack(
    const clik_set_platform_power_req_t *msg, uint8_t *payload, uint8_t *payload_len);

int clik_set_platform_power_req_unpack(
    clik_set_platform_power_req_t *msg, const uint8_t *payload, uint8_t payload_len);

int clik_set_platform_power_req_to_frame(
    const clik_set_platform_power_req_t *msg, uint8_t *frame, size_t frame_size,
    uint8_t sync_code);

int clik_set_platform_power_req_from_frame(
    clik_set_platform_power_req_t *msg, const uint8_t *frame, size_t frame_len,
    uint8_t *sync_code);

/* Message ID: 0x0004 - SetPlatformPower Response */
typedef struct {
    clik_response_code_t error_code;
} clik_set_platform_power_resp_t;

int clik_set_platform_power_resp_pack(
    const clik_set_platform_power_resp_t *msg, uint8_t *payload, uint8_t *payload_len);

int clik_set_platform_power_resp_unpack(
    clik_set_platform_power_resp_t *msg, const uint8_t *payload, uint8_t payload_len);

int clik_set_platform_power_resp_to_frame(
    const clik_set_platform_power_resp_t *msg, uint8_t *frame, size_t frame_size,
    uint8_t sync_code);

int clik_set_platform_power_resp_from_frame(
    clik_set_platform_power_resp_t *msg, const uint8_t *frame, size_t frame_len,
    uint8_t *sync_code);

/* Message ID: 0x0000 - GetPayloadChannelStatus Request */
typedef struct {
    uint8_t _dummy;  /* Empty struct not allowed in C */
} clik_get_payload_channel_status_req_t;

int clik_get_payload_channel_status_req_pack(
    const clik_get_payload_channel_status_req_t *msg, uint8_t *payload, uint8_t *payload_len);

int clik_get_payload_channel_status_req_unpack(
    clik_get_payload_channel_status_req_t *msg, const uint8_t *payload, uint8_t payload_len);

int clik_get_payload_channel_status_req_to_frame(
    const clik_get_payload_channel_status_req_t *msg, uint8_t *frame, size_t frame_size,
    uint8_t sync_code);

int clik_get_payload_channel_status_req_from_frame(
    clik_get_payload_channel_status_req_t *msg, const uint8_t *frame, size_t frame_len,
    uint8_t *sync_code);

/* Message ID: 0x0000 - GetPayloadChannelStatus Response */
typedef struct {
    clik_response_code_t error_code;
    uint8_t payload_connected;
    uint16_t payload_voltage;
    uint16_t payload_current_draw;
    clik_channel_status_t payload_channel_status;
} clik_get_payload_channel_status_resp_t;

int clik_get_payload_channel_status_resp_pack(
    const clik_get_payload_channel_status_resp_t *msg, uint8_t *payload, uint8_t *payload_len);

int clik_get_payload_channel_status_resp_unpack(
    clik_get_payload_channel_status_resp_t *msg, const uint8_t *payload, uint8_t payload_len);

int clik_get_payload_channel_status_resp_to_frame(
    const clik_get_payload_channel_status_resp_t *msg, uint8_t *frame, size_t frame_size,
    uint8_t sync_code);

int clik_get_payload_channel_status_resp_from_frame(
    clik_get_payload_channel_status_resp_t *msg, const uint8_t *frame, size_t frame_len,
    uint8_t *sync_code);

/* Message ID: 0x0001 - GetPayloadChannelPowerConfig Request */
typedef struct {
    uint8_t _dummy;  /* Empty struct not allowed in C */
} clik_get_payload_channel_power_config_req_t;

int clik_get_payload_channel_power_config_req_pack(
    const clik_get_payload_channel_power_config_req_t *msg, uint8_t *payload, uint8_t *payload_len);

int clik_get_payload_channel_power_config_req_unpack(
    clik_get_payload_channel_power_config_req_t *msg, const uint8_t *payload, uint8_t payload_len);

int clik_get_payload_channel_power_config_req_to_frame(
    const clik_get_payload_channel_power_config_req_t *msg, uint8_t *frame, size_t frame_size,
    uint8_t sync_code);

int clik_get_payload_channel_power_config_req_from_frame(
    clik_get_payload_channel_power_config_req_t *msg, const uint8_t *frame, size_t frame_len,
    uint8_t *sync_code);

/* Message ID: 0x0001 - GetPayloadChannelPowerConfig Response */
typedef struct {
    clik_response_code_t error_code;
    uint16_t current_limit;
    clik_power_options_t power_options;
} clik_get_payload_channel_power_config_resp_t;

int clik_get_payload_channel_power_config_resp_pack(
    const clik_get_payload_channel_power_config_resp_t *msg, uint8_t *payload, uint8_t *payload_len);

int clik_get_payload_channel_power_config_resp_unpack(
    clik_get_payload_channel_power_config_resp_t *msg, const uint8_t *payload, uint8_t payload_len);

int clik_get_payload_channel_power_config_resp_to_frame(
    const clik_get_payload_channel_power_config_resp_t *msg, uint8_t *frame, size_t frame_size,
    uint8_t sync_code);

int clik_get_payload_channel_power_config_resp_from_frame(
    clik_get_payload_channel_power_config_resp_t *msg, const uint8_t *frame, size_t frame_len,
    uint8_t *sync_code);

/* Message ID: 0x0002 - SetPayloadChannelPower Request */
typedef struct {
    uint8_t power_state;
} clik_set_payload_channel_power_req_t;

int clik_set_payload_channel_power_req_pack(
    const clik_set_payload_channel_power_req_t *msg, uint8_t *payload, uint8_t *payload_len);

int clik_set_payload_channel_power_req_unpack(
    clik_set_payload_channel_power_req_t *msg, const uint8_t *payload, uint8_t payload_len);

int clik_set_payload_channel_power_req_to_frame(
    const clik_set_payload_channel_power_req_t *msg, uint8_t *frame, size_t frame_size,
    uint8_t sync_code);

int clik_set_payload_channel_power_req_from_frame(
    clik_set_payload_channel_power_req_t *msg, const uint8_t *frame, size_t frame_len,
    uint8_t *sync_code);

/* Message ID: 0x0002 - SetPayloadChannelPower Response */
typedef struct {
    clik_response_code_t error_code;
} clik_set_payload_channel_power_resp_t;

int clik_set_payload_channel_power_resp_pack(
    const clik_set_payload_channel_power_resp_t *msg, uint8_t *payload, uint8_t *payload_len);

int clik_set_payload_channel_power_resp_unpack(
    clik_set_payload_channel_power_resp_t *msg, const uint8_t *payload, uint8_t payload_len);

int clik_set_payload_channel_power_resp_to_frame(
    const clik_set_payload_channel_power_resp_t *msg, uint8_t *frame, size_t frame_size,
    uint8_t sync_code);

int clik_set_payload_channel_power_resp_from_frame(
    clik_set_payload_channel_power_resp_t *msg, const uint8_t *frame, size_t frame_len,
    uint8_t *sync_code);

/* Message ID: 0x0003 - SetPayloadChannelCurrentLimit Request */
typedef struct {
    uint8_t current_limit;
} clik_set_payload_channel_current_limit_req_t;

int clik_set_payload_channel_current_limit_req_pack(
    const clik_set_payload_channel_current_limit_req_t *msg, uint8_t *payload, uint8_t *payload_len);

int clik_set_payload_channel_current_limit_req_unpack(
    clik_set_payload_channel_current_limit_req_t *msg, const uint8_t *payload, uint8_t payload_len);

int clik_set_payload_channel_current_limit_req_to_frame(
    const clik_set_payload_channel_current_limit_req_t *msg, uint8_t *frame, size_t frame_size,
    uint8_t sync_code);

int clik_set_payload_channel_current_limit_req_from_frame(
    clik_set_payload_channel_current_limit_req_t *msg, const uint8_t *frame, size_t frame_len,
    uint8_t *sync_code);

/* Message ID: 0x0003 - SetPayloadChannelCurrentLimit Response */
typedef struct {
    clik_response_code_t error_code;
} clik_set_payload_channel_current_limit_resp_t;

int clik_set_payload_channel_current_limit_resp_pack(
    const clik_set_payload_channel_current_limit_resp_t *msg, uint8_t *payload, uint8_t *payload_len);

int clik_set_payload_channel_current_limit_resp_unpack(
    clik_set_payload_channel_current_limit_resp_t *msg, const uint8_t *payload, uint8_t payload_len);

int clik_set_payload_channel_current_limit_resp_to_frame(
    const clik_set_payload_channel_current_limit_resp_t *msg, uint8_t *frame, size_t frame_size,
    uint8_t sync_code);

int clik_set_payload_channel_current_limit_resp_from_frame(
    clik_set_payload_channel_current_limit_resp_t *msg, const uint8_t *frame, size_t frame_len,
    uint8_t *sync_code);

#ifdef __cplusplus
}
#endif

#endif /* CLIK_MESSAGES_H */
