#include <stdio.h>

int main() {
    int x = 1, y = 1;
    int width = 6, height = 5;

    while (y <= height) 
    {
        x = 1;
        while (x <= width) 
        {
            if (y == 1 || y == height || x == 1 || x == width)
            {
                printf("\x1B[%d;%dH#", y, x);
            }
            x=x+1;
        }
        y=y+1;
    }

    return 0;
}
