#include <stdio.h>

int avg(int x, int y) {
    int temp;

    temp = (x + y) / 2;

    return temp;
}

int main(void) {
    int a, b;
    int result;

    printf("x, y: ");
    scanf("%d%d", &a, &b);

    result = avg(a, b);
    printf("%d\n", result);
    
    return 0;
}