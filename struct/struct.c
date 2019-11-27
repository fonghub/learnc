#include <stdio.h>
struct student
{
    long int num;
    char name[20];
    char sex;
    char addr[30];
}a = {89031,"Li Lin",'M',"123 Beijing Road"};

void main()
{
    printf("NO.:%ld\nname:%s\nsex:%c\naddress:%s\n",a.num,a.name,a.sex,a.addr);
}