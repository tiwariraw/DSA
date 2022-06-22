#include <stdio.h>
int main()
{
    void *p;
    int x = 5;
    p = &x;
    printf("%d", *p);
    return 0;
}
