#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <Windows.h>
#include <string.h>

// ANSI Ŀ�� �̵�
void gotoXY(int x, int y) {
    printf("\033[%d;%dH", y, x);
}

// �ؽ�Ʈ ���� ����
void setTextColor(int color) {
    printf("\033[%dm", color);
}

// ���� �ʱ�ȭ
void resetTextColor() {
    printf("\033[0m");
}

// ���� on/off
void startUnderline() {
    printf("\033[4m");
}

void endUnderline() {
    printf("\033[24m");
}

int main() {
    const char* target = "hello my name is taejoon";
    char input[100] = { 0 };
    int len = strlen(target);
    int pos = 0, correct = 0, wrong = 0;

    clock_t startTime = clock();

    // �� ���� ���� ��� (1��)
    gotoXY(0, 1);
    setTextColor(37);  // ���
    printf("%s", target);
    resetTextColor();

    while (1) {
        gotoXY(0, 2);  // 2�࿡�� �Է� ǥ��
        char ch = _getch();

        if (ch == 13) break;  // Enter ������ ����

        if (ch == 8) {  // Backspace
            if (pos > 0) {
                pos--;
                input[pos] = '\0';
                gotoXY(pos, 2);
                printf(" ");  // �����
                gotoXY(pos, 2);
            }
            continue;
        }

        if (pos >= len) continue;  // ���� �ʰ� ����

        input[pos] = ch;

        // �� �� ���
        gotoXY(pos, 2);
        if (ch == target[pos]) {
            setTextColor(37);  // ���
            printf("%c", ch);
            correct++;
        }
        else {
            setTextColor(31);  // ����
            startUnderline();
            printf("%c", ch);
            endUnderline();
            wrong++;
        }
        resetTextColor();

        pos++;

        clock_t now = clock();
        double seconds = (double)(now - startTime) / CLOCKS_PER_SEC;
        double speed = (seconds > 0) ? ((correct - wrong) / seconds) * 60.0 : 0;

        gotoXY(0, 4);
        setTextColor(32); 
        printf("���� Ÿ��: %.0f    ", speed);
        resetTextColor();
    }

    clock_t endTime = clock();
    double totalTime = (double)(endTime - startTime) / CLOCKS_PER_SEC;
    double finalSpeed = ((correct - wrong) / totalTime) * 60.0;

    gotoXY(0, 6);
    setTextColor(33); 
    printf("���� Ÿ��: %.0f\n", finalSpeed);
    resetTextColor();

    return 0;
}
