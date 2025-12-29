#include <stdio.h>
#include <math.h>

int main(void){
    double x, y;

    printf("실수 x 입력: ");
    scanf("%lf", &x);
    printf("실수 y 입력: ");
    scanf("%lf", &y);

    printf("\n[math.h 함수 예제]\n");
    printf("sqrt(x)   =%.4lf\n", sqrt(x));
    printf("pow(x, y) =%.4lf\n", pow(x,y));
    printf("sin(x)    =%.4lf\n", sin(x));
    printf("cos(x)    =%.4lf\n", cos(x));
    printf("log(x)    =%.4lf\n", log(x));
    printf("fabs(x)   =%.4lf\n", fabs(x));

    return 0;

}