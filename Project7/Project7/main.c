#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <Windows.h>

int main() {
    clock_t start_time, end_time; // 시간을 저장할 변수를 선언합니다. clock_t 타입은 time.h에 정의되어 있습니다.
    double elapsed_time; // 계산된 시간을 초 단위로 저장할 변수입니다.

    // --- 시간 측정을 시작할 지점 ---
    start_time = clock(); // clock() 함수를 호출하여 현재 CPU 시간을 기록합니다.

    // --- 측정하고자 하는 작업 ---
    // 여기서는 간단한 반복문을 사용하여 시간을 소비하는 작업을 시뮬레이션합니다.
    // 실제 프로그램에서는 파일 입출력, 복잡한 계산, 네트워크 통신 등 다양한 작업이 될 수 있습니다.
    printf("시간 측정을 시작합니다...\n");
    for (long long i = 0; i < 1000000000; i++) {
        // 아무 작업도 하지 않는 빈 반복문입니다.
        // 실제로는 유의미한 코드가 들어갑니다.
    }
    printf("작업이 완료되었습니다.\n");
    // --- 측정하고자 하는 작업 끝 ---

    // --- 시간 측정을 종료할 지점 ---
    end_time = clock(); // 작업이 끝난 후 다시 clock() 함수를 호출하여 CPU 시간을 기록합니다.

    // --- 경과 시간 계산 ---
    // (종료 시간 - 시작 시간)을 CLOCKS_PER_SEC로 나누어 초 단위로 변환합니다.
    // CLOCKS_PER_SEC는 1초당 clock 틱 수를 나타내는 매크로입니다.
    elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    // --- 결과 출력 ---
    printf("작업 실행에 걸린 CPU 시간: %f 초\n", elapsed_time);

    return 0;
}
