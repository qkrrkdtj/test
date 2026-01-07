#include <stdio.h>
#include <string.h>

int main(void) {
    char S[100];
    scanf("%s", S);

    int cnt = 0;

    for (int i = 0; S[i] != '\0'; i++) {

        // dz=
        if (S[i] == 'd' && S[i+1] == 'z' && S[i+2] == '=') {
            cnt++;
            i += 2;
        }
        // c=, s=, z=
        else if ((S[i] == 'c' || S[i] == 's' || S[i] == 'z') && S[i+1] == '=') {
            cnt++;
            i += 1;
        }
        // c-, d-
        else if ((S[i] == 'c' || S[i] == 'd') && S[i+1] == '-') {
            cnt++;
            i += 1;
        }
        // lj, nj
        else if ((S[i] == 'l' || S[i] == 'n') && S[i+1] == 'j') {
            cnt++;
            i += 1;
        }
        // 일반 문자
        else {
            cnt++;
        }
    }

    printf("%d", cnt);
    return 0;
}
