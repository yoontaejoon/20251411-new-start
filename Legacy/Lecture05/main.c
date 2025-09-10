#include <stdio.h>

int main() {
    int i = 5, j;

    while (i) 
    {
        j = i;
        while (j - 6) 
        {
            printf("*");
            j = j + 1; 
        }
        printf("\n");
        i = i - 1;
    }

    return 0;
}