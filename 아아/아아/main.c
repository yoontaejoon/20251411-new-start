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
	printf("10�� ���� �ƹ� Ű�� �Է��ϼ���");

	time_t start = time(NULL);
	int count = 0;

	while (time(NULL) - start < 10)
	{
		gotoxy(0, 5);
		if (_kbhit())
		{
			_getch;
			printf("������ �ϼ���");
		}
		else
		{
			printf("  �� �ϰ� �־��  ");
		}
		Sleep(100);
		gotoxy(0, 6);
		printf("���� �ð� %2d", 10 - (time(NULL) - start));
		count = count + 1;
	}
	gotoxy(0, 7);
	printf("�� �Է� Ƚ��:%d", count);
	return 0;
}