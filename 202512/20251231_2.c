#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int N, delta;
    int *vel;
    int up = 0, down = 0;

    printf("속도 데이터의 수: ");
    scanf("%d", &N);
    vel = (int*)malloc(sizeof(4*N));

    for(int i=0; i<N; i++){
        scanf("%d", &vel[i]);
    }

    for(int i=0; i<N; i++){
        delta = vel[i+1] - vel[i];
        if(delta >= 10) up++;
        else if (delta <= -10) down++;
    }

    printf("급가속: %d\n", up);
    printf("급제동: %d\n", down);

    free(vel);

    return 0;
}