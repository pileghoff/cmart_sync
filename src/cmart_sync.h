
#ifndef __CMART_SYNC_H__
#define __CMART_SYNC_H__

#include <pthread.h>
#include <stddef.h>
#include "stdlib.h"
#include <string.h>

typedef struct
{
    pthread_mutex_t mutex;
    void *inner;
} cmart_mutex_t;

void cmart_mutex_init(cmart_mutex_t *cmart_mutex, void *inner, size_t inner_size);

void *cmart_mutex_lock(cmart_mutex_t *cmart_mutex);

void cmart_mutex_unlock(void **inner);

#define CMART_MUTEX_CREATE(type, name) \
    cmart_mutex_t name##_mutex;        \
    typedef type name##_inner_t

#define CMART_MUTEX_TAKE(name)                                                                                              \
    __attribute__((cleanup(cmart_mutex_unlock))) void *name##_to_clean = (name##_inner_t *)cmart_mutex_lock(&name##_mutex); \
    name##_inner_t *name = (name##_inner_t *)name##_to_clean

#define CMART_MUTEX_INIT(name, initial)                                                      \
    {                                                                                        \
        name##_inner_t name##initial_val = initial;                                          \
        cmart_mutex_init(&name##_mutex, (void *)&name##initial_val, sizeof(name##_inner_t)); \
    }                                                                                        \
    while (0)

#endif