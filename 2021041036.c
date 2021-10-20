학생 정보 출력 프로그램
#include <stdio.h>
struct student {
    char name[20];
    int studentNumber;
    int birth;
};

void main()
{
    struct student arr[10];
    int n = 0;
    int i;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%s", &arr[i].name);
        scanf("%d", &arr[i].studentNumber);
        scanf("%d", &arr[i].birth);
    }
    struct student *p = arr;
    for (i = 0; i < n; i++)
    {
        printf("%s    %10d    %10d\n", (p + i)->name, (p + i)->studentNumber, (p + i)->birth);

    }
}

중첩구조체 문제 #1-1
#include <stdio.h>
void print_average(struct student const *p);

struct subject {
    int math;
    int eng;
};
struct student {
    char name[20];
    int stunumber;
    struct subject score;
};
void main()
{
    int i;
    struct student s[3];
    for (i = 0; i < 3; i++)
    {
        scanf("%s", s[i].name);
        scanf("%d", &s[i].stunumber);
        scanf("%d", &s[i].score.math);
        scanf("%d", &s[i].score.eng);
    }
    print_average(s);
}
void print_average(struct student const *p)
{
    float sum_eng = 0.0;
    float sum_math = 0.0;
 
    for (int i = 0; i < 3; i++)
    {
        sum_eng += p[i].score.eng; //p+i->score.eng
        sum_math += p[i].score.math;

    }
    printf("영어 평균 : %.1f    수학 평균 : %.1f", sum_eng / 3., sum_math /3.);
}