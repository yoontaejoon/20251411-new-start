#include <stdio.h>
#include <conio.h>
#include <Windows.h>

// ANSI Escape Code�� �̿��� Ŀ�� �̵� �Լ�
void gotoXY(int x, int y) {
    printf("\033[%d;%dH", y, x);  // Ŀ���� (x, y) ��ġ�� �̵� (y�� ��, x�� ��)
}



int main() {
    printf("10�� ���� �ƹ� Ű�� ��������.\n");
    printf("���� �ð��� %2.0f��\n");

    while (1) {
        gotoXY(0, 5);  // Ŀ���� 5�� 0���� �̵�

        if (_kbhit()) {
            _getch();          // Ű���� �Է��� �޾ƿ���, ȭ�鿡�� ������� ����
            printf(" ������ ġ���� "); // Ű�� ������ �� ���
        }
        else {
            printf("�ƹ��ų� ġ����"); // Ű�� �� ������ �� ���� ���� �����
        }

        
        Sleep(100);  
    }


    
    return 0;
}
