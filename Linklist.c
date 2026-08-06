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
    if(!p || j > i)
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
//单链表插入，在第i个结点之前插入一个结点
Status InsertLinklist(Linklist* L,ElemType e,int i){
    LNode* p;
    p = (*L)->next;
    int j = 1;
    while(p && j < i-1){
        j++;
        p = p->next;
    }
    if(!p || j > i-1)
        return ERROR;
    LNode* n;
    n = (LNode*)malloc(sizeof(LNode));
    n->data = e;
    n->next = p->next;
    p->next = n;
    return OK;
}
//单链表删除，删除第i个结点
Status DeleteLinklist(Linklist* L,int i){
    LNode*p,*q;
    p = (*L)->next;
    int j = 1;
    while(p && j < i-1){
        j++;
        p = p->next;
    }
    if(!p || j > i-1)
        return ERROR;
    q = p->next;
    p->next = q->next;
    free(q);
    return OK;
}
//单链表建立，头插法
void CreateLinklist_Head(Linklist* L,int n){
    int i = 0;

    for(i = n;i > 0;i--){
        LNode* p;
        InitLinklist(&p);
        printf("Please input %d the data of the new node p:\n",n-i+1);
        scanf("%d",&p->data);
        p->next = (*L)->next;
        (*L)->next = p;
    }
}
//单链表的建立，尾插法
void CreateLinklist_Tail(Linklist*L,int n){
    int i = 0;
    LNode* r;
    r = *L;
    // 先找到最后一个结点
    while (r->next != NULL) {
        r = r->next;
    }
    for(i = 0;i < n;i++){
        LNode* p;
        InitLinklist(&p);
        printf("Please input %d the data of the new node p:\n",i+1);
        scanf("%d",&p->data);
        r->next = p;
        r = p;
    }
    r->next = NULL;
}
//显示单链表
void ShowLinklist(Linklist* L){
    LNode* p;
    p = (*L)->next;
    while(p != NULL){
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
}
int main(){
    //初始化链表并头插法和尾插法
    Linklist list;
    InitLinklist(&list);
    CreateLinklist_Head(&list,5);
    ShowLinklist(&list);
    CreateLinklist_Tail(&list,5);
    ShowLinklist(&list);
    //展示链表长度
    int length = GetLength(&list);
    printf("The length of the linked list is: %d\n", length);
    //查找链表中第3个元素
    ElemType e;
    if(LocatElem(&list, 3, &e) == OK){
        printf("The 3rd element is: %d\n", e);
    } else {
        printf("Element not found.\n");
    }
    //判断链表是否为空
    if(IsEmpty(&list)){
        printf("The linked list is empty.\n");
    } else {
        printf("The linked list is not empty.\n");
    }
    //按值查找
    ElemType value = 5; // Example value to search for
    LNode* result = LacatElem_V_LNode(&list, value);
    if (result) {
        printf("Element %d found in the linked list.\n", value);
    } else {
        printf("Element %d not found in the linked list.\n", value);
    }
    ElemType valueIndex = 5; // Example value to search for index
    //在第三个位置插入一个元素
    InsertLinklist(&list,valueIndex,3);
    ShowLinklist(&list);
    //删除链表中第三个元素
    DeleteLinklist(&list,3);
    ShowLinklist(&list);
    //销毁链表
    DestoryLinklist(&list);
    return 0;
}