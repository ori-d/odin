#ifndef ODIN_CORE_MEM_STREAM_H
#define ODIN_CORE_MEM_STREAM_H 1

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include "stream.h"
#include "../exports.h"

odin_status_t
odin_core_api
odin_memory_stream_create(odin_stream_t **pp_stream, size_t i_size);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ODIN_CORE_MEM_STREAM_H */
