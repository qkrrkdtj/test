#include <stdio.h>

int main(void) {
    char s[5][15];
    int i, j;
    int max=0;

    for(i=0; i<5; i++) {
        for(j=0; s[j]!='\0'; j++) {
            scanf("%s", s[i][j]);
        }
        if(i==0) max=j;
        else if(j>max) max=j;
    }

    for(j=0; j<max; j++) {
        for(i=0; i<5; i++) {
            if (s[i][j]=='\0') printf("");
            else printf("%c", s[i][j]);
        }
    }

    return 0;
}