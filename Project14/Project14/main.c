#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <time.h>

void gotoXY(int x, int y)
{
    COORD pos = { x,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void setTextColor(int color) {
    printf("\033[%dm", color);
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

int main()
{
    int i = 0;
    int correct = 0;
    int wrong = 0;
    int total = 3;
    char input;
    clock_t start = 0;
    clock_t end;
    double cpu_time_used;

    int started = 0; // ���� ����

    gotoXY(0, 0);
    setTextColor(37);
    printf("END");
    resetTextColor();

    while (1)
    {
        input = _getch();

        if (started == 0) {
            start = clock(); // ù �Է� ���� �ð� ���� ����
            started = 1;
        }

        if (input == 13) // ���� �Է��ϸ� ����
            break;

        if (input == 8 && i > 0)
        {
            i=i-1;
            gotoXY(i, 1);
            printf(" ");
            gotoXY(i, 1);
            if (correct > 0) correct=correct-1;
            else if (wrong > 0) wrong=wrong-1;
            continue;
        }

        gotoXY(i, 1);
        if ((i == 0 && input == 'E') ||
            (i == 1 && input == 'N') ||
            (i == 2 && input == 'D'))
        {
            setTextColor(37);
            printf("%c", input);
            correct=correct+1;
            resetTextColor();
        }
        else
        {
            setTextColor(31);
            if (input == ' ')
            {
                startUnderline();
                printf("%c", input);
                endUnderline();
            }
            else
            {
                printf("%c", input);
            }
            wrong=wrong+1;
        }

        resetTextColor();
        i = i + 1;

        end = clock();
        double seconds = (double)(end - start) / CLOCKS_PER_SEC;

        int ��Ȯ = correct - wrong;
        if (��Ȯ < 0) ��Ȯ = 0;

        double speed;
        if (started == 1) 
        {
            speed = (��Ȯ / seconds) * 60.0;
        }
        else {
            speed = 0;
        }

        gotoXY(0, 3);
        setTextColor(32);
        printf("�ǽð� Ÿ��:%.0f     \n", speed);
        resetTextColor();

        gotoXY(0, 5);
        printf("���� ��/ ��ü :%d/%d\n", correct, total);
        gotoXY(0, 6);
        printf("Ʋ���� %d\n", wrong);
        gotoXY(0, 7);
        printf("Ÿ��:%.0f\n     ", speed);

        cpu_time_used = 0;
        if (started == 1)
        {
            cpu_time_used = (double)(end - start) / CLOCKS_PER_SEC;
        }

        gotoXY(0, 8);
        printf("�ɸ� �ð�: %.2f��\n", cpu_time_used);
    }

    return 0;
}