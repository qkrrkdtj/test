#include <stdio.h>

int get_num(void);

int main(void){
    int result[10];

    for(int i=0; i<10; i++){
        result[i] = get_num();
    }

    for(int j=0; j<10; j++){
        printf("%d\n", result[j]);
    }

    return 0;
}

int get_num(void){
    int num;
    
    printf("양수 입력: ");
    scanf("%d", &num);

    return num;
}