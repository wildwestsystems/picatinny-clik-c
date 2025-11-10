#include <stdio.h>
#include "clik_messages.h"

int main(void) {
    /* Create a request */
    clik_get_payload_identifier_req_t req = {0};
    
    /* Pack into frame */
    uint8_t frame[CLIK_MAX_FRAME_SIZE];
    int frame_len = clik_get_payload_identifier_req_to_frame(&req, frame, sizeof(frame), 0x5A);
    
    if (frame_len > 0) {
        printf("Frame packed successfully, size: %d\n", frame_len);
        
        /* Unpack the frame */
        clik_get_payload_identifier_req_t req2;
        uint8_t sync_code;
        int result = clik_get_payload_identifier_req_from_frame(&req2, frame, frame_len, &sync_code);
        
        if (result == CLIK_OK) {
            printf("Frame unpacked successfully, sync: 0x%02X\n", sync_code);
        }
    }
    
    return 0;
}
