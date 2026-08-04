//单链表操作

#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0

typedef int Status;
typedef int ElemType;

//定义链表
typedef struct LNode{
    ElemType data;
    struct LNode* next;//在此处Lnode还未定义，所以要用struct
}LNode,*Linklist;//两个别名，LNode*偏向指向结点的指针，Linklist偏向链表的头部

//初始化链表
Status InitLinklist(Linklist* L){
    *L = (Linklist)malloc(sizeof(LNode));
    //Linklist表示强制类型转换，将malloc输出的void*类型转换成需要的类型
    //sizeof(LNode)中的LNode不能换成*Linklist,
    //因为LNode表示struct Single_link_List类型，*Linklist是表达式，但是Linklist是Struct LNode*类型的，*Linklist不成立
    //sizeof()中的内容只能是类型和表达式
    if(*L == NULL)
        return ERROR;
    (*L)->next = NULL;
    return OK;
}
//判断链表是否为空
int IsEmpty(Linklist* L){
    if((*L)->next == NULL)
        return 1;
    else
        return 0;
}
//单链表的销毁
Status DestoryLinklist(Linklist* L){
    LNode* p;
    while(*L != NULL){
        p = *L;
        *L = (*L)->next;
        free(p);
    }
    return OK;
}
//销毁就是直接将L销毁掉，清空是还保留了链表的表头
//清空单链表
Status ClearLinklist(Linklist* L){
    LNode* p,*q;
    p = (*L)->next;
    while(p != NULL){
        q = p;
        p = p->next;
        free(q);
    }
    (*L)->next = NULL;
    return OK;
}
//求单链表的表长
int GetLength(Linklist* L){
    LNode* p;
    p = (*L)->next;
    int i = 0;
    while(p != NULL){
        i++;
        p = p->next;
    }
    (*L)->data = i;
    return i;
}
//取出单链表中第i个元素
Status LocatElem(Linklist* L,int i,ElemType* e){
    int j = 1;
    LNode *p;
    p = (*L)->next;
    while(p && j < i){
        j++;
        p = p->next;
    }
    if(!p|| j > i)
        return ERROR;
    *e =  p->data;
    return OK;

}
//单链表按值查找，返回LNode
LNode* LacatElem_V_LNode(const Linklist* L,ElemType value){
    LNode* p;
    p = (*L)->next;
    while(p && p->data!=value)
        p = p->next;
    return p;
}
//单链表按值查找，返回元素位置
int LacatElem_v_Index(const Linklist* L,ElemType value){
    int j = 1;
    LNode* p;
    p = (*L)->next;
    while(p && p->data != value){
        j++;
        p = p->next;
    }
    if(!p)
        return 0;
    else
        return j;
}
int main(){

    return 0;
}