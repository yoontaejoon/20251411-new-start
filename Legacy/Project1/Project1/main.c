#include <stdio.h>

int main() {
    int year = 2025;
    char grade = 'A';
    char name[] = "원주대";

    // %%d: 실제 %d를 출력하고 싶을 때 사용
    printf("성적: %c 학점 (출력 형식: %%d 사용 예시)\n", grade);

    // 실제 정수 출력
    printf("입학 연도: %d년\n", year);

    // char 배열 출력
    printf("학교 이름: %s\n", name);

    // 개별 문자 출력
    printf("첫 글자만 출력하면? %c\n", name[0]);

    return 0;
}