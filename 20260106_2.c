#include <stdio.h>

int main(void) {
    int a, b;
    int ra = 0, rb = 0;

    scanf("%d %d", &a, &b);

    ra = (a%10)*100 + ((a/10)%10)*10 + (a/100);
    rb = (a%10)*100 + ((a/10)%10)*10 + (a/100);

    printf("%d", ra > rb ? ra : rb);

    return 0;
}