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
#define MAXSIZE 100
typedef struct {
    int Num;
    char Name[50];
}Book;
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
Status GetElem(int i,const SqList* L,Book e){
    if(i < 1||i >= L->Length)
        return ERROR;
    else{
        e = L->elem[i-1];
        return OK;
    }
}
//线性表按值顺序查找
Status LocatElem(const SqList* L,Book e){
    for(int i = 0;i <= L->Length-1;i++){
        if(L->elem[i].Num == e.Num)//只能比较结构体的标识符，不能比较结构体
            return i+1;
    }
    return 0;
}
//顺序表插入
Status InsertList_Sq(SqList* L, int n, const Book e){
    if(n >= 1 && n <= L->Length + 1){
        if(L->Length == MAXSIZE)
                return ERROR;
        for(int i = L->Length-1;i >= n-1;i--){
            L->elem[i+1] = L->elem[i];
        }
        L->elem[n-1] = e;
        L->Length += 1;
        return OK;
    }
    return ERROR;
}
//顺序表删除指定元素
Status DeleteElem(SqList* L,int n){
    if(n >= 1 && n < L->Length){
        L->elem[n-1].Num = 0;
        for(int i = n-1;i <= L->Length-1;i++){
            L->elem[i].Num = L->elem[i+1].Num;
        }
        L->Length --;
        return OK;
    }
    return ERROR;
}
//显示顺序表
void ShowList_Sq(const SqList*L){
    if(L->Length == 0 )
        printf("The List is empty");
    else{
        int i = 0;
        for(i = 0;i < L->Length;i++)
            printf("%d ",L->elem[i].Num);
        printf("\n");
        for(int j = 0;j < L->Length;j++)
            printf("%c ",L->elem[j].Name[2]);
        printf("\n");
        printf("The length of list is %d\n",L->Length);
    }
}
//合并两个顺序表，将L2合并到L1
Status MergeList_Sq(SqList* L1, const SqList* L2){
    if(L1->Length == 0 || L2->Length == 0){
        printf("the List is empty");
        return ERROR;
    }
    else if(L1->Length + L2->Length > MAXSIZE){
        printf("Overflow");
        return OVERFLOW;
    }
    else{
        for(int i = 0;i <= L2->Length - 1;i++){
            L1->elem[i+L1->Length] = L2->elem[i];
        }
        L1->Length += L2->Length;
        return OK;
    }

}
//主函数
int main(){
    SqList MyList1;
    Book b1;
    Book b2;
    Book b3;
    Book b4;
    b1.Num = 1;
    b1.Name[2] = 'a';
    b2.Num = 2;
    b2.Name[2] = 'b';
    b3.Num = 3;
    b3.Name[2] = 'c';
    b4.Num = 4;
    b4.Name[2] = 'd';
    SqList MyList2;
    //初始化顺序表
    InitList_Sq(&MyList1);
    InitList_Sq(&MyList2);
    //顺序表插入元素
    InsertList_Sq(&MyList1,1,b1);
    InsertList_Sq(&MyList1,2,b2);
    InsertList_Sq(&MyList1,3,b3);
    InsertList_Sq(&MyList1,4,b4);
    //展示顺序表
    ShowList_Sq(&MyList1);
    //查找顺序表
    int Num = LocatElem(&MyList1,b1);
    printf("%d",Num);
    return 0;
}
