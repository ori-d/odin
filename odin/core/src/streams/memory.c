#include <odin/core/streams/memory.h>
#include <odin/core/memory.h>

extern
ssize_t
libodin_memory_stream_seek(odin_stream_t *,
                           ssize_t ,
                           odin_stream_seek_t);

extern
ssize_t
libodin_memory_stream_write(odin_stream_t *,
                            const void *,
                            size_t);

extern
ssize_t
libodin_memory_stream_read(odin_stream_t *,
                           void *,
                           size_t);

extern
bool
libodin_memory_stream_flush(odin_stream_t *);

static
void
odin_memory_stream_destroy(odin_stream_t **pp_stream) {
    odin_free((*pp_stream)->s_cursor.p_internal);
    (*pp_stream) = NULL;
}

static
odin_status_t
odin_memory_stream_alloc(odin_stream_t **pp_stream) {
    (*pp_stream) = odin_calloc(1, sizeof(odin_stream_t));
    return NULL != (*pp_stream)
            ? odin_status_ok
            : odin_status_e_nomem;
}

static
odin_status_t
odin_memory_stream_cursor_new(odin_stream_t *stream, size_t size) {
    stream
        ->s_cursor
            .p_internal = odin_calloc(size, sizeof(uint8_t));
    
    if (NULL != stream->s_cursor.p_internal) {
        stream->s_cursor.i_size = size;
    }

    return stream
            ->s_cursor
                .p_internal != NULL
                    ? odin_status_ok
                    : odin_status_e_nomem;
}

odin_status_t
odin_memory_stream_create(odin_stream_t **pp_stream, size_t i_size) {
    odin_status_t status = odin_memory_stream_alloc(pp_stream);

    if (odin_status_good(status)) {
        status = odin_memory_stream_cursor_new((*pp_stream), i_size);
        if (odin_status_good(status)) {
            (*pp_stream)
                ->s_callback = (odin_stream_callback_t) {
                    .pfn_destroy = odin_memory_stream_destroy,
                    .pfn_flush = libodin_memory_stream_flush,
                    .pfn_read = libodin_memory_stream_read,
                    .pfn_seek = libodin_memory_stream_seek,
                    .pfn_write = libodin_memory_stream_write
                };
        } else {
            odin_memory_stream_destroy(pp_stream);
        }
    }

    return status;
}
