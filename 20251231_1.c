#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    srand(time(NULL));

    int r1 = rand() % 10;
    int r2 = rand() % 100 + 1;
    int r3 = rand() % 21 - 10;

    printf("1 %d\n", r1);
    printf("2 %d\n", r2);
    printf("3 %d\n", r3);

    return 0;
}