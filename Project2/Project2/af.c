#include <stdio.h>
#include <windows.h>

void sleep1sec();
void showGameStart();
void showIntro();
void showHoldBackAnger();
void showHitDesk();

// 1�� ��� �Լ�
void sleep1sec() {
    Sleep(1000); // 1�� ���
}

// ù ��° ȭ�� ���
void showIntro() {
    system("cls");
    printf("�г� : ��Ƽ�̵����� �߰���� ������ ���� ����\n\n");
    sleep1sec();

    printf("[������]\n");
    printf("1. ���ӽ���\n");
    printf("2. ��������\n");
    printf("�Է��ϼ���: ");

    char choice = getchar(); getchar(); // Enter ó��
    if (choice == '1') {
        showGameStart();
    }
    else if (choice == '2') {
        printf("���� ����...\n");
    }
}

// ���� ���� ȭ�� ���
void showGameStart() {
    system("cls");
    printf("�߰���� ������ ���� ���� ������ �г븦 �������ִ�.\n\n");
    sleep1sec();

    printf("[������]\n");
    printf("1. å���� ģ��.\n");
    printf("2. ���´�.\n");
    printf("�Է��ϼ���: ");

    char choice = getchar(); getchar(); // Enter ó��
    if (choice == '1') {
        showHitDesk();
    }
    else if (choice == '2') {
        showHoldBackAnger();
    }
}

// å���� ĥ ���� ȭ�� ���
void showHitDesk() {
    system("cls");
    printf("��!!!!\n\n");
    sleep1sec();
    printf("�ķ��ϴ�....\n\n");
    sleep1sec();
    printf("�ٽ� ȭ�� ���� ������ ������ �ķ�������....\n\n");
    sleep1sec();
    printf("�׷���....\n\n");
    sleep1sec();
    printf("�ƾ�... ������...\n\n");
    sleep1sec();
    printf("���\n\n");
    sleep1sec();
    printf("GameOver\n");
}

// ���� ���� ȭ�� ���
void showHoldBackAnger() {
    system("cls");
    printf("��....\n\n");
    sleep1sec();
    printf("����.....\n\n");
    sleep1sec();
    printf("���ƾƾƾƾƾ�!!!\n\n");
    sleep1sec();
    printf("���\n\n");
    sleep1sec();
    printf("GameOver\n");
}

// ������ �����ϴ� �Լ�
int main() {
    showIntro();
    return 0;
}