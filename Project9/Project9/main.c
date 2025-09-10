#include <stdio.h>
#include <stdlib.h> // rand(), srand() �Լ��� ����ϱ� ���� �ʿ��մϴ�.
#include <time.h>   // time() �Լ��� ����ϱ� ���� �ʿ��մϴ�.

int main() {
    // ���� �õ� �ʱ�ȭ: ���α׷� ���� �� �� �� ���� ȣ���մϴ�.
    // time(NULL)�� ���� �ð��� ��ȯ�ϸ�, �̸� �õ�� ����ϸ� ������ ������ �ٸ� ���� ���� ���� �� �ֽ��ϴ�.
    srand(time(NULL));

    printf("���� ���� 5�� ����:\n");

    // 0���� RAND_MAX ������ ���� ���� 5�� ���
    for (int i = 0; i < 5; i++) {
        int random_num = rand();
        printf("%d ", random_num);
    }
    printf("\n\n");

    // Ư�� ���� (��: 1���� 100)�� ���� ���� 5�� ���
    printf("1���� 100 ������ ���� ���� 5�� ����:\n");
    for (int i = 0; i < 5; i++) {
        // (rand() % ������ ����) + ���� ��
        // 1���� 100������ �� 100���� �����̹Ƿ� ������ ������ 100�Դϴ�.
        int random_range = (rand() % 100) + 1;
        printf("%d ", random_range);
    }
    printf("\n\n");

    // Ư�� ���� [min, max]�� ���� ���� ���� �Լ� ����
    printf("10���� 50 ������ ���� ���� 5�� ����:\n");
    int min = 10;
    int max = 50;
    for (int i = 0; i < 5; i++) {
        // (rand() % (max - min + 1)) + min
        int random_min_max = (rand() % (max - min + 1)) + min;
        printf("%d ", random_min_max);
    }
    printf("\n");

    return 0;
}
