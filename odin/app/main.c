#include <odin/core/streams/memory.h>
#include <string.h>
#include <stdio.h>

int main(int argc, char const *argv[]) {
    odin_stream_t *stream;
    odin_status_t status;

    status = odin_memory_stream_create(&stream, sizeof(uint32_t));

    if (odin_status_good(status)) {
        odin_stream_destroy(&stream);
    }

    return status;
}

