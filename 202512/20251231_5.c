#include <stdio.h>

int main(void){
    int num[10];
    int state = 0;

    for(int i=0; i<10; i++){
        printf("배터리 잔량: ");
        scanf("%d", &num[i]);
    }

    for(int i =0; i<10; i++) {
        if(state==0 && num[i] <=35) {
            state = 1;
        }
        else if (state==1 && num[i] >= 35) {
            state = 0;
        }

        printf("배터리 잔량: %d, 경고 상태: %d\n", num[i], state);

    }
    
    
    return 0;
}