#include <odin/core/streams/stream.h>
#include <odin/core/memory.h>

ssize_t
odin_stream_read(odin_stream_t *stream,
                 void *buffer,
                 size_t count ) {
    return stream
            ->s_callback
                .pfn_read( stream, buffer, count );
}

ssize_t
odin_stream_seek(odin_stream_t *stream,
                 ssize_t offset,
                 odin_stream_seek_t origin) {
    return stream
            ->s_callback
                .pfn_seek(stream, offset, origin);
}
ssize_t
odin_stream_tell(odin_stream_t const *const stream) {
    return stream
            ->s_cursor
                .i_offset;
}

ssize_t
odin_stream_write(odin_stream_t *stream,
                  void const *data,
                  size_t size ) {
    return stream
            ->s_callback
                .pfn_write(stream, data, size);
}

bool
odin_stream_flush(odin_stream_t *stream) {
    return stream
            ->s_callback
                .pfn_flush(stream);
}

void
odin_stream_destroy(odin_stream_t **stream) {
    (*stream)
        ->s_callback
            .pfn_destroy(stream);
}
