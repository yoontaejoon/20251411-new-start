#include <stdio.h>
#include <math.h>
#include <Windows.h>

#define PI 3.14159226535897

void moveCursor(int x, int y)
{
	printf("\x1b[%d;%dH", y, x);
}

int drawPoint(int x, int y)
{
	printf("\x1B[%d;%dH#", y, x);
}

//매개변수 isExploded
//0: 폭발전 폭탄
//1: 폭발함
void printBomb(int isExploded)
{
	//폭탄은 항상 7칸
	if (isExploded)
	{
		printf("\x1b[A^^^^^^^");
		printf("\x1b[B\x1b[7D!!BAM!!");
		printf("\x1b[B\x1b[7D^^^^^^^");
	}
	else
		printf("(  b  )");
}

int main()
{
	// 여기부터 코드를 작성하세요----------------------   
	int posX = 14, posY = 9;
	double angle = 0;
	int length = 0;

	moveCursor(posX, posY);
	printf("*");


	int y, x;
	y = cos(angle * PI / 180.0);
	if (y)
		length = 0;
	else
		length = 0;
	x = sin(angle * PI / 180.0);
	while (length < 2)
	{
		posX += x;
		posY += y;
		drawPoint(posX, posY);
		length++;
	}
	//아래로 내리기
	x = cos(angle * PI / 180.0);
	if (x)
		length = 0;
	else
		length = 0;
	y = sin(angle * PI / 180.0);
	while (length < 2)
	{
		posX += x;
		posY += y;
		drawPoint(posX, posY);
		length++;
	}
	//오른쪽으로 가기
	x = sin(angle * PI / 180.0);
	if (x)
		length = 0;
	else
		length = 0;
	y = -cos(angle * PI / 180.0);
	while (length < 4)
	{
		posX += x;
		posY += y;
		drawPoint(posX, posY);
		length++;
	}
	//위로 올리기
	y = sin(angle * PI / 180.0);
	if (y)
		length = 0;
	else
		length = 0;
	x = -cos(angle * PI / 180.0);
	while (length < 4)
	{
		posX += x;
		posY += y;
		drawPoint(posX, posY);
		length++;
	}
	//왼쪽으로 가기
	y = cos(angle * PI / 180.0);
	if (y)
		length = 0;
	else
		length = 0;
	x = sin(angle * PI / 180.0);
	while (length < 6)
	{
		posX += x;
		posY += y;
		drawPoint(posX, posY);
		length++;
	}
	//아래로 내리기
	x = cos(angle * PI / 180.0);
	if (x)
		length = 0;
	else
		length = 0;
	y = sin(angle * PI / 180.0);
	while (length < 6)
	{
		posX += x;
		posY += y;
		drawPoint(posX, posY);
		length++;
	}
	//오른쪽으로 가기
	x = sin(angle * PI / 180.0);
	if (x)
		length = 0;
	else
		length = 0;
	y = -cos(angle * PI / 180.0);
	while (length < 8)
	{
		posX += x;
		posY += y;
		drawPoint(posX, posY);
		length++;
	}
	//위로 올리기
	y = sin(angle * PI / 180.0);
	if (y)
		length = 0;
	else
		length = 0;
	x = -cos(angle * PI / 180.0);
	while (length < 8)
	{
		posX += x;
		posY += y;
		drawPoint(posX, posY);
		length++;
	}
	//왼쪽으로 가기
	y = cos(angle * PI / 180.0);
	if (y)
		length = 0;
	else
		length = 0;
	x = sin(angle * PI / 180.0);
	while (length < 10)
	{
		posX += x;
		posY += y;
		drawPoint(posX, posY);
		length++;
	}
	//아래로 내리기
	x = cos(angle * PI / 180.0);
	if (x)
		length = 0;
	else
		length = 0;
	y = sin(angle * PI / 180.0);
	while (length < 10)
	{
		posX += x;
		posY += y;
		drawPoint(posX, posY);
		length++;
	}
	//오른쪽으로 가기
	x = sin(angle * PI / 180.0);
	if (x)
		length = 0;
	else
		length = 0;
	y = -cos(angle * PI / 180.0);
	while (length < 12)
	{
		posX += x;
		posY += y;
		drawPoint(posX, posY);
		length++;
	}
	//위로 올리기
	y = sin(angle * PI / 180.0);
	if (y)
		length = 0;
	else
		length = 0;
	x = -cos(angle * PI / 180.0);
	while (length < 12)
	{
		posX += x;
		posY += y;
		drawPoint(posX, posY);
		length++;
	}
	//왼쪽으로 가기


	angle += 90;



	// 여기까지 코드를 작성하세요----------------------   
	moveCursor(10, 20);
	return 0;
}
