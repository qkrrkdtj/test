#include <stdio.h>
#include <string.h>

void scpy(char*, char*);
void sncpy(char*, char*, int);
void scat(char*, char*);
void sncat(char*, char*, int);
int sl(char* ch);
int scmp(char*, char*);
int sncmp(char*, char*, int);

int main(void) {
    
    return 0;
}

void scpy(char* ch1, char* ch2) {
    int i=0;

    while(ch2[i]!='\0') {
        ch1[i] = ch2[i];
        i++;
    }
    ch1[i] = '\0';
}

void sncpy(char* ch1, char* ch2, int n) {
    int i;

    for(i=0; i<n && ch2[i] != '\0'; i++) {
        ch1[i] = ch2[i];
    }
    for(; i<n; i++) {
        ch1[i] = '\0';
    }
}

void scat(char* ch1, char* ch2) {
    int i=0;

    while(ch1[i]!='\0') {
        i++;
    }
    
    int j=0;
    while(ch2[j]!='\0') {
        ch1[i++] = ch2[j++];
    }
    ch1[i] = '\0';
}

void sncat(char* ch1, char* ch2, int n) {
    int i=0;
    while(ch1[i] != '\0') {
        i++;
    }

    int j=0;
    while(j<n && ch2[j] != '\0') {
        ch1[i++]=ch2[j++];
    }
    ch1[i]='\0';
}

int sl(char* ch) {
    int cnt = 0;

    for(int i=0; ch[i] != '\0'; i++) {
        cnt++;
    }

    return cnt;
}

int scmp(char* ch1, char* ch2) {
    int i=0;

    while(ch1[i] != '\0' && ch2[i] != '\0') {
        if(ch1[i] > ch2[i]) {
            return 1;
        }
        else if(ch1[i] <ch2[i]) {
            return -1;
        }
        i++;
    }

    if (ch1[i] == '\0' && ch2[i] == '\0') return 0;
    else if (ch1[i] == '\0') return -1;
    else return 1;
}

int sncmp(char* ch1, char* ch2, int n) {
    int i;

    for(i=0; i<n; i++) {
        if(ch1[i] != ch2[i]) {
            return (ch1[i] > ch2[i] ? 1 : -1);
        }
        if(ch1[i]=='\0'){
            return 0;
        }
        
    }

    return 0;
}