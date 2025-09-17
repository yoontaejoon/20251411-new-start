#include <stdio.h>
#include <math.h>
#include <Windows.h>

#define PI 3.14159226535897

int drawPoint(int x, int y)
{
	printf("\x1B[%d;%dH#", y, x);
	return 0;
}

void moveCursor(int x, int y)
{
	printf("\x1b[%d;%dH", y, x);
}


int main()
{
	int posX = 14, posY = 9;
	double angle = 0;
	int length = 0;

	moveCursor(posX, posY);
	printf("*");

	while (angle < 360)
	{
		int y, x;
		y = cos(angle * PI / 180.0);
		if (y)
			length = -2;
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
	}
	angle += 90;
}