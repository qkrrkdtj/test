#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int N, delta;
    int *vel;
    int up_cnt=0;
    int down_cnt=0;


    printf("속도 데이터의 수: ");
    scanf("%d", &N);
    vel = (int*)malloc(sizeof(int)*N);

    srand(time(NULL));

    for(int i=0; i<=N; i++){
        if(i == 0) {
            vel[i]=0;
            up_cnt+=1;
        }
        else {
            if(vel[i]<=0){
                printf("정지\n");
                break;
            }
            else if(i<10) {
                vel[i]=rand()%21+vel[i-1];
                up_cnt+=1;
            }

            else{
                if(up_cnt>=10) {
                    vel[i]=rand()%(41)+vel[i-1]-20;
                    if(vel[i]>vel[i-1]) {
                        up_cnt+=1;
                        down_cnt=0;
                    }
                    else if(vel[i]<vel[i-1]) {
                        printf("------%d번 상승이후 감소------\n", up_cnt);
                        up_cnt=0;
                        down_cnt+=1;
                    }
                    else if(vel[i]==vel[i-1]) {
                        up_cnt=0;
                        down_cnt=0;
                    }
                }
                else if(down_cnt>=10) {
                    vel[i]=rand()%(41)+vel[i-1]-20;
                    if(vel[i]>vel[i-1]) {
                        printf("------%d번 감소 이후 상승------\n", down_cnt);
                        up_cnt+=1;
                        down_cnt=0;
                    }
                    else if(vel[i]<vel[i-1]) {
                        down_cnt+=1;
                        up_cnt=0;
                    }
                }
                else if(up_cnt>=1 && up_cnt<10){
                    vel[i]=rand()%21+vel[i-1];
                    up_cnt++;
                }
                else if(down_cnt>=1 && down_cnt<10){
                    vel[i]=rand()%21+vel[i-1]-20;
                    down_cnt++;
                }
            }    
        
            printf("%d: %d (%d, %d)\n", i, vel[i], up_cnt, down_cnt);
        }
    }

    free(vel);

    return 0;
}