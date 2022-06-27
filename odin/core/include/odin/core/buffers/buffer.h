/**
 * @file buffer.h
 * @author おり (kok.in@yahoo.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-27
 * 
 * @copyright Copyright (c) ori-d <おり> 2022
 * 
 */
#ifndef ODIN_CORE_BUFFER_H
#define ODIN_CORE_BUFFER_H 1

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include <stdbool.h>
#include <stddef.h>
#include "../exports.h"

typedef struct odin_buffer_cursor_s {
    /* internal data pointer */
    void *p_internal;
    size_t i_capacity;
    size_t i_size;
} odin_buffer_cursor_t;

typedef struct odin_buffer_s odin_buffer_t;

typedef
void (*odin_buffer_destroy_fn_t)
     (odin_buffer_t **);

typedef
bool (*odin_buffer_resizable_fn_t)
     (odin_buffer_t const *const);

typedef
size_t (*odin_buffer_write_fn_t)
       (odin_buffer_t *const, void *const, size_t);



typedef struct odin_buffer_callback_s {
    odin_buffer_destroy_fn_t pfn_destroy;
    odin_buffer_resizable_fn_t pfn_resizable;
} odin_buffer_callback_t;

typedef struct odin_buffer_s {
    odin_buffer_cursor_t s_cursor;
    odin_buffer_callback_t s_callback;
} odin_buffer_t;

/**
 * @brief Return the current size of the buffer.
 * 
 * @param[in] p_buffer pointer to a @a odin_buffer_t structure.
 * @return size_t 0 on error or positive number on success.
 */
size_t
odin_core_api
odin_buffer_size(odin_buffer_t const *const p_buffer);

/**
 * @brief Return the current capacity of the buffer.
 * 
 * @param[in] p_buffer pointer to a @a odin_buffer_t structure.
 * @return size_t 0 on error or positive number on success.
 */
size_t
odin_core_api
odin_buffer_capacity(odin_buffer_t const *const p_buffer);

/**
 * @brief Return the pointer to data of the buffer.
 * 
 * @param[in] p_buffer pointer to a @a odin_buffer_t structure.
 * @return void const* pointer to data.
 */
void const *
odin_core_api
odin_buffer_data(odin_buffer_t const *const p_buffer);

/**
 * @brief Write data to the buffer.
 * 
 * @param[in] p_buffer pointer to a @a odin_buffer_t structure.
 * @param[in] p_data pointer to data to be written to the buffer.
 * @param[in] i_size count of the data to be written to the buffer.
 * @return ssize_t count of written bytes or negative value on failure.
 */
ssize_t
odin_core_api
odin_buffer_write(odin_buffer_t * const p_buffer,
                  void *p_data, size_t i_size);

/**
 * @brief Resizes the buffer to the given size.
 * 
 * @param[in] i_new_size 
 * @return ssize_t difference after resizing, or a negative value on error.
 */
ssize_t
odin_core_api
odin_buffer_resize(odin_buffer_t * const p_buffer
                   size_t i_new_size);

/**
 * @brief Destroy the buffer and free allocated memory.
 * 
 * @param[in/out] pp_buffer On destroy complete, pointer will be set to NULL.
 */
void
odin_core_api
odin_buffer_destroy(odin_buffer_t **pp_buffer);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ODIN_CORE_BUFFER_H */
