#include <odin/core/streams/memory.h>
#include <string.h>
#include <stdbool.h>

extern
ssize_t
libodin_memory_stream_seek( odin_stream_t *stream,
                            ssize_t offset,
                            odin_stream_seek_t seek ) {
    ssize_t ret;
    if ( NULL == stream
        || offset > (stream->s_cursor.i_size + offset) ) {
        return -1;
    }

    switch (seek)
    {
    case odin_stream_seek_begin: {
        stream->
            s_cursor
                .i_offset
                    = ret
                    = offset;
    } break;
    case odin_stream_seek_current: {
        ret = (stream->s_cursor.i_offset += offset);
    } break;
    case odin_stream_seek_end: {
        stream->s_cursor.i_offset
            = ret
            = stream->s_cursor.i_size - offset;
    } break;
    default:
        return -1;
    }

    return ret;
}

ssize_t
libodin_memory_stream_write(odin_stream_t *stream,
                            const void *data,
                            size_t size) {
    uint8_t *cursor;
    if (stream->s_cursor.i_size > stream->s_cursor.i_offset + size) {
        return -1;
    }

    cursor = stream
                ->s_cursor
                    .p_internal += odin_stream_tell(stream);

    (void) memcpy (cursor, data, size);
    (void) libodin_memory_stream_seek(stream, size, odin_stream_seek_current);
    return size;
}

extern
ssize_t
libodin_memory_stream_read( odin_stream_t *stream,
                            void *buffer,
                            size_t count) {
    if (NULL == stream) {
        return -1;
    }

    (void) memcpy(buffer, stream->s_cursor.p_internal, count);
    (void) libodin_memory_stream_seek(stream, count, odin_stream_seek_current);
    return count;
}

extern
bool
libodin_memory_stream_flush(odin_stream_t *stream) {
    return NULL != stream;
}
