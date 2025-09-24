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

int drawFire(int x, int y)
{
	printf("\x1B[%d;%dH*", y, x);
}

int clearPoint(int x, int y)
{
	printf("\x1B[%d;%dH ", y, x);
}

//�Ű����� isExploded
//0: ������ ��ź
//1: ������
void printBomb(int isExploded)
{
	//��ź�� �׻� 7ĭ
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
	// ������� �ڵ带 �ۼ��ϼ���----------------------   
	int posX = 14, posY = 9;
	double angle = 0;
	int length = 0;

	// ���� �׸��� (���� �ڵ�� ����)
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
	//�Ʒ��� ������
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
	//���������� ����
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
	//���� �ø���
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
	//�������� ����
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
	//�Ʒ��� ������
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
	//���������� ����
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
	//���� �ø���
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
	//�������� ����
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
	//�Ʒ��� ������
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
	//���������� ����
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
	//���� �ø���
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

	// ��ź �׸���
	moveCursor(posX - 3, posY - 1);
	printBomb(0);

	Sleep(1000);  // 1�� ���

	// ������ Ÿ�� �ִϸ��̼� (�ٽ� ���� ��θ� ���󰡸鼭)
	posX = 14, posY = 9;
	angle = 0;
	length = 0;

	// �������� �Ҳ�
	moveCursor(posX, posY);
	drawFire(posX, posY);
	Sleep(300);
	clearPoint(posX, posY);

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
		drawFire(posX, posY);
		Sleep(200);
		clearPoint(posX, posY);
		length++;
	}
	//�Ʒ��� ������
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
		drawFire(posX, posY);
		Sleep(200);
		clearPoint(posX, posY);
		length++;
	}
	//���������� ����
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
		drawFire(posX, posY);
		Sleep(200);
		clearPoint(posX, posY);
		length++;
	}
	//���� �ø���
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
		drawFire(posX, posY);
		Sleep(200);
		clearPoint(posX, posY);
		length++;
	}
	//�������� ����
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
		drawFire(posX, posY);
		Sleep(200);
		clearPoint(posX, posY);
		length++;
	}
	//�Ʒ��� ������
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
		drawFire(posX, posY);
		Sleep(200);
		clearPoint(posX, posY);
		length++;
	}
	//���������� ����
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
		drawFire(posX, posY);
		Sleep(200);
		clearPoint(posX, posY);
		length++;
	}
	//���� �ø���
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
		drawFire(posX, posY);
		Sleep(200);
		clearPoint(posX, posY);
		length++;
	}
	//�������� ����
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
		drawFire(posX, posY);
		Sleep(200);
		clearPoint(posX, posY);
		length++;
	}
	//�Ʒ��� ������
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
		drawFire(posX, posY);
		Sleep(200);
		clearPoint(posX, posY);
		length++;
	}
	//���������� ����
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
		drawFire(posX, posY);
		Sleep(200);
		clearPoint(posX, posY);
		length++;
	}
	//���� �ø���
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
		drawFire(posX, posY);
		Sleep(200);
		clearPoint(posX, posY);
		length++;
	}

	// ��ź ����
	Sleep(500);
	moveCursor(posX - 3, posY - 1);
	printBomb(1);

	Sleep(2000);

	// ������� �ڵ带 �ۼ��ϼ���----------------------   
	moveCursor(10, 20);
	return 0;
}