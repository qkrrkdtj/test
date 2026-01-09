#include <stdio.h>
#define N 2
typedef struct {
    int x;
    int y;
} Position;

void move(Position *p, int dx, int dy);

int main(void) {
    Position r1;
    r1.x = 0;
    r1.y = 0;

    for(int i=0; i<N; i++) {
        int dx=0, dy=0;
        scanf("%d%d", &dx, &dy);
        move(&r1, dx, dy);
    }

    printf("로봇 최종 위치: (%d, %d)", r1.x, r1.y);

    return 0;
}

void move(Position *p, int dx, int dy) {
    p->x += dx;
    p->y += dy;
}