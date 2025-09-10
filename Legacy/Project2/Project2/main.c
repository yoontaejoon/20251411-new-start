#include <stdio.h>
#include <conio.h>
#include <windows.h>

// 커서 이동 함수
void gotoxy(int x, int y) {
    COORD pos = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int main() {
    char c;
    int isLoop = 1;

    gotoxy(2, 2);
    printf("input>");

    while (isLoop) {
        c = _getch();

        if (c >= '0' && c <= '9') {
            gotoxy(9, 2);
            printf("\033[92m%c\033[0m", c);  // 밝은 초록색 글자 출력
            isLoop = 0;
        }
        else {
            gotoxy(2, 3);
            printf("\033[31m\a오류: 숫자만 입력하세요.\033[0m     ");  // 빨간색 경고 + 경고음
        }
    }

    return 0;
}
