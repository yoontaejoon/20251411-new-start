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

    printf("10초 동안 아무 키나 눌러보세요!\n");

    while (time(NULL) - start < 10) {  // 타이머 루프
        time_t now = time(NULL);
        gotoxy(0,5);
        printf("계속 누르세요");
        if (_kbhit()) {
            _getch(); // 키를 읽고 (보이진 않음)
            count++;  // 누른 횟수 증가
        }
        Sleep(100); // CPU 과부하 방지
        gotoxy(0, 5);
        printf("             ");
 gotoxy(0, 6);
    printf("남은 시간 %2d초\n", 10 - (int)(now - start));
    }
   
    printf("시간 종료!\n");
    printf("총 눌린 횟수: %d\n", count);

    return 0;
}
