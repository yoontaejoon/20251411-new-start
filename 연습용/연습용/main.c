#include <stdio.h>
#include <conio.h>
#include <Windows.h>

void gotoXY(int x, int y) {
    printf("\\033[%d;%dH", y, x);
}

int main() {
    printf("아무 키나 누르면 'Pressed'가 나타납니다.\n");
    printf("키를 누르지 않으면 지워집니다.\n");
    while (1) {
        gotoXY(0, 5);
        if (_kbhit()) {
            _getch();
            printf("아무 키나 누르세요");
        }
        else {
            printf("      더 열심히 하세요           ");
        }
        Sleep(100);
    }
    return 0;
}

