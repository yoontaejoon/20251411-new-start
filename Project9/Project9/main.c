#include <stdio.h>
#include <stdlib.h> // rand(), srand() 함수를 사용하기 위해 필요합니다.
#include <time.h>   // time() 함수를 사용하기 위해 필요합니다.

int main() {
    // 랜덤 시드 초기화: 프로그램 시작 시 딱 한 번만 호출합니다.
    // time(NULL)은 현재 시간을 반환하며, 이를 시드로 사용하면 실행할 때마다 다른 랜덤 값을 얻을 수 있습니다.
    srand(time(NULL));

    printf("랜덤 숫자 5개 생성:\n");

    // 0부터 RAND_MAX 사이의 랜덤 숫자 5개 출력
    for (int i = 0; i < 5; i++) {
        int random_num = rand();
        printf("%d ", random_num);
    }
    printf("\n\n");

    // 특정 범위 (예: 1부터 100)의 랜덤 숫자 5개 출력
    printf("1부터 100 사이의 랜덤 숫자 5개 생성:\n");
    for (int i = 0; i < 5; i++) {
        // (rand() % 범위의 개수) + 시작 값
        // 1부터 100까지는 총 100개의 숫자이므로 범위의 개수는 100입니다.
        int random_range = (rand() % 100) + 1;
        printf("%d ", random_range);
    }
    printf("\n\n");

    // 특정 범위 [min, max]의 랜덤 숫자 생성 함수 예제
    printf("10부터 50 사이의 랜덤 숫자 5개 생성:\n");
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
