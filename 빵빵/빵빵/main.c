#include<stdio.h>
#include<time.h>
#include <windows.h>


int main()
{
    clock_t start, end;
    double cpu_time_used;

    start = clock();
    int i = 1;
    while (i <= 10)
    {
        printf("»§ÀÌ %d°³°¡ »ý¼ºµÊ\n", i);
        i = i + 1;

        Sleep(100);
    }

    end = clock();
    
    
    
        cpu_time_used = (double)(end - start) / CLOCKS_PER_SEC;
        printf("10°³ »ý»ê¿¡ ÃÑ %.2fÃÊ °É·È½À´Ï´Ù.\n", cpu_time_used);
   
    return 0;
}