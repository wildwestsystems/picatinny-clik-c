# CLIK Protocol - C Implementation

This is a generated C implementation of the CLIK protocol. The code is compatible
with both C and C++ compilers.

## Files

- `clik_types.h` - Type definitions (enums, bitsets)
- `clik_runtime.h/c` - Frame packing/unpacking and streaming framer
- `clik_messages.h/c` - Message structures and serialization

## Usage

### Basic Example

```c
#include "clik_messages.h"

/* Create and send a request */
clik_get_payload_status_req_t req = {0};
uint8_t frame[CLIK_MAX_FRAME_SIZE];
int frame_len = clik_get_payload_status_req_to_frame(&req, frame, sizeof(frame), 0x00);

/* Parse a response */
clik_get_payload_status_resp_t resp;
uint8_t sync_code;
int result = clik_get_payload_status_resp_from_frame(&resp, frame, frame_len, &sync_code);
if (result == CLIK_OK) {
    /* Use response data */
}
```

### Streaming Parser

```c
clik_framer_t framer;
clik_framer_init(&framer);

/* Feed bytes incrementally */
for (size_t i = 0; i < data_len; i++) {
    clik_framer_push_byte(&framer, data[i]);
    
    /* Try to extract frames */
    uint16_t msg_id;
    uint8_t sync;
    uint8_t payload[CLIK_MAX_PAYLOAD_SIZE];
    uint8_t payload_len;
    
    if (clik_framer_next_frame(&framer, &msg_id, &sync, payload, &payload_len) > 0) {
        /* Got a complete frame */
    }
}
```

## Building

The generated code requires a C99 compatible compiler:

```bash
gcc -std=c99 -Wall -Wextra -c clik_runtime.c
gcc -std=c99 -Wall -Wextra -c clik_messages.c
```

Or for C++:

```bash
g++ -std=c++11 -Wall -Wextra -c clik_runtime.c
g++ -std=c++11 -Wall -Wextra -c clik_messages.c
```
