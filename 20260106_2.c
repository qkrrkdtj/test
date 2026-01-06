#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char *S;
    int* a;
    int N;
    int sum=0;

    scanf("%d ", &N);
    S=(char*)malloc(sizeof(char)*N);
    a=(int*)malloc(sizeof(int)*N);

    for(int i=0; i<N; i++) {
        scanf("%c", &S[i]);
        a[i]=S[i]-48;
        sum+=a[i];
    }

    printf("%d\n", sum);

    free(S);
    free(a);
    return 0;
}