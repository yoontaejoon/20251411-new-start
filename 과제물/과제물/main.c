#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

struct Fish {
    char* name;
    char* talk;
    int answer;
    char* talk_O;
    char* talk_X;
};

int main() {
    srand((unsigned int)time(NULL));  // 랜덤 시드 설정

    struct Fish fishes[5] = {
        {"붕어", "붕어가 묻습니다: 1+1=?\n1) 2\n2) 창문\n3) 0", 1, "정답입니다! 엄청 쉽죠?", "틀렸어요. 너무 어렵게 생각하지 마요."},
        {"잉어", "잉어가 묻습니다: 학생들이 좋아하는 수업은?\n1) 휴강\n2) 종강\n3) 교수님의 풀강의", 2, "정답입니다! ㅎㅎ교수님 제 맘 아시죠?", "틀렸어요. ㅎㅎ 설마요"},
        {"금붕어", "금붕어가 묻습니다: 철수와 영희가 대화하고 있습니다. 이때 철수와 영희는 무슨 대화를 하고 있었을까요?\n1) 교수님 칭찬\n2) 교수님 뒷담\n3) 미영이 남친 얘기", 1, "정답입니다! 역시 교수님이 짱입니닷", "하진 않죠?"},
        {"소", "소가 묻습니다: 소는 어느 부위가 제일 비쌀까요?(1kg 기준)\n1) 채끝살\n2) 안심\n3) 등심", 2, "정답입니다! 안심이 되나요?", "틀렸어요. 그러니 사주세요"},
        {"잠수함", "잠수함 묻습니다: 다음 중 멸종 위기 동물인 것은?\n1) 아프리카 코끼리\n2) 아시아 코끼리\n3) 매머드", 2, "정답입니다! 코끼리를 아껴주세요..", "틀렸어요. 네"}
    };

    char yn;

    while (1) {
        printf("찌를 던진다 (Y/N) > ");
        yn = _getch();
        printf("%c\n", yn);

        if (yn == 'Y' || yn == 'y') {
            printf("찌를 던졌습니다!\n");
            break;
        }
        else if (yn == 'N' || yn == 'n') {
            printf("던지지 않았습니다. 종료합니다.\n");
            return 0;
        }
        else {
            printf("Y 또는 N을 누르세요\n");
            Sleep(1000);
            system("cls");
        }
    }

    // 던진 후 기다리는 연출
    for (int i = 0; i < 5; i++) {
        printf(".");
        Sleep(500);
    }
    printf("\n");

    // 랜덤 물고기 등장
    int fishIndex = rand() % 5;
    struct Fish selected = fishes[fishIndex];

    printf("\n%s를(을) 잡았습니다!\n", selected.name);
    Sleep(1000);

    // 퀴즈 출력
    printf("\n%s\n", selected.talk);
    printf("정답 번호를 입력하세요 (1~3): ");

    int userAnswer;
    scanf_s("%d", &userAnswer);

    // 정답 판별
    if (userAnswer == selected.answer) {
        printf("\n%s\n", selected.talk_O);
    }
    else {
        printf("\n%s\n", selected.talk_X);
    }

    return 0;
}
