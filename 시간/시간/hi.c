#include <stdio.h>
#include <time.h>
#include <windows.h>

int main()
{
    clock_t start, end;
    double cpu_time_used;

    start = clock();
    int i = 0;
    while (i <= 3)
    {
        printf("ㅎㅇ %d\n", i);
        i = i + 1;

        Sleep(1000);
    }

    end = clock();

    if (i <= 5)
    {
        printf("5초 경과\n");
    }
    cpu_time_used = (double)(end - start) / CLOCKS_PER_SEC;
    printf("걸린 시간: %.2f초\n", cpu_time_used);

    return 0;
}


