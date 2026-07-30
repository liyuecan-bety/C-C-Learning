//顺序表
#include <stdio.h>
#include <stdlib.h>
//函数结果状态定义
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
//Status 是函数的类型，其值是函数结果状态代码
typedef int Status;

//顺序表定义
typedef struct {
    int Num;
    char Name[50];
}Book;
#define MAXSIZE 100
typedef struct{
    Book* elem;
    int Length;
}SqList;

/*顺序表操作*/
//顺序表初始化
Status InitList_Sq(SqList* L){
    L->elem = (Book*)malloc(MAXSIZE*sizeof(Book));
    if (!L->elem)
        exit(OVERFLOW);
    L->Length = 0;
    return OK;
}
//销毁线性表
void DestoryList_Sq(SqList* L){
    if(L->elem)
        free(L->elem);
    L = NULL;
}
//清空线性表
void ClearList(SqList* L){
    L->Length = 0;
}
//求线性表长度
int GetLength(SqList* L){
    return L->Length;
}
//判断线性表是否为空
Status IsEmpty(SqList* L){
    if(L->Length == 0)
        return TRUE;
    else
        return FALSE;
}
//取线性表中第i个值
Status GetElem()
//主函数
int main(){


    return 0;
}