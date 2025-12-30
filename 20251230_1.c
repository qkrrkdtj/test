#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

int clip(int x, int min, int max);

int main(void){
    double m, T_m, g, r, SF, eta, C;
    int N_m;

    const double G = 9.81;

    printf("총 질량 [kg]: ");
    scanf("%lf", &m);
    printf("모터 정격 토크 [N*m]: ");
    scanf("%lf", &T_m);
    printf("구동 모터 수 [개]: ");
    scanf("%d", &N_m);
    printf("감속비: ");
    scanf("%lf", &g);
    printf("구동 효율 [0-1, 90%% = 0.9]: ");
    scanf("%lf", &eta);
    printf("바퀴 반지름 [m]: ");
    scanf("%lf", &r);
    printf("구름 저항 계수 [0.01 - 0.02]: ");
    scanf("%lf", &C);
    printf("안전계수 [>=1]: ");
    scanf("%lf", &SF);

    double T_tot = N_m * T_m * G * eta;
    double F_avail = T_tot / r;
    double mg = m * G;
    double sin_theta = clip((F_avail/SF - C*mg) / mg, 0, 1);

    double theta_rad = asin(sin_theta);
    double theta_deg = theta_rad * 180.0 / M_PI;
    double grade_pct = tan(theta_rad) * 100;

    printf("-------------------------\n");
    printf("총 구동 토크 T_tot: %.2lf N*m\n", T_tot);
    printf("가용 견인력 F_avail: %.2lf N\n", F_avail);
    printf("등판 가능 최대각: %.2lf deg\n", theta_deg);
    printf("등판율(grade): %.2lf %%\n", grade_pct);

    return 0;
}

int clip(int x, int min, int max) {
    if (x < min) return min;
    if (x > max) return max;
    return x;
}