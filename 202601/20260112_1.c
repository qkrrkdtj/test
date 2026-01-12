#include <stdio.h>
#include <string.h>
#define SIZE 100
#define N 1
#define height 5

int main(void) {
    FILE *fp;
    char input[SIZE];
    char str[height][SIZE]={0};
    int cnt[height]={0};
    int num=0;

    fp = fopen("log.txt", "r");
    if(fp==NULL) return 1;

    while(fgets(input, sizeof(input), fp)) {
        int flag = 1;

        if(strncmp(input, "[ERROR]", 7)==0) {
            for(int i=0; i<num; i++) {
                if(strcmp(str[i], input)==0) {
                    cnt[i]++;
                    flag = 0;
                    break;
                }
            }

            if(flag == 1) {
                strcpy(str[num], input);
                cnt[num]++;
                num++;
            }
        }

        
    }

    for(int i=0; i<num; i++) {
        printf("%s %d\n", str[i], cnt[i]);
    }

    fclose(fp);

    return 0;
}