#include <stdio.h>

int main(void) {
    int k;
    int max=0;
    int cnt=0;

    for(int i=0; i<9; i++) {
        scanf("%d", &k);
        if(i==0) {
            max=k;
            cnt = 1;
        }
        else if(max<k) {
            max = k;
            cnt = i+1;
        }
    }

    printf("%d\n%d\n", max, cnt);

    return 0;
}