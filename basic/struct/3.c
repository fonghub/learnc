# include <stdio.h>
# include <string.h>
struct student
{
    char name[20];
    int age;
    char sex;
    char num[20];
};
void OutputSTU(struct student stu[5]);  //函数声明, 该函数的功能是输出学号最大的学生信息

// 从键盘输入 5 个学生的基本信息，如姓名、年龄、性别、学号，然后将学号最大的学生的基本信息输出到屏幕。
int main()
{
    int i;
    struct student stu[5];
    printf("|name |age |sex |study num|\n");
    for (i=0; i<5; ++i)
    {
        printf("%d:", i+1);
        scanf ("%s%d %c%s", stu[i].name, &stu[i].age, &stu[i].sex, stu[i].num);/*%c前面要加空格, 不然输入时会将空格赋给%c*/
    }
    OutputSTU(stu);
    return 0;
}

void OutputSTU(struct student stu[5])
{
    struct student stumax = stu[0];
    int j;
    for (j=1; j<5; ++j)
    {
        if (strcmp(stumax.num, stu[j].num) < 0)  //strcmp函数的使用
        {
            stumax = stu[j];
        }
    }
    printf("name:%s age:%d sex:%c study num:%s\n", stumax.name, stumax.age, stumax.sex, stumax.num);
}