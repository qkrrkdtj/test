#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 360

int main(void) {
    double *d;
    int deg;
    double max=0;

    srand(time(NULL));

    int cnt=0;
    int i=0;

    while(cnt<5) {
        d=(double*)malloc(sizeof(double)*N);

        double max = 0;
        int deg = 0;

        d[0] = (double)rand() / RAND_MAX *500.0;
        max=d[0];

        for(int i=1; i<N; i++) {
            d[i] = ((double)rand() / RAND_MAX) * 100.0 + (d[i-1]-50);
            
            if(d[i]<0) d[i]=0;
            
            if(d[i]>max) {
                max=d[i];
                deg=i;
            }
        }

        printf("최댓값: %.2lf\n", max);
        printf("각도: %d\n", deg);

        free(d);
        
        cnt++;

    } 
    return 0;
}