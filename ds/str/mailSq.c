#include <stdio.h>
#include <malloc.h>

#define MaxSize 100             //最多的字符个数
#define True 1
#define False 0

typedef int Bool;
typedef struct
{   char data[MaxSize];         //定义可容纳MaxSize个字符的空间
    int length;                 //标记当前实际串长
} SqString;

void StrAssign(SqString &s,char cstr[]);    //字符串常量cstr赋给串s
void StrCopy(SqString &s,SqString t);   //串t复制给串s
Bool StrEqual(SqString s,SqString t); //判串相等
int StrLength(SqString s);  //求串长
SqString Concat(SqString s,SqString t);  //串连接
SqString SubStr(SqString s,int i,int j); //求子串
SqString InsStr(SqString s1,int i,SqString s2); //串插入
SqString DelStr(SqString s,int i,int j) ;   //串删去
SqString RepStr(SqString s,int i,int j,SqString t);     //串替换
void DispStr(SqString s);   //输出串


int main()
{
    SqString s,s1,s2,s3,s4;
    printf("链串的基本运算如下:\n");
    printf("  (1)建立串s和串s1\n");
    StrAssign(s,"abcdefghijklmn");
    printf("  (2)输出串s:");
    DispStr(s);
    StrAssign(s1,"123");
    printf("  (2)输出串s1:");
    DispStr(s1);
    printf("  (3)串s的长度:%d\n",StrLength(s));
    printf("  (4)在串s的第9个字符位置插入串s1而产生串s2\n");
    s2=InsStr(s,9,s1);
    printf("  (5)输出串s2:");
    DispStr(s2);
    printf("  (6)删除串s第2个字符开始的5个字符而产生串s2\n");
    s2=DelStr(s,2,5);
    printf("  (7)输出串s2:");
    DispStr(s2);
    printf("  (8)将串s第2个字符开始的5个字符替换成串s1而产生串s2\n");
    s2=RepStr(s,2,5,s1);
    printf("  (9)输出串s2:");
    DispStr(s2);
    printf("  (10)提取串s的第2个字符开始的10个字符而产生串s3\n");
    s3=SubStr(s,2,10);
    printf("  (11)输出串s3:");
    DispStr(s3);
    printf("  (12)将串s1和串s2连接起来而产生串s4\n");
    s4=Concat(s1,s2);
    printf("  (13)输出串s4:");
    DispStr(s4);
    return 0;
}
