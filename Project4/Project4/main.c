#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include<time.h>

void gotoxy(int x, int y) 
{
    COORD pos = { x,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int main() {
    printf("10�� ���� �ƹ� Ű�� �Է��ϼ���.\n");

    int count = 0;
    time_t start = time(NULL);
    time_t now = start;
        
    while (now-start<10)
    {
        now = time(NULL);
        gotoxy(0, 5);

        if (_kbhit()) 
        {
            _getch();
            printf("������ �ϼ���");
            count++;
        }
        else 
        {
            printf("              ");
        }
        Sleep(100);
        gotoxy(0, 8);
        printf("���� �ð� %2d", 10-(int)(now - start));
    }
    gotoxy(0, 9);
    printf("�� �Է� %d", count);
    return 0;
}