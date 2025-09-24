#include <stdio.h>
#include <stdlib.h>
#define Key_a 97
#define Key_z 122

int swap(char* a, char* b)
{
    char c;
    c = *a;
    *a = *b;
    *b = c;
}

int main()
{
    char random[Key_z - Key_a + 1];
    char sorted[Key_z - Key_a + 1];

    //�迭 �ʱ�ȭ
    int i = 0;
    for (i = 0; i < Key_z - Key_a + 1; i++)
    {
        random[i] = 0;
    }

    // �����ϰ� ���ĺ� ��ġ
    for (i = 0; i < Key_z - Key_a + 1; i++)
    {
        while (1)
        {
            int rand_index = rand() % (Key_z - Key_a + 1);
            if (random[rand_index] == 0)
            {
                random[rand_index] = (char)(i + Key_a);
                break;
            }
        }
    }

    // ���Ŀ� �迭�� ����
    for (i = 0; i < Key_z - Key_a + 1; i++)
    {
        sorted[i] = random[i];
    }

    // �����ϱ� - ������ ���ҳ��� ���ؼ� ū ���� ���������� ������
    int j;

    // �ܺ� �ݺ���: ��ü �迭�� 25�� ��ȸ (�迭 ũ�� - 1��)
    // �� �� ��ȸ�� ������ ���� ū ���� �ϳ��� �� ���������� Ȯ����
    for (i = 0; i < Key_z - Key_a; i++)
    {
        // ���� �ݺ���: ������ �� ���Ҹ� ���ʴ�� ��
        // i�� �����Ҽ��� �� ������ �پ�� (�̹� ���ĵ� �޺κ��� ����)
        for (j = 0; j < Key_z - Key_a - i; j++)
        {
            // ���� ���Ұ� ������ ���Һ��� ũ�� (ASCII ������ ��)
            if (sorted[j] > sorted[j + 1])
            {
                // swap �Լ��� ȣ���ؼ� �� ������ ��ġ�� �ٲ�
                // ��������� ū ���� ���������� �̵�
                swap(&sorted[j], &sorted[j + 1]);
            }
        }
        // ���� �ݺ����� ������ �̹� ȸ������ ���� ū ���� �� �����ʿ� ����
    }
    // �ܺ� �ݺ����� ������ ��ü �迭�� a~z ������ ���ĵ�

    //------------������� ���� ����------------------------
    printf("\t\tRandom\tSorted\n");
    for (i = 0; i < Key_z - Key_a + 1; i++)
    {
        printf("\t%d\t%c\t%c\n", i, random[i], sorted[i]);
    }

    return 0;
}