#include <mimalloc.h>
#include <odin/core/exports.h>

void *
libodin_core_malloc( size_t i_size ) {
    return mi_malloc ( i_size );
}

void *
libodin_core_calloc( size_t c, size_t s ) {
    return mi_calloc ( c, s );
}

void *
libodin_core_realloc( void * p, size_t i ) {
    return mi_realloc ( p, i );
}

void
libodin_core_free( void * p) {
    return mi_free ( p );
}
