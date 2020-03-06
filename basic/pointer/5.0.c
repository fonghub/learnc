#include <stdio.h>
#include <string.h>

struct Age{
    int year;
    int month;
    int day;
};

struct Student
{
    char name[20];
    int num;
    struct Age birthday;
    float score;
};
void set1(struct Student *student)
{
    strcmp((*student).name,"xiaoming");
    (*student).num = 127007;
    (*student).birthday.year = 1995;
    (*student).birthday.month = 3;
    (*student).birthday.day = 22;
    (*student).score = 99;
}
void display1(struct Student *student)
{
    printf("name=%s\n",(*student).name);
    printf("num=%d\n",(*student).num);
    printf("birthday=%d-%d-%d\n",(*student).birthday.year,(*student).birthday.month,(*student).birthday.day);
    printf("score=%.1f\n",(*student).score);
}

void set2(struct Student *student)
{
    strcmp(student->name,"小明");
    student->num = 127007;
    student->birthday.year = 1995;
    student->birthday.month = 3;
    student->birthday.day = 22;
    student->score = 99;
}

void display2(struct Student *student)
{
    printf("name=%s\n",student->name);
    printf("num=%d\n",student->num);
    printf("birthday=%d-%d-%d\n",student->birthday.year,student->birthday.month,student->birthday.day);
    printf("score=%.1f\n",student->score);
}
int main()
{
    struct Student xiaoming;
    struct Student *p;
    //结构体变量赋值给指针，表示指针指向结构体的第一个成员的地址
    p = &xiaoming;
    // set1(p);
    // display1(p);
    set2(p);
    display2(p);
    return 0;
}