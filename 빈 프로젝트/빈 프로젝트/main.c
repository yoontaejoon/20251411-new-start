#include<stdio.h>
#include<windows.h>
#include<time.h>

int main()
{
	int d = 1;
	while (d <= 1000000)
	{
		printf("���� �ɸ� �ð� %d��\n",d);
		Sleep(1);
		d = d +1;

	}
	return 0;
}