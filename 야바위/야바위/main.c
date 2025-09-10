#include <iostream>Add commentMore actions
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <ctime>

// �Լ� ����
void showIntro();
void showStartMenu();
void countdownToStart();
void playGame(int score, int speed);
void showResult(int score);

// ���� �Լ�
int main() {
    int score = 0;
    int speed = 1000; // �� ���� �ӵ� (ms)

    showIntro();
    showStartMenu();
    countdownToStart();
    playGame(score, speed);
    showResult(score);

    return 0;
}

// ��Ʈ�� ȭ��
void showIntro() {
    system("cls");
    printf("==========================\n");
    printf("   �߹��� ���ӿ� ���� �� ȯ���մϴ�!\n");
    printf("   ������ �� ���� ���� ������!\n");
    printf("==========================\n");
    Sleep(2000);
}

// ���� �޴�
void showStartMenu() {
    system("cls");
    printf("�� ������ �����Ϸ��� Enter�� ��������.\n");
    printf("�� �����Ϸ��� ESC�� ��������.\n");

    while (1) {
        char key = _getch();
        if (key == 13) break;     // Enter
        if (key == 27) exit(0);   // ESC
    }
}

// ī��Ʈ�ٿ�
void countdownToStart() {
    system("cls");
    for (int i = 3; i >= 1; i--) {
        printf("���� ���۱���... %d��!\n", i);
        Sleep(1000);
        system("cls");
    }
    printf("����!\n");
    Sleep(1000);
}

// ���� ���� ����
void playGame(int score, int speed)
{
    while (1)
    {
        system("cls");
        srand((unsigned int)time(0));

        // �� �迭 �ʱ�ȭ
        int cups[3] = { 0, 0, 0 };
        int ballIndex = rand() % 3;
        cups[ballIndex] = 1;

        // ���� ��ġ �����ֱ�
        printf("���� ��ġ:\n");
        printf("[1]   [2]   [3]\n");
        printf("������ %d�� �� �Ʒ��� �ֽ��ϴ�!\n", ballIndex + 1);
        Sleep(1500);
        system("cls");

        // �� ����
        for (int i = 0; i < 5; i++)
        {
            int a = rand() % 3;
            int b = rand() % 3;
            while (b == a) b = rand() % 3;

            // swap
            int temp = cups[a];
            cups[a] = cups[b];
            cups[b] = temp;

            printf("���� ���� ��...\n");
            Sleep(speed);
            speed = max(200, speed - 100);
            system("cls");
        }

        // ����� �Է�
        int choice;
        printf("������ ��� �ſ� �������? (1~3): ");
        scanf_s("%d", &choice);

        if (choice < 1 || choice > 3) {
            printf("�߸��� �Է��Դϴ�. 1~3 ������ ���ڸ� �Է��ϼ���.\n");
            Sleep(1500);
            continue;
        }

        if (cups[choice - 1] == 1) {
            printf("�����Դϴ�!\n");
            score++;
        }
        else {
            int correct = (int)(std::find(cups, cups + 3, 1) - cups) + 1;
            printf("Ʋ�Ƚ��ϴ�. ������ %d�� ���̾����ϴ�.\n", correct);
        }

        printf("���� ����: %d\n", score);

        // �ִ� ���� 5�� ���� �� ����
        if (score >= 5) {
            printf("\n�����մϴ�! �ְ� ������ �����ϼ̽��ϴ�!\n");
            Sleep(3000);
            return;
        }

        printf("����Ϸ��� Enter, �����Ϸ��� ESC�� ��������...\n");

        while (1) {
            char key = _getch();
            if (key == 13) break;   // Enter
            if (key == 27) return;  // ESC
        }
    }
}
// ��� ���
void showResult(int score)
{
    system("cls");
    printf("���� ����!\n");
    printf("����� ������: 100�� �Դϴ�!\n", score);
    Sleep(3000);
}