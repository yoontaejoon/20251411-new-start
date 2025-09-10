#include<stdio.h>
#include<windows.h>
#include<time.h>

int main()
{
	int d = 1;
	while (d <= 1000000)
	{
		printf("현재 걸린 시간 %d초\n",d);
		Sleep(1);
		d = d +1;

	}
	return 0;
}