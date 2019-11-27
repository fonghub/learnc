#include <stdio.h>
#include <string.h>

struct books
{
    char name[20];
    int id;
    char subject[20];
    char author[20];
};
void printBook( struct books book);
void printBook_1(struct books *p);

// 结构体作为参数传入函数
void main()
{
    struct books book;
    struct books *p;
    p = &book;
    strcpy(book.name,"tcpl");
    strcpy(book.subject,"c language");
    strcpy(book.author,"kr");
    book.id = 30666;

    // printBook(book);
    printBook(*p);
}

//结构体作为参数
void printBook( struct books book)
{
    printf("book id:%d\n",book.id);
    printf("book name:%s\n",book.name);
    printf("book subject:%s\n",book.subject);
    printf("book author:%s\n",book.author);
}

//结构体指针作为参数
void printBook_1(struct books *p)
{
    printf("book id:%d\n",(*p).id);
    printf("book name:%s\n",(*p).name);
    printf("book subject:%s\n",(*p).subject);
    printf("book author:%s\n",(*p).author);
}
