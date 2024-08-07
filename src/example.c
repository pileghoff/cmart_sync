
#include "cmart_sync.h"
#include "stdio.h"

CMART_MUTEX_CREATE(int, test_mutex);

void a()
{
    int *m = CMART_MUTEX_TAKE(test_mutex);
    *m += 1;
    printf("Set %d\n", *m);
}

void b()
{
    int *m = CMART_MUTEX_TAKE(test_mutex);
    printf("Take %d\n", *m);
}

void main()
{
    CMART_MUTEX_INIT(test_mutex, 0);
    a();
    b();
}