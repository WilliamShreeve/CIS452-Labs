#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    puts("Before fork");
    sleep(10);
    fork();
    sleep(10);
    puts("After fork");
    return 0;
}
