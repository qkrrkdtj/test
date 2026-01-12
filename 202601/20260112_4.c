#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 1024
#define N 200

typedef struct {
    char ip[SIZE];
    int time;   // hour (0~23)
} TIME_IP;

int main(void) {
    FILE *fp;
    char line[SIZE];
    TIME_IP ti[N];
    char ip_in[SIZE];
    char h[3];
    int cnt[N] = {0};
    int num = 0;

    fp = fopen("fast.log", "r");
    if (fp == NULL) {
        printf("파일 열기 실패\n");
        return 1;
    }

    while (fgets(line, sizeof(line), fp)) {

        /* ---------- 시간 추출 ---------- */
        char *t = strchr(line, '-');
        if (t == NULL) continue;

        strncpy(h, t + 1, 2);
        h[2] = '\0';
        int hour = atoi(h);   // 문자열 → 정수

        /* ---------- IP 추출 ---------- */
        char *arrow = strstr(line, "->");
        if (arrow == NULL) continue;

        char *end = arrow-1;
        while(end > line && *end != ':') end--;
        end-=1;

        char *start = end;
        while(start > line && *start != ' ') start--;
        start+=1;

        int len = end - start+1;
        strncpy(ip_in, start, len);
        ip_in[len] = '\0';

        /* ---------- (시간, IP) 비교 ---------- */
        int flag = 1;
        for (int i = 0; i < num; i++) {
            if (ti[i].time == hour && strcmp(ti[i].ip, ip_in) == 0) {
                cnt[i]++;
                flag = 0;
                break;
            }
        }

        if (flag == 1 && num < N) {
            ti[num].time = hour;
            strcpy(ti[num].ip, ip_in);
            cnt[num] = 1;
            num++;
        }
    }

    fclose(fp);

    /* ---------- 시간대별 최다 IP 출력 ---------- */
    for (int h = 0; h < 24; h++) {
        int max = 0;
        int idx = -1;

        for (int i = 0; i < num; i++) {
            if (ti[i].time == h && cnt[i] > max) {
                max = cnt[i];
                idx = i;
            }
        }

        if (idx != -1) {
            printf("[%2d시]%s(%d회)\n", h, ti[idx].ip, max);
        }
    }

    return 0;
}
