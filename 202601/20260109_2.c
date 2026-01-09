#include <stdio.h>
#include <math.h>

int main(void) {
    int n;
    int k;

    scanf("%d", &n);
    int j=0;
    for(int i=0; i<=n; i++) {
        if(j==0) {
            j = i+1 + i+1;
            k=pow(j, 2);
        }
        else {
            j = j + j-1;
            k = pow(j, 2);
        }
    }

    printf("%d", k);

    return 0;
}