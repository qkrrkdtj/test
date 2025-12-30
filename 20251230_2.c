#include <stdio.h>
#include <math.h>

int main(void) {
    double r, W, espL_pct, espR_pct, L;

    printf("바퀴 반지름 [m]: ");
    scanf("%lf", &r);
    printf("트랙 폭 [m]: ");
    scanf("%lf", &W);
    printf("좌 바퀴 오차율 [%%]: ");
    scanf("%lf", &espL_pct);
    printf("우 바퀴 오차율 [%%]: ");
    scanf("%lf", &espR_pct);
    printf("목표 주행거리 [m]:");
    scanf("%lf", &L);

    double espL = espL_pct / 100.0;
    double espR = espR_pct / 100.0;

    double rL = r * ( 1.0 + espL);
    double rR = r * ( 1.0 + espR);

    double Rc = (W / 2.0) * (rL + rR) / (rR - rL);
    double theta_rad = L / Rc;
    double theta_deg = theta_rad * 180.0 / M_PI;
    double drift = Rc * ( 1 - cos(theta_rad));

    printf("\n[결과]\n");
    printf("좌/우 바퀴 반경: %.4lf / %.4lf\n", rL, rR);
    printf("곡률 반경: %.4lf\n", Rc);
    printf("편류각: %.4lf deg\n", theta_deg);
    printf("편류거리: %.4lf m\n", drift);



    return 0;
}