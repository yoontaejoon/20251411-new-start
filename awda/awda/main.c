#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <ctime>

void gotoXY(int x, int y) {
    printf("\\033[%d;%dH", y, x);
}

// ���� ���� ����: 31=����, 32=�ʷ�, 33=���, 37=���
void setTextColor(int color) {
    printf("\\033[%dm", color);
}

// ���� �ʱ�ȭ
void resetTextColor() {
    printf("\\033[0m");
}

// ���� ����
void startUnderline() {
    printf("\\033[4m");
}

// ���� ����
void endUnderline() {
    printf("\\033[24m");
}

