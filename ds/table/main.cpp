#include "list.h"
int main()
{
    SqList *sq;
    ElemType x[6]= {5,8,7,2,4,9};
    CreateList(sq, x, 6);
    DispList(sq);
    return 0;
}