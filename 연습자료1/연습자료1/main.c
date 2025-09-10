#include <stdio.h>
#include <windows.h>

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = (SHORT)x; // 명시적 형변환 권장
    coord.Y = (SHORT)y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main() {
    gotoxy(0, 0);
    printf("이거 맞아요?");
    
    gotoxy(0, 1);
    printf("안녕하세요");

    gotoxy(0, 2);
    printf("네 안녕하세요");
    
    gotoxy(0, 3);
    printf("하이");
    
    gotoxy(0, 4);
    printf("ㅎㅇ");

    gotoxy(0, 5);
    printf("이거 되려나");
    
    gotoxy(0, 6);
    printf("이게 맞을라나");
    
    return 0;
}





//int main()
//{
   // gotoxy(20, 3);
    //printf("\033[43m 안녕 얘들아 \033[0m");

    //gotoxy(9, 7);
    //printf("\033[31m 이건 빨간 글씨고\033[0m \033[44m 이건 파란 배경이야\033[0m");


    //return 0;
//}