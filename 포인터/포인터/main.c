#include<stdio.h>

void sum(int x, int y, int* result)
{
	*result = x + y;
}

int main()
{
	int a = 3;
	int b = 2;
	int c = 0;

	int* pa;
	pa = &a;
	//printf("%d", *pa);

	sum(a, b,&c);
	printf("%d", c);
	return 0;
}


//*는 포인터:주소를 저장하는 변수,,&는 주소:메모리가 저장된 위치