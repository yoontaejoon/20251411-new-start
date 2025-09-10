#include <stdio.h>

void gotoXY(int x, int y) {
    printf("\033[%d;%dH", y, x);
}

void setTextColor(int color) {
    printf("\033[%dm", color); // 31=빨강, 32=초록, 33=노랑, 37=흰색 등
}

void resetTextColor() {
    printf("\033[0m");
}

void startUnderline() {
    printf("\033[4m");
}

void endUnderline() {
    printf("\033[24m");
}

int main() {
    // 콘솔 초기화 (커서 위치 초기화)
    printf("\033[2J"); // 화면 지우기
    printf("\033[H");  // 커서 홈 위치

    // 10,5 좌표로 가서 빨간색 밑줄 텍스트 출력
    gotoXY(10, 5);
    setTextColor(31);  //글자색을 빨간색으로 설정해.
    startUnderline(); //밑줄 스타일을 켜서 이후 출력되는 텍스트에 밑줄을 넣어
    printf("Hello, World!"); // "Hello, World!"를 빨간색 밑줄 텍스트로 출력해.
    endUnderline();//"Hello, World!"를 빨간색 밑줄 텍스트로 출력해
    resetTextColor(); //글자색을 기본값(흰색 등)으로 초기화.

    // 10,7 좌표로 가서 초록색 일반 텍스트 출력
    gotoXY(10, 7);
    setTextColor(32);  // 초록
    printf("This is green text.");
    resetTextColor();

    // 10,9 좌표로 가서 노란색 밑줄 텍스트 출력 후 밑줄 해제
    gotoXY(10, 9);
    setTextColor(33);  // 노랑
    startUnderline();
    printf("Underlined yellow text");
    endUnderline();
    resetTextColor();

    // 커서가 텍스트 아래에 위치하도록 조정
    gotoXY(0, 12);

    return 0;
}
