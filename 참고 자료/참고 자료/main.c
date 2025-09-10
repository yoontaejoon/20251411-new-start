#include <stdio.h>

void gotoXY(int x, int y) {
    printf("\033[%d;%dH", y, x);
}

void setTextColor(int color) {
    printf("\033[%dm", color); // 31=����, 32=�ʷ�, 33=���, 37=��� ��
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
    // �ܼ� �ʱ�ȭ (Ŀ�� ��ġ �ʱ�ȭ)
    printf("\033[2J"); // ȭ�� �����
    printf("\033[H");  // Ŀ�� Ȩ ��ġ

    // 10,5 ��ǥ�� ���� ������ ���� �ؽ�Ʈ ���
    gotoXY(10, 5);
    setTextColor(31);  //���ڻ��� ���������� ������.
    startUnderline(); //���� ��Ÿ���� �Ѽ� ���� ��µǴ� �ؽ�Ʈ�� ������ �־�
    printf("Hello, World!"); // "Hello, World!"�� ������ ���� �ؽ�Ʈ�� �����.
    endUnderline();//"Hello, World!"�� ������ ���� �ؽ�Ʈ�� �����
    resetTextColor(); //���ڻ��� �⺻��(��� ��)���� �ʱ�ȭ.

    // 10,7 ��ǥ�� ���� �ʷϻ� �Ϲ� �ؽ�Ʈ ���
    gotoXY(10, 7);
    setTextColor(32);  // �ʷ�
    printf("This is green text.");
    resetTextColor();

    // 10,9 ��ǥ�� ���� ����� ���� �ؽ�Ʈ ��� �� ���� ����
    gotoXY(10, 9);
    setTextColor(33);  // ���
    startUnderline();
    printf("Underlined yellow text");
    endUnderline();
    resetTextColor();

    // Ŀ���� �ؽ�Ʈ �Ʒ��� ��ġ�ϵ��� ����
    gotoXY(0, 12);

    return 0;
}
