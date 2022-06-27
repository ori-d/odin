#ifndef ODIN_CORE_MMEORY_H
#define ODIN_CORE_MMEORY_H 1

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include <stddef.h>
#include "exports.h"

void *
odin_core_api
odin_malloc( size_t i_bytes );

void *
odin_core_api
odin_calloc( size_t i_count, size_t i_member_size );

void *
odin_core_api
odin_realloc( void *p_memory, size_t i_new_size );

void
odin_core_api
odin_free( void *p_memory );

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ODIN_CORE_MMEORY_H */
