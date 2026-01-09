#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 80

struct profile {
    char name[20];
    int age;
    double height;
    char *intro;
};

int main(void) {
    struct profile yuni;

    strcpy(yuni.name, "서하윤");
    yuni.age=17;
    yuni.height=164.5;

    yuni.intro=(char*)malloc(SIZE);

    if(yuni.intro == NULL) {
        printf("메모리 할당 실패");
        exit(1);
    }
    printf("자기소개 (%d자 이내): ", SIZE/2);
    fgets(yuni.intro, SIZE, stdin);

    printf("이름: %s\n", yuni.name);
    printf("나이: %d\n", yuni.age);
    printf("키: %.1lf\n", yuni.height);
    printf("자기소개: %s\n", yuni.intro);
    free(yuni.intro);

    return 0;
}