#include <stdio.h>
#define THRESHOLD 500

int black_count(int);
int count(int x, int y);

int main(void){
    int N;
    int label[8];
    int cnt=0;
    int sum_index = 0;
    
    printf("개수: ");
    scanf("%d", &N);


    printf("value = ");

    for(int i = 0; i<N; i++) {
        scanf("%d", &label[i]);
        label[i] = black_count(label[i]);
        cnt = count(label[i], cnt);
        sum_index += i*label[i];
    }

    if(cnt==0) {
        printf("라인없음\n");
        return 1;
    }
    double index_avg = (double)sum_index / cnt;

    printf("label = ");
    for(int i = 0; i<N; i++) {
        printf("%d ", label[i]);
    }
    
    printf("\nblack_count= %d\n", cnt);
    printf("index_avg = %.2lf\n", index_avg);

    return 0;
}

int black_count(int x){
    if(x<THRESHOLD) {
        x = 1;
    }
    else if(x>=THRESHOLD) {
        x = 0;
    }

    return x;
}

int count(int x, int y) {
    if(x==1) {
        return y+1;
    }
    else if(x==0) {
        return y;
    }
}