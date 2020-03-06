#include <stdio.h>
struct student
{
    char name[20];
    int age;
    char sex;
    char num[20];
};

int main(void)
{
    struct student stu[3] = {
        {"小红", 22, 'F', "Z1207031"},
        {"小明", 21, 'M', "Z1207035"},
        {"小七", 23, 'F', "Z1207022"}};
    
    //数组名字赋值给指针，表示指针指向数组的第一个元素（即结构体）的地址
    struct student *p = stu;
    for (; p < stu + 3; ++p)
    {
        printf("name:%s; age:%d; sex:%c; num:%s\n", p->name, p->age, p->sex, p->num);
    }
    return 0;
}