#include <stdio.h>
#include <string.h>
#define SUB 3
#define S 5
#define SIZE 20

typedef struct {
    int num;
    char name[SIZE];
    int score[SUB];
    int sum;
    double avg;
    char grade;
} Student;

void scanf_S(Student*);
int sum_S(Student*);
double avg_S(Student*);
char grade_S(Student*);
void printf_S(Student*);
void sort_S(Student*);

int main(void) {
    Student s[S];

    for(int i=0; i<S; i++)
    {
        scanf_S(&s[i]);
        s[i].sum = sum_S(&s[i]);
        s[i].avg = avg_S(&s[i]);
        s[i].grade = grade_S(&s[i]);
    }

    printf("# 정렬 전 데이터...\n");
    printf_S(s);


    sort_S(s);
    printf("# 정렬 후 데이터...\n");
    printf_S(s);


    return 0;
}

void scanf_S(Student *ps) {
    printf("학번: ");
    scanf("%d", &ps->num);
    getchar();
    printf("이름(20자 이내): ");
    fgets(ps->name, SIZE, stdin);
    ps->name[strlen(ps->name)-1] = '\0';
    printf("국어, 영어, 수학 점수(최대: 100 / 초과 시 0점 처리): ");

    for(int i=0; i<SUB; i++) {
        scanf("%d", &ps->score[i]);
        if(ps->score[i] > 100 || ps->score[i] < 0) ps->score[i] = 0;
    }
}

int sum_S(Student *ps) {
    int sum=0;

    for(int i=0; i<SUB; i++) {
        sum += ps->score[i];
    }

    return sum;
}

double avg_S(Student *ps) {
    double avg = 0;

    avg = (double)ps->sum / SUB;

    return avg;
}

char grade_S(Student *ps) {
    if(ps->avg >= 90) return 'A';
    else if(ps->avg >= 80) return 'B';
    else if(ps->avg >= 70) return 'C';
    else return 'F';
}

void printf_S(Student *ps) {
    for(int i=0; i<S; i++) {
        printf("%d ", ps[i].num);
        printf("%s ", ps[i].name);
        for(int j=0; j<SUB; j++) {
            printf("%d ", ps[i].score[j]);
        }
        printf("%d ", ps[i].sum);
        printf("%.1lf ", ps[i].avg);
        printf("%c", ps[i].grade);
        printf("\n");
    }
}

void sort_S(Student *ps) {
    Student temp;

    for(int i=0; i<S-1; i++) {
        for(int j=0; j<S-1-i; j++) {
            if(ps[j].avg < ps[j+1].avg) {
                temp = ps[j];
                ps[j] = ps[j+1];
                ps[j+1] = temp;
            }
        }
    }
}