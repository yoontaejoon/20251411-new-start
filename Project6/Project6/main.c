#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <Windows.h>
VOID gotoxy(int x, int y)
{
    COORD pos = { x,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
int main() {
    int count = 0;
    time_t start = time(NULL);
    time_t now = start;

    printf("10�� ���� �ƹ� Ű�� ����������!\n");

    while (time(NULL) - start < 10) {  // Ÿ�̸� ����
        time_t now = time(NULL);
        gotoxy(0,5);
        printf("��� ��������");
        if (_kbhit()) {
            _getch(); // Ű�� �а� (������ ����)
            count++;  // ���� Ƚ�� ����
        }
        Sleep(100); // CPU ������ ����
        gotoxy(0, 5);
        printf("             ");
 gotoxy(0, 6);
    printf("���� �ð� %2d��\n", 10 - (int)(now - start));
    }
   
    printf("�ð� ����!\n");
    printf("�� ���� Ƚ��: %d\n", count);

    return 0;
}
