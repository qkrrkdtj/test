#include <stdio.h>
#include <string.h>

#define SIZE 1024

int main(void)
{
    FILE *fp;

    fp=fopen("fast.log", "r");
    if(fp==NULL) {
        printf("파일 열기 실패 ");
        return 1;
    }

    char log[SIZE];
    int cnt=0;

    while(fgets(log, sizeof(log), fp)) {
        if(strstr(log, "Ping")) {
            cnt++;
        }
    }
    
    printf("%d", cnt);

    return 0;
}
