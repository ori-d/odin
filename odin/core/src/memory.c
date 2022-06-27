#include <odin/core/memory.h>

/* from lib/memory.c */

extern
void *
libodin_core_malloc( size_t );

extern
void *
libodin_core_calloc( size_t, size_t );

extern
void *
libodin_core_realloc( void *, size_t );

extern
void
libodin_core_free( void * );

void *
odin_malloc( size_t i_bytes ) {
    return libodin_core_malloc ( i_bytes );
}

void *
odin_calloc( size_t i_count, size_t i_member_size ) {
    return libodin_core_calloc ( i_count, i_member_size );
}

void *
odin_realloc( void *p_memory, size_t i_new_size ) {
    return libodin_core_realloc ( p_memory, i_new_size );
}

void
odin_free( void *p_memory ) {
    return libodin_core_free ( p_memory );
}
