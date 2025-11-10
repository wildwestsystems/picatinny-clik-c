#include <stdio.h>
#include <string.h>
#include "clik_messages.h"

int main(void) {
    printf("=== CLIK C Library Test ===\n\n");
    
    /* Test 1: Pack and unpack a response with data */
    printf("Test 1: GetPayloadIdentifier Response\n");
    clik_get_payload_identifier_resp_t resp = {
        .error_code = CLIK_RESPONSE_CODE_SUCCESS,
        .uid = 0xBEEF,
    };
    strcpy(resp.identifier, "Test Payload");
    strcpy(resp.version, "1.0.0");
    
    uint8_t frame[CLIK_MAX_FRAME_SIZE];
    int frame_len = clik_get_payload_identifier_resp_to_frame(&resp, frame, sizeof(frame), 0x5A);
    
    if (frame_len > 0) {
        printf("  Frame packed: %d bytes\n", frame_len);
        printf("  Frame hex: ");
        for (int i = 0; i < frame_len && i < 20; i++) {
            printf("%02X ", frame[i]);
        }
        printf("...\n");
        
        /* Unpack it back */
        clik_get_payload_identifier_resp_t resp2;
        uint8_t sync_code;
        int result = clik_get_payload_identifier_resp_from_frame(&resp2, frame, frame_len, &sync_code);
        
        if (result == CLIK_OK) {
            printf("  Unpacked successfully!\n");
            printf("  - Sync: 0x%02X\n", sync_code);
            printf("  - Error Code: %d\n", resp2.error_code);
            printf("  - UID: 0x%04X\n", resp2.uid);
            printf("  - Identifier: %s\n", resp2.identifier);
            printf("  - Version: %s\n", resp2.version);
        } else {
            printf("  ERROR: Failed to unpack (code %d)\n", result);
        }
    } else {
        printf("  ERROR: Failed to pack (code %d)\n", frame_len);
    }
    
    /* Test 2: Streaming framer */
    printf("\nTest 2: Streaming Framer\n");
    clik_framer_t framer;
    clik_framer_init(&framer);
    
    /* Feed the frame byte by byte */
    for (int i = 0; i < frame_len; i++) {
        clik_framer_push_byte(&framer, frame[i]);
    }
    
    /* Try to extract a frame */
    uint16_t msg_id;
    uint8_t sync;
    uint8_t payload[CLIK_MAX_PAYLOAD_SIZE];
    uint8_t payload_len;
    
    int got_frame = clik_framer_next_frame(&framer, &msg_id, &sync, payload, &payload_len);
    if (got_frame) {
        printf("  Got frame from framer!\n");
        printf("  - Message ID: 0x%04X\n", msg_id);
        printf("  - Sync: 0x%02X\n", sync);
        printf("  - Payload length: %d\n", payload_len);
        
        /* Unpack the payload */
        clik_get_payload_identifier_resp_t resp3;
        int result = clik_get_payload_identifier_resp_unpack(&resp3, payload, payload_len);
        if (result == CLIK_OK) {
            printf("  - Identifier: %s\n", resp3.identifier);
        }
    } else {
        printf("  ERROR: No frame extracted\n");
    }
    
    /* Test 3: Message with array */
    printf("\nTest 3: Message with IP Address Array\n");
    clik_get_payload_network_config_resp_t net_resp = {
        .error_code = CLIK_RESPONSE_CODE_SUCCESS,
        .interface_index = 0,
        .interface_enabled = 1,
        .ip_address = {192, 168, 1, 100},
        .subnet_bits = 24,
    };
    
    uint8_t net_frame[CLIK_MAX_FRAME_SIZE];
    int net_frame_len = clik_get_payload_network_config_resp_to_frame(&net_resp, net_frame, sizeof(net_frame), 0x00);
    
    if (net_frame_len > 0) {
        printf("  Frame packed: %d bytes\n", net_frame_len);
        
        clik_get_payload_network_config_resp_t net_resp2;
        uint8_t sync2;
        int result = clik_get_payload_network_config_resp_from_frame(&net_resp2, net_frame, net_frame_len, &sync2);
        
        if (result == CLIK_OK) {
            printf("  IP Address: %d.%d.%d.%d/%d\n",
                   net_resp2.ip_address[0], net_resp2.ip_address[1],
                   net_resp2.ip_address[2], net_resp2.ip_address[3],
                   net_resp2.subnet_bits);
        }
    }
    
    printf("\n=== All tests completed ===\n");
    return 0;
}
