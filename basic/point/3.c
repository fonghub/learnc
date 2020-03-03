#include <stdio.h>

//通过指针修改数组的值
//最后修改被调用函数变量的值
void changeArr(int *p,int n)
{
    for (int i = 0; i < n; i++)
        *(p+i) = *(p+i) + 1;
    
}

//返回字符串长度
int strlen_1(char *c)
{
    int n = 0;
    while (*c != '\0')
    {
        n++;
        c++;
    }
    return n;
}

void main()
{
    int *p;
    int arr[] = {1,3,5,7,9};
    int n=5;
    p = &arr[0];    //把数组的第一个元素地址赋值给指针，指针就可以变量数组

    printf("befort\n");
    for (int i = 0; i < n; i++)
        printf("%d\t",*(p+i));
    printf("\n");

    changeArr(p,n);

    printf("after\n");
    for (int i = 0; i < n; i++)
        printf("%d\t",*(p+i));
    printf("\n");

    char c[] = "Hello w.";
    int leng;
    leng = strlen_1(&c[0]);
    printf("leng=%d",leng);
}