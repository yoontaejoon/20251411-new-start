#include <stdio.h>
#include <conio.h>
#include <Windows.h>

void gotoXY(int x, int y) {
    printf("\\033[%d;%dH", y, x);
}

int main() {
    printf("�ƹ� Ű�� ������ 'Pressed'�� ��Ÿ���ϴ�.\n");
    printf("Ű�� ������ ������ �������ϴ�.\n");
    while (1) {
        gotoXY(0, 5);
        if (_kbhit()) {
            _getch();
            printf("�ƹ� Ű�� ��������");
        }
        else {
            printf("      �� ������ �ϼ���           ");
        }
        Sleep(100);
    }
    return 0;
}

