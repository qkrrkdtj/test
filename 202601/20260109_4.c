#include <stdio.h>

typedef struct {
    double left;
    double right;
} WheelSpeed;

typedef struct {
    double linear;
    double angular;
} RobotSpeed;

RobotSpeed computeSpeed(WheelSpeed, double, double);

int main(void) {
    WheelSpeed ws1;
    RobotSpeed rs1;

    double rad, dis;

    printf("왼쪽 바퀴 속도(rad/s): ");
    scanf("%lf", &ws1.left);
    printf("오른쪽 바퀴 속도(rad/s): ");
    scanf("%lf", &ws1.right);
    printf("바퀴 반지름(m): ");
    scanf("%lf", &rad);
    printf("바퀴 간 거리(m): ");
    scanf("%lf", &dis);

    rs1 = computeSpeed(ws1, rad, dis);

    printf("선속도: %.2lf m/s\n", rs1.linear);
    printf("각속도: %.2lf rad/s\n", rs1.angular);

    return 0;
}

RobotSpeed computeSpeed(WheelSpeed w, double wheel_radius, double wheel_distance) {
    RobotSpeed rs;

    rs.linear = (wheel_radius*(w.right + w.left)) / 2;
    rs.angular = (wheel_radius*(w.right - w.left)) / wheel_distance;

    return rs;
}