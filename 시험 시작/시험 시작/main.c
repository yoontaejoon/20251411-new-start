#include <stdio.h>
#include <conio.h>
#include <Windows.h>

// ANSI Escape Code를 이용한 커서 이동 함수
void gotoXY(int x, int y) {
    printf("\033[%d;%dH", y, x);  // 커서를 (x, y) 위치로 이동 (y가 행, x가 열)
}



int main() {
    printf("10초 동안 아무 키나 누르세요.\n");
    printf("남은 시간은 %2.0f초\n");

    while (1) {
        gotoXY(0, 5);  // 커서를 5행 0열로 이동

        if (_kbhit()) {
            _getch();          // 키보드 입력을 받아오되, 화면에는 출력하지 않음
            printf(" 열심히 치세요 "); // 키가 눌렸을 때 출력
        }
        else {
            printf("아무거나 치세요"); // 키가 안 눌렸을 때 기존 글자 덮어쓰기
        }

        
        Sleep(100);  
    }


    
    return 0;
}
