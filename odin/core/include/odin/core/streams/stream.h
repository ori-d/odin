#ifndef ODIN_CORE_STREAM_H
#define ODIN_CORE_STREAM_H 1

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include "../object.h"
#include "../exports.h"
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

typedef enum odin_stream_seek_e {
    odin_stream_seek_begin,
    odin_stream_seek_current,
    odin_stream_seek_end
} odin_stream_seek_t;

typedef struct odin_stream_s odin_stream_t;

typedef
void    ( *odin_stream_destroy_cb_t )
        ( odin_stream_t ** );

typedef
ssize_t ( *odin_stream_read_cb_t )
        ( odin_stream_t *, void *, size_t );

typedef
ssize_t ( *odin_stream_write_cb_t )
        ( odin_stream_t *, void const *, size_t );

typedef
bool    ( *odin_stream_flush_cb_t )
        ( odin_stream_t * );

typedef
ssize_t ( *odin_stream_seek_cb_t )
        ( odin_stream_t *, ssize_t, odin_stream_seek_t );

typedef struct odin_stream_cursor_s {
    void *p_internal;
    ssize_t i_offset;
    ssize_t i_size;
} odin_stream_cursor_t;

typedef struct odin_stream_callback_s {
    odin_stream_read_cb_t pfn_read;
    odin_stream_write_cb_t pfn_write;
    odin_stream_flush_cb_t pfn_flush;
    odin_stream_seek_cb_t pfn_seek;
    odin_stream_destroy_cb_t pfn_destroy;
} odin_stream_callback_t;

typedef struct odin_stream_s {
    odin_stream_cursor_t s_cursor;
    odin_stream_callback_t s_callback;
} odin_stream_t;

ssize_t
odin_core_api
odin_stream_read(odin_stream_t *stream,
                 void *buffer,
                 size_t i_read_count);

ssize_t
odin_core_api
odin_stream_write(odin_stream_t *stream,
                  void const *const p_data,
                  size_t i_data_size  );

bool
odin_core_api
odin_stream_flush(odin_stream_t *stream);

ssize_t
odin_core_api
odin_stream_seek(odin_stream_t *stream,
                 ssize_t i_offset,
                 odin_stream_seek_t e_seek);

ssize_t
odin_core_api
odin_stream_tell(odin_stream_t const *const stream);

void
odin_core_api
odin_stream_destroy(odin_stream_t **pp_stream);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ODIN_CORE_STREAM_H */
