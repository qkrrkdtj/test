#include <stdio.h>
#include <math.h>

int main(void) {
    char s[10];
    int b;
    int sum = 0;

    scanf("%s%d", s, &b);

    for(int i=0; s[i]!='\0'; i++) {
        if(s[i]>='A' && s[i]<='Z')
            sum=sum+(s[i]-'A'+10)*pow(b, i);
        else
            sum=sum+(s[i]-'0')*pow(b, i);
    }

    printf("%d", sum);

    return 0;
}