
#include "cmart_sync.h"
#include "pthread.h"
#include "stdlib.h"
#include <string.h>
#include "stdio.h"

void cmart_mutex_init(cmart_mutex_t *cmart_mutex, void *inner, size_t inner_size)
{
    pthread_mutex_init(&cmart_mutex->mutex, NULL);
    cmart_mutex->inner = malloc(inner_size);
    memcpy(cmart_mutex->inner, inner, inner_size);
}

void *cmart_mutex_lock(cmart_mutex_t *cmart_mutex)
{
    if (pthread_mutex_lock(&cmart_mutex->mutex) != 0)
    {
        return NULL;
    }

    return cmart_mutex->inner;
}

void cmart_mutex_unlock(cmart_mutex_t **cmart_mutex)
{
    pthread_mutex_unlock(&(*cmart_mutex)->mutex);
}
