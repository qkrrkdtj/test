#include <stdio.h>

int main(void) {
    int a;

    while(a!=0) {
        switch(a) {
            case 1:
            case 2:
            case 3:
            case 4:
            case 0:
                exit(0);
            default:
                return 0;
        }
    }
}