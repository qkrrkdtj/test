#include <stdio.h>
#include <math.h>

double rtd(double x) {
    double temp;
    temp = x * 180.0 / M_PI;

    return temp;
}

double dtr(double x) {
    double temp;
    temp = x * M_PI / 180.0;

    return temp;
}

int main(void) {
    int a;
    double b;
    double result;

    printf("1 radian to degree / 2 degree to radian: ");
    scanf("%d", &a);
    printf("값 입력: ");
    scanf("%lf", &b);

    if(a==1) {
        result = rtd(b);
        printf("%.2lf deg\n", result);
    }
    else if(a==2) {
        result = dtr(b);
        printf("%.2lf rad\n", result);
    }
    else {
        printf("잘못된 입력\n");
        return 1;
    }

    return 0;
}