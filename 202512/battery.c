#include "calc.h"

void battery(void){
    double I_load, vel, R, V, C, eta;
    int wheels;

    // 사전 선정 정보 - 모터 측(부하)
    printf("-----사전 선정 정보(모터)-----\n");
    printf("평균전류[A]: ");
    scanf("%lf", &I_load);
    printf("평균속도[km/h]: ");
    scanf("%lf", &vel);
    printf("예비율[0~1]: ");
    scanf("%lf", &R);
    printf("바퀴 수: ");
    scanf("%d", &wheels);

    // 배터리 정보
    printf("-----배터리 정보-----\n");
    printf("공칭전압[v]: ");
    scanf("%lf", &V);
    printf("용량[Ah]: ");
    scanf("%lf", &C);
    printf("시스템 효율 [0~1, 90%% = 0.9]: ");
    scanf("%lf", &eta);

    double E_usable = V * C * eta * ( 1 - R );
    double P = ( ( V * I_load ) / eta ) * wheels;
    double t = E_usable / P;
    double d = vel * t;

    printf("사용 가능 에너지(Wh): %.2lf\n", E_usable);
    printf("소비전력(W): %.2lf\n", P);
    printf("런타임(h): %.2lf\n", t);
    printf("주행거리(km): %.2lf\n", d);
    
    return 0;
}