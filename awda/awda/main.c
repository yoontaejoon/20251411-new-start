#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <ctime>

void gotoXY(int x, int y) {
    printf("\\033[%d;%dH", y, x);
}

// 글자 색상 설정: 31=빨강, 32=초록, 33=노랑, 37=흰색
void setTextColor(int color) {
    printf("\\033[%dm", color);
}

// 색상 초기화
void resetTextColor() {
    printf("\\033[0m");
}

// 밑줄 시작
void startUnderline() {
    printf("\\033[4m");
}

// 밑줄 종료
void endUnderline() {
    printf("\\033[24m");
}

