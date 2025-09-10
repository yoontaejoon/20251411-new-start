#include <stdio.h>
#include <conio.h>    
#include <windows.h> 
#include <string.h>
#include <stdlib.h>

void gotoxy(int x, int y) {
    COORD pos = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void drawInputUI() {
    gotoxy(10, 2);
    printf("한번 맞춰 보시지 케케");

    gotoxy(10, 4);
    printf("[ ] [ ] [ ] [ ]");

    gotoxy(11, 4);
}

int main() {
    char slots[5] = { ' ', ' ', ' ', ' ', '\0' }; 
    int filled = 0;
    char ch;

    system("cls");
    drawInputUI();

    while (filled < 4) {
        ch = _getch();

        if (ch >= '0' && ch <= '9') {
            slots[filled] = ch;

            gotoxy(11 + filled * 4, 4);
            printf("%c", ch);

            filled++;
            if (filled < 4) {
                gotoxy(11 + filled * 4, 4);
            }
        }
        else if (ch == '\b' && filled > 0) {
            filled--;
            slots[filled] = ' ';
            gotoxy(11 + filled * 4, 4);
            printf(" ");
            gotoxy(11 + filled * 4, 4);
        }
    }

    gotoxy(0, 6);
    if (strcmp(slots, "8540") == 0) {
        printf("너 정답을 아는구나?\n");
    }
    else {
        int value = atoi(slots);
        if (value % 2 == 0) {
            printf("응 너 짱ㅋ\n");
        }
        else {
            printf("넌 절대 못 맞춰ㅋㅋ\n");
        }
    }
    printf("\n엔터 ㄱㄱ");
    getchar();
    return 0;
}
