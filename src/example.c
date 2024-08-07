
#include "cmart_sync.h"
#include "stdio.h"

CMART_MUTEX_CREATE(int, test_mutex);

void a()
{
    CMART_MUTEX_TAKE(test_mutex);
    *test_mutex += 1;
    printf("Set %d\n", *test_mutex);
}

void b()
{
    CMART_MUTEX_TAKE(test_mutex);
    printf("Take %d\n", *test_mutex);
}

void main()
{
    CMART_MUTEX_INIT(test_mutex, 0);
    a();
    b();
}