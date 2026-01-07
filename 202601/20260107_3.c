#include <stdio.h>

void assign10(void);
void assign20(void);

int a; // 전역변수는 자동 0으로 초기화

int main(void) {
    printf("호출 전 a: %d\n", a);

    assign10();
    assign20();

    printf("호출 후 a: %d\n", a);

    return 0;
}

void assign10(void) {
    a = 10;
}

void assign20(void) {
    // int a;

    a= 20;
}