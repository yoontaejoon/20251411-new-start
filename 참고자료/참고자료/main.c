#include <stdio.h>Add commentMore actions
#include <conio.h>
#include <Windows.h>

// ANSI ���� �ڵ�
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define RESET   "\033[0m"

// ANSI Ŀ�� �̵�
void gotoXY(int x, int y) {
    printf("\033[%d;%dH", y, x);
}

int main() {
    char target[5] = { 'A', 'S', 'D', 'F', 'G' };
    int correct = 0;
    int wrong = 0;

    for (int i = 0; i < 5; i++) {
        system("cls");

        // 1. ���� ���ĺ� ���
        gotoXY(0, 1);
        printf("���� ����: %c", target[i]);

        // 2. �Է� ���: 1�� ���� _kbhit()�� ����, �ԷµǸ� getch() ���
        char input = 0;
        int time = 0;
        while (time < 10) { // 1�� = 100ms * 10
            if (_kbhit()) {
                input = _getch(); // �Էµ� Ű
                break;
            }
            Sleep(100);
            time++;
        }

        // 3. �Է��� ���� ���
        gotoXY(0, 2);
        if (input != 0) {
            printf("%c", input);
        }
        else {
            printf("�Է� ����");
        }

        // 4. ��� ���� ���
        gotoXY(0, 3);
        if (input == target[i]) {
            printf(GREEN "�Ϻ�!!!" RESET);
            correct++;
        }
        else {
            printf(RED "����!!!" RESET);
            wrong++;
        }

        // 5. ��� ����
        Sleep(800);
    }

    // 6. ��� ȭ��
    system("cls");
    gotoXY(0, 5);
    printf(YELLOW "=== ��� ===" RESET);
    gotoXY(0, 6);
    printf(YELLOW "���� ��: %d" RESET, correct);
    gotoXY(0, 7);
    printf(YELLOW "���� ��: %d" RESET, wrong);

    return 0;
}