#ifndef ODIN_NET_TYPES_H
#define ODIN_NET_TYPES_H 1

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include <stdint.h>

typedef enum odin_net_status_e {
    /* all is good */
    odin_net_status_ok = 0,
    odin_net_status_nomem = 1,
    odin_net_status_invalid = 2,
    odin_net_status_invalid_args = 3,
    odin_net_status_invalid_address = 4,
} odin_net_status_t;

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ODIN_NET_TYPES_H */
