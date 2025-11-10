#ifndef CLIK_TYPES_H
#define CLIK_TYPES_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Communication channels */
typedef enum {
    CLIK_CHANNEL_SERIAL = 0,
    CLIK_CHANNEL_UDP = 1,
} clik_channel_t;

/* Communication agents */
typedef enum {
    CLIK_AGENT_PLATFORM = 0,
    CLIK_AGENT_PAYLOAD = 1,
} clik_agent_t;

/* ResponseCode enum */
typedef enum {
    CLIK_RESPONSE_CODE_SUCCESS = 0,
    CLIK_RESPONSE_CODE_BAD_CHECKSUM = 1,
    CLIK_RESPONSE_CODE_INVALID_COMMAND = 2,
    CLIK_RESPONSE_CODE_INVALID_DATA_LENGTH = 3,
    CLIK_RESPONSE_CODE_INVALID_COMMAND_PARAMETER = 4,
} clik_response_code_t;

/* PayloadStatus bitset */
typedef uint8_t clik_payload_status_t;
#define CLIK_PAYLOAD_STATUS_HEALTHY (1U << 0)
#define CLIK_PAYLOAD_STATUS_ARMED (1U << 1)
#define CLIK_PAYLOAD_STATUS_FIRING (1U << 2)
#define CLIK_PAYLOAD_STATUS_FUNCTIONS_AVAILABLE (1U << 3)
#define CLIK_PAYLOAD_STATUS_FUNCTIONS_ACTIVATED (1U << 4)
#define CLIK_PAYLOAD_STATUS_FUNCTIONS_ARMED (1U << 5)
#define CLIK_PAYLOAD_STATUS_RESERVED_1 (1U << 6)
#define CLIK_PAYLOAD_STATUS_RESERVED_2 (1U << 7)

/* FunctionState enum */
typedef enum {
    CLIK_FUNCTION_STATE_UNAVAILABLE = 0,
    CLIK_FUNCTION_STATE_NOT_ACTIVATED = 1,
    CLIK_FUNCTION_STATE_ACTIVATED = 2,
    CLIK_FUNCTION_STATE_ARMED = 3,
    CLIK_FUNCTION_STATE_FIRING = 4,
} clik_function_state_t;

/* ChannelStatus bitset */
typedef uint8_t clik_channel_status_t;
#define CLIK_CHANNEL_STATUS_OVERCURRENT (1U << 0)
#define CLIK_CHANNEL_STATUS_POWER_STATE (1U << 1)
#define CLIK_CHANNEL_STATUS_ARMED (1U << 2)
#define CLIK_CHANNEL_STATUS_FIRING (1U << 3)
#define CLIK_CHANNEL_STATUS_RESERVED_1 (1U << 4)
#define CLIK_CHANNEL_STATUS_RESERVED_2 (1U << 5)
#define CLIK_CHANNEL_STATUS_RESERVED_3 (1U << 6)
#define CLIK_CHANNEL_STATUS_RESERVED_4 (1U << 7)

/* PowerOptions bitset */
typedef uint8_t clik_power_options_t;
#define CLIK_POWER_OPTIONS_OVERCURRENT_CIRCUIT_RESET (1U << 0)
#define CLIK_POWER_OPTIONS_CONFIGURABLE_CURRENT_LIMIT (1U << 1)
#define CLIK_POWER_OPTIONS_POWER_ON_OFF_CONTROL (1U << 2)
#define CLIK_POWER_OPTIONS_RESERVED_1 (1U << 3)
#define CLIK_POWER_OPTIONS_RESERVED_2 (1U << 4)
#define CLIK_POWER_OPTIONS_RESERVED_3 (1U << 5)
#define CLIK_POWER_OPTIONS_RESERVED_4 (1U << 6)
#define CLIK_POWER_OPTIONS_RESERVED_5 (1U << 7)

#ifdef __cplusplus
}
#endif

#endif /* CLIK_TYPES_H */
