#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<time.h>

void gotoXY(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
int main() {
    printf("10초 동안 아무 키나 입력하세요.\n");
    
    time_t start = time(NULL);
    int count = 0;

    while (time(NULL) - start < 10)
    {
        gotoXY(0, 5);  

        if (_kbhit()) 
        {
            _getch();          
            printf("열심히 치세요"); 
        }
        else {
            printf("             ");
        }     
        Sleep(100);
        gotoXY(0, 6);
        printf("남은 시간 %2d", 10-(time(NULL) - start));
        count = count + 1;
    }
    gotoXY(0, 7);
    printf("총 입력 수:%d",count);

    return 0;
}
