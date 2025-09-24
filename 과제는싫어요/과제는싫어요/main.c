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

    //배열 초기화
    int i = 0;
    for (i = 0; i < Key_z - Key_a + 1; i++)
    {
        random[i] = 0;
    }

    // 랜덤하게 알파벳 배치
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

    // 정렬용 배열에 복사
    for (i = 0; i < Key_z - Key_a + 1; i++)
    {
        sorted[i] = random[i];
    }

    // 정렬하기 - 인접한 원소끼리 비교해서 큰 놈을 오른쪽으로 보내기
    int j;

    // 외부 반복문: 전체 배열을 25번 순회 (배열 크기 - 1번)
    // 한 번 순회할 때마다 가장 큰 원소 하나가 맨 오른쪽으로 확정됨
    for (i = 0; i < Key_z - Key_a; i++)
    {
        // 내부 반복문: 인접한 두 원소를 차례대로 비교
        // i가 증가할수록 비교 범위가 줄어듦 (이미 정렬된 뒷부분은 제외)
        for (j = 0; j < Key_z - Key_a - i; j++)
        {
            // 왼쪽 원소가 오른쪽 원소보다 크면 (ASCII 값으로 비교)
            if (sorted[j] > sorted[j + 1])
            {
                // swap 함수를 호출해서 두 원소의 위치를 바꿈
                // 결과적으로 큰 값이 오른쪽으로 이동
                swap(&sorted[j], &sorted[j + 1]);
            }
        }
        // 내부 반복문이 끝나면 이번 회차에서 가장 큰 값이 맨 오른쪽에 도달
    }
    // 외부 반복문이 끝나면 전체 배열이 a~z 순서로 정렬됨

    //------------순서대로 숫자 정렬------------------------
    printf("\t\tRandom\tSorted\n");
    for (i = 0; i < Key_z - Key_a + 1; i++)
    {
        printf("\t%d\t%c\t%c\n", i, random[i], sorted[i]);
    }

    return 0;
}