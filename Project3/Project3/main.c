#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<time.h>
void gotoxy(int x,int y)
{
	COORD pos = {x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
int main()
{
	time_t start = time(NULL);
	time_t end = time(NULL);
	for (int i = 10; i > 0; i--)
	{
		gotoxy(0, 7);
		printf("\r%2d", i);
		fflush(stdout);
		Sleep(1000);

	}
	gotoxy(0,7);
	printf("\r%d√  ≥°", end - start);
	return 0;
}
