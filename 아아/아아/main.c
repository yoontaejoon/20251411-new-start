#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<time.h>

void gotoXY(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int main()
{
	printf("10초 동안 아무 키나 입력하세요");

	time_t start = time(NULL);
	int count = 0;

	while (time(NULL) - start < 10)
	{
		gotoxy(0, 5);
		if (_kbhit())
		{
			_getch;
			printf("열심히 하세요");
		}
		else
		{
			printf("  잘 하고 있어요  ");
		}
		Sleep(100);
		gotoxy(0, 6);
		printf("남은 시간 %2d", 10 - (time(NULL) - start));
		count = count + 1;
	}
	gotoxy(0, 7);
	printf("총 입력 횟수:%d", count);
	return 0;
}