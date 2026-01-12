#include <stdio.h>
#include <string.h>

#define SIZE 1024
#define N 100

int main(void) {
    FILE *fp;
    char line[SIZE];
    char ip[N][SIZE];
    char ip_in[SIZE];
    int cnt[N] = {0};
    int num = 0;

    fp = fopen("fast.log", "r");
    if (fp == NULL) {
        printf("파일 열기 실패\n");
        return 1;
    }

    while (fgets(line, sizeof(line), fp)) {
        char *arrow = strstr(line, "->");
        if(arrow==NULL) continue;

        char *end = arrow-1;
        while(end > line && *end != ':') end--;
        end-=1;

        char *start = end;
        while(start > line && *start != ' ') start--;
        start+=1;

        int len = end - start+1;
        strncpy(ip_in, start, len);

        int flag = 1;
        for (int i = 0; i < num; i++) {
            if (strcmp(ip[i], ip_in) == 0) {
                cnt[i]++;
                flag = 0;
                break;
            }
        }

        if (flag == 1 && num < N) {
            strcpy(ip[num], ip_in);
            cnt[num]++;
            num++;
        }
    }

    fclose(fp);

    int max = 0, idx = 0;
    for (int i = 0; i < num; i++) {
        if (cnt[i] > max) {
            max = cnt[i];
            idx = i;
        }
    }

    printf("가장 많이 나온 IP: %s (%d회)\n", ip[idx], max);

    return 0;
}
