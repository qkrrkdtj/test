#include "calc.h"

void robot_motor(void){
    double mass, SF, margin, radius, torque, gear;
    int wheels;

    const double g = 9.81;
    const double c = 0.018;

    // 기획 단계에서 선정하는 요소
    printf("-----이동로봇 설계사항-----\n");
    printf("총 하중(kg): ");
    scanf("%lf", &mass);
    printf("구동 바퀴 수: ");
    scanf("%d", &wheels);
    printf("안전계수: ");
    scanf("%lf", &SF);
    printf("설계마진(20%% == 1.2): ");
    scanf("%lf", &margin);

    // 모터 정보
    printf("-----모터 및 바퀴 사양-----\n");
    printf("반지름(m): ");
    scanf("%lf", &radius);
    printf("토크(N*m): ");
    scanf("%lf", &torque);
    printf("감속비: ");
    scanf("%lf", &gear);

    double Fmin = c * g * mass * SF * margin;
    double Fmotor = ( (torque * gear) / radius ) * wheels;

    printf("필요한 최소 견인력: %.2lf N\n", Fmin);
    printf("모터가 낼 수 있는 견인력: %.2lf N\n", Fmotor);

    if ( Fmin <= Fmotor ) printf("판정: 만족");
    else printf("판정: 불만족");
}