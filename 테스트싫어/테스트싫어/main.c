// Windows 환경에서 C 표준 라이브러리 함수 사용 시 발생하는 보안 경고를 무시합니다.
#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>  // 입출력 함수 (printf, scanf, fopen, fprintf 등) 사용을 위해 포함합니다.
#include <stdlib.h> // 문자열을 숫자로 변환하는 함수 (atoi) 사용을 위해 포함합니다.
#include <string.h> // 문자열 처리 함수 (strcpy, strtok, strlen 등) 사용을 위해 포함합니다.

#define MAX_STUDENTS 20 // 프로그램을 처리할 수 있는 최대 학생 수를 20으로 정의합니다.
#define MAX_NAME_LEN 50 // 학생 이름의 최대 글자 수를 50으로 정의합니다.
#define LINE_BUF 256    // 파일을 한 줄씩 읽을 때 사용할 버퍼의 안전한 크기를 256으로 정의합니다.

// 학생 한 명의 정보를 담는 구조체를 정의하고, Student라는 별칭(새로운 이름)을 부여합니다.
typedef struct
{
    char name[MAX_NAME_LEN]; // 학생 이름 (최대 50자)
    int atk;                 // 공격력 (Attack Power)
    int def;                 // 방어력 (Defense Power)
    int hp;                  // 체력 (Health Point)
} Student;

int main(void)
{
    // Student 구조체 배열을 선언합니다. 최대 20명의 학생 데이터를 저장할 수 있습니다.
    Student students[MAX_STUDENTS];
    int count = 0; // 실제로 읽어 들인 학생 수를 세는 변수입니다.

    char buffer[LINE_BUF];  // CSV 파일에서 한 줄을 읽어올 임시 버퍼입니다.
    char id[20];            // 사용자로부터 입력받을 학번을 저장할 변수입니다.
    char name[MAX_NAME_LEN]; // 사용자로부터 입력받을 이름을 저장할 변수입니다.

    // 👇 CSV 파일의 경로를 지정합니다. 이 경로는 사용자의 컴퓨터 환경에 맞게 수정해야 합니다.
    const char* csv_path = "students.csv"; // 예제를 위해 상대 경로로 변경했습니다.
    // (원래 경로: "D:\\20251411-new-start\\테스트싫어\\테스트싫어\\students.csv") 경로만 바꾸면 된다

    printf("학번을 입력하세요: ");
    scanf("%s", id); // 사용자로부터 학번을 입력받아 id 변수에 저장합니다.
    printf("이름을 입력하세요: ");
    scanf("%s", name); // 사용자로부터 이름을 입력받아 name 변수에 저장합니다.

    // -------------------------
    // (2) students.csv 파일 읽기
    // -------------------------
    // "r" 모드(읽기 전용)로 CSV 파일을 엽니다.
    FILE* fp = fopen(csv_path, "r");
    if (fp == NULL) { // 파일 열기에 실패하면 (파일이 없거나 경로가 잘못된 경우)
        perror("students.csv 열기 실패"); // 오류 메시지를 출력합니다.
        return 1;                       // 프로그램을 종료합니다.
    }

    // 파일의 끝(NULL)에 도달할 때까지 파일을 한 줄씩 읽습니다.
    while (fgets(buffer, sizeof(buffer), fp) != NULL)
    {
        // strcspn 함수를 사용하여 버퍼에서 캐리지 리턴(\r)이나 개행 문자(\n)가 처음 나타나는 위치를 찾고,
        // 그 위치에 널 문자(\0)를 넣어 개행 문자를 제거합니다.
        buffer[strcspn(buffer, "\r\n")] = '\0';
        if (strlen(buffer) == 0) continue; // 개행 문자를 제거한 후 길이가 0이면 (빈 줄이면) 건너뜁니다.

        // 👇 파일의 첫 줄이 "이름,공격력,방어력,HP"와 같은 헤더인지 확인하고, 헤더라면 무시합니다.
        if (strstr(buffer, "이름") != NULL) continue;

        // 쉼표(,)를 기준으로 문자열을 분리(토큰화)하기 시작합니다.
        char* token = strtok(buffer, ",");
        if (token == NULL) continue; // 토큰이 없으면 (예: 쉼표 없이 빈 값) 건너뜁니다.
        // 첫 번째 토큰(이름)을 현재 학생의 name 필드에 복사합니다.
        strcpy(students[count].name, token);

        // 다음 토큰들을 가져옵니다 (첫 번째 인수에 NULL을 넣어 이전 호출의 다음 위치부터 탐색).

        // 두 번째 토큰(공격력) 처리
        token = strtok(NULL, ",");
        if (token == NULL) continue;
        // 문자열 형태의 공격력을 정수(int)로 변환하여 atk 필드에 저장합니다.
        students[count].atk = atoi(token);

        // 세 번째 토큰(방어력) 처리
        token = strtok(NULL, ",");
        if (token == NULL) continue;
        // 문자열 형태의 방어력을 정수(int)로 변환하여 def 필드에 저장합니다.
        students[count].def = atoi(token);

        // 네 번째 토큰(HP) 처리
        token = strtok(NULL, ",");
        if (token == NULL) continue;
        // 문자열 형태의 HP를 정수(int)로 변환하여 hp 필드에 저장합니다.
        students[count].hp = atoi(token);

        count++; // 학생 수를 1 증가시킵니다.
        if (count >= MAX_STUDENTS) break; // 최대 학생 수에 도달하면 루프를 종료합니다.
    }
    fclose(fp); // 파일 사용을 마쳤으므로 닫습니다.

    // 분석을 위해 최소 8명의 데이터가 있는지 확인합니다.
    if (count < 8) {
        printf("CSV 데이터가 부족합니다 (최소 8명 필요).\n");
        return 1;
    }

    // -------------------------
    // (3) 데이터 분석 처리 (최대 공격력 찾기)
    // -------------------------
    int max_atk_index = 0; // 가장 공격력이 높은 학생의 인덱스를 저장할 변수를 0으로 초기화합니다.
    for (int i = 1; i < count; i++) {
        // 현재 학생의 공격력(students[i].atk)이 현재까지 최고 공격력(students[max_atk_index].atk)보다 높으면
        if (students[i].atk > students[max_atk_index].atk)
            max_atk_index = i; // 인덱스를 업데이트합니다.
    }

    // 전투에 참여할 학생의 인덱스입니다. 배열은 0부터 시작하므로 3번째는 인덱스 2, 8번째는 인덱스 7입니다.
    int idx3 = 2; // 3번째 학생
    int idx8 = 7; // 8번째 학생

    // -------------------------
    // (4) 전투 규칙 적용 (3번째 학생 vs 8번째 학생)
    // -------------------------
    // 3번째 학생이 8번째 학생에게 가하는 피해량: ATK - DEF. 피해량이 음수일 수 없으므로 0보다 작으면 0으로 설정합니다.
    int dmg3to8 = students[idx3].atk - students[idx8].def;
    if (dmg3to8 < 0) dmg3to8 = 0;

    // 8번째 학생이 3번째 학생에게 가하는 피해량: ATK - DEF.
    int dmg8to3 = students[idx8].atk - students[idx3].def;
    if (dmg8to3 < 0) dmg8to3 = 0;

    char winner[MAX_NAME_LEN]; // 승자의 이름을 저장할 변수입니다.

    // 두 학생 모두 상대방에게 피해를 줄 수 없는 경우 (데미지가 0인 경우)
    if (dmg3to8 == 0 && dmg8to3 == 0) {
        strcpy(winner, "무승부"); // 무승부로 처리합니다.
    }
    // 한 명이라도 피해를 줄 수 있는 경우 (전투 시작)
    else {
        int hp3 = students[idx3].hp; // 3번째 학생의 초기 체력
        int hp8 = students[idx8].hp; // 8번째 학생의 초기 체력

        while (1) { // 무한 루프 (전투가 끝날 때까지 반복)
            hp3 -= dmg8to3; // 3번째 학생은 8번째 학생의 공격력만큼 체력 감소
            hp8 -= dmg3to8; // 8번째 학생은 3번째 학생의 공격력만큼 체력 감소

            // 두 학생 모두 체력이 0 이하가 되면
            if (hp3 <= 0 && hp8 <= 0) {
                strcpy(winner, "무승부"); // 무승부
                break;
            }
            // 3번째 학생만 체력이 0 이하가 되면
            else if (hp3 <= 0) {
                strcpy(winner, students[idx8].name); // 8번째 학생 승리
                break;
            }
            // 8번째 학생만 체력이 0 이하가 되면
            else if (hp8 <= 0) {
                strcpy(winner, students[idx3].name); // 3번째 학생 승리
                break;
            }
        }
    }

    // -------------------------
    // (5) 결과 파일 (Test.txt) 출력
    // -------------------------
    // "w" 모드(쓰기 전용)로 Test.txt 파일을 엽니다. 파일이 이미 있으면 덮어씁니다.
    FILE* out = fopen("Test.txt", "w");
    if (out == NULL) {
        perror("Test.txt 열기 실패"); // 파일 열기에 실패하면 오류 메시지를 출력합니다.
        return 1;
    }

    // 파일에 결과를 출력합니다 (fprintf는 파일에 출력하는 함수입니다).
    fprintf(out, "%s : %s\n", id, name); // 입력받은 학번과 이름
    fprintf(out, "가장 공격력이 높은 사람: %s (ATK=%d)\n",
        students[max_atk_index].name, students[max_atk_index].atk); // 최고 공격력 학생 정보
    fprintf(out, "3번째: %s HP=%d\n", students[idx3].name, students[idx3].hp); // 3번째 학생 정보
    fprintf(out, "8번째: %s HP=%d\n", students[idx8].name, students[idx8].hp); // 8번째 학생 정보

    // 승자를 판별하여 출력합니다.
    if (strcmp(winner, "무승부") == 0)
        fprintf(out, "3번째 vs 8번째 승자: 무승부\n");
    else if (strcmp(winner, students[idx3].name) == 0)
        fprintf(out, "3번째 vs 8번째 승자: %s\n", students[idx3].name);
    else
        fprintf(out, "3번째 vs 8번째 승자: %s\n", students[idx8].name);

    // 마지막 인사말 출력
    fprintf(out, "교수님 시험문제 너무 쉽습니다. 담주에 더 어렵게 내주세요\n");

    fclose(out); // 출력 파일 닫기

    printf("✅ Test.txt 파일 생성 완료!\n"); // 콘솔에 완료 메시지 출력
    return 0;
}