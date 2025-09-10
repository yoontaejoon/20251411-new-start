#include<stdio.h>
#include<time.h>
#include<conio.h>
#include<windows.h>

void gotoXY(int x, int y) {
	printf("\033[%d;%dH", y, x);
}

void setTextColor(int color) {
	printf("\033[%dm", color);  // 31=����, 32=�ʷ�, 33=���
}

void resetTextColor() {
	printf("\033[0m");
}

	int main()
	{
	char sequence[5] = { 'T','R','A','I','N' };
	int correct = 0, wrong = 0;
	for (int i = 0; i < 5; i++)
	{
		system("cls");
		gotoXY(0, 0);
		printf("���� ����:%c", sequence[i]);
		unsigned int start = GetTickCount();
		char input = 0;
		int entered = 0;
		while (GetTickCount() - start < 5000)
		{
			if (_kbhit())
			{
				input = _getch();
				entered = 1;
				break;
			}
			Sleep(10);
		}


		gotoXY(0, 1);
		if (entered)
		{
			printf("%c", input);
		}
		else
		{
			printf("�Է� ����");
			wrong++;
			gotoXY(0, 2);
			setTextColor(31);
			printf("����");
			resetTextColor();
			if (wrong >= 3) break;
			Sleep(1000);
			continue;
		}
		gotoXY(0, 2);
		if (input == sequence[i])
		{
			correct++;
			setTextColor(32);
			printf("�Ϻ�");
		}
		else
		{
			wrong++;
			setTextColor(31);
			printf("����");
		}
		resetTextColor();
		if (wrong >= 3) break;
		Sleep(1000);
	}
gotoXY(0, 4);
setTextColor(33);
printf("=== ��� ===\n");
printf("���� ��: %d\n", correct);
printf("���� ��: %d\n", wrong);
resetTextColor();

return 0;

}