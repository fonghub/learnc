#include <stdio.h>

// 递归输出
// 把整数当作字符串一样输出
int printd(int num)
{
    if (num / 10)
        printd(num/10);
    putchar(num%10+'0');
}
int main()
{
    int num = 123123;
    printd(num);
    return 0;
}