#include <stdio.h>
#include <windows.h>

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = (SHORT)x; // ����� ����ȯ ����
    coord.Y = (SHORT)y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main() {
    gotoxy(0, 0);
    printf("�̰� �¾ƿ�?");
    
    gotoxy(0, 1);
    printf("�ȳ��ϼ���");

    gotoxy(0, 2);
    printf("�� �ȳ��ϼ���");
    
    gotoxy(0, 3);
    printf("����");
    
    gotoxy(0, 4);
    printf("����");

    gotoxy(0, 5);
    printf("�̰� �Ƿ���");
    
    gotoxy(0, 6);
    printf("�̰� ������");
    
    return 0;
}





//int main()
//{
   // gotoxy(20, 3);
    //printf("\033[43m �ȳ� ���� \033[0m");

    //gotoxy(9, 7);
    //printf("\033[31m �̰� ���� �۾���\033[0m \033[44m �̰� �Ķ� ����̾�\033[0m");


    //return 0;
//}