#include <stdio.h>


int main(void) {
    int i, j, k, l;
    int a = 9;
    int b = 4;
    int c;

    for(i=0; i<5; i++) {
        c = a - 2*b;
        for(j=0; j<b; j++) {
            printf(" ");
        }
        for(k=0; k<c; k++){
            printf("*");
        }
        for(l=0; l<b; l++){
            printf(" ");
        }
        printf("\n");
        b-=1;
        if ( b == 0 ) break;
    }


    return 0;
}
