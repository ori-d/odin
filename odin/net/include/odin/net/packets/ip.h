#ifndef ODIN_NET_PACKETS_IP_H
#define ODIN_NET_PACKETS_IP_H 1

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include <stdint.h>
#include <odin/core/object.h>
#include "../exports.h"

typedef struct odin_net_packet_ip_s {
    odin_object_t base;
    struct {
        uint8_t version;
        uint8_t header_length;
        uint8_t type;
        uint16_t length;
        uint8_t flags;
        uint16_t fragment_offset;
        uint8_t time_to_live;
        uint8_t protocol;
        uint16_t checksum;
        uint32_t source_ip;
        uint32_t destination_ip;
    } data;
} odin_net_packet_ip_t;

odin_net_packet_ip_t
odin_net_api
odin_net_packet_ip_from_buffer( void const *p_data, size_t i_size );

odin_net_packet_ip_t
odin_net_api
odin_net_packet_ip_from_stream ( FILE *

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ODIN_NET_PACKETS_IP_H */
