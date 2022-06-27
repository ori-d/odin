#ifndef ODIN_CORE_OBJECT_H
#define ODIN_CORE_OBJECT_H 1

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include <stdint.h>
#include <errno.h>

typedef enum odin_status_e {
    odin_status_ok = 0,
    odin_status_e_access = 1,
    odin_status_e_nomem = 2,
    /* bad address */
    odin_status_e_fault = 3,
    odin_status_e_ilseq = 4,
    _odin_status_e_max = 0xffffffffu
} odin_status_t;

typedef struct odin_object_s {
    odin_status_t status;
} odin_object_t;

#define odin_status_good(o)                         \
((odin_status_ok) == (o))

#define odin_status_bad(o)                          \
!odin_status_good(0)

#define odin_object_valid(o)                        \
odin_status_good((o)->status)

#define odin_object_invalid(o)                      \
odin_status_bad((o)->status)


#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ODIN_CORE_OBJECT_H */
