#include <stdio.h>

int main(void) {
    char s[5][15]={0};
    int i, j;
    int max=0;

    for(i=0; i<5; i++) {
        scanf("%s", s[i]);
        int len = strlen(s[i]);
        if (len > max) max=len;
    }

    for(j=0; j<max; j++) {
        for(i=0; i<5; i++) {
            if (s[i][j]!=0) printf("%c", s[i][j]);
        }
    }

    return 0;
}