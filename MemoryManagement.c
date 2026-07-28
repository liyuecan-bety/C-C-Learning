
/* 内存管理学习代码 
 * 1. 内存分为堆区，栈区，静态区
 * 2. 堆区：由程序员手动申请和释放，使用malloc/free函数
 * 3. 栈区：由编译器自动分配和释放，使用局部变量，函数参数，返回地址，后进先出
 * 4. 静态区：由编译器自动分配和释放，使用全局变量，静态变量，常量，字符串常量，分为数据段，代码段
静态区：
    1. 全局变量：在函数外部定义的变量，作用域为整个文件，生命周期为整个程序运行期间
    2. 静态变量：在函数内部定义的变量，使用static修饰，作用域为函数内部，生命周期为整个程序运行期间，但其作用域仍限于函数内部。每次函数调用时，该变量会保留上一次修改的值。
       用于修饰全局变量或函数时，会将变量或函数的作用域限制在当前文件内，避免与其他文件的同名变量或函数冲突。
    3. 常量：使用const修饰的变量，作用域为整个文件，生命周期为整个程序运行期间
    4. 字符串常量：使用双引号括起来的字符串，作用域为整个文件，生命周期为整个程序运行期间
    5.代码区（Text段）：存放程序代码（机器指令），只读。

动态内存管理
    
    1. malloc函数：用于动态分配内存，返回指向分配内存的指针，分配失败返回NULL 
    void* malloc (size_t size);
    2. free函数：用于释放动态分配的内存，释放后指针仍然指向原来的地址，但该地址的内容可能被覆盖，使用时需要小心
    void free (void* ptr);
    3. realloc函数：用于重新分配内存，返回指向新分配内存的指针，分配失败返回NULL
    void* realloc (void* ptr, size_t size);
    4. calloc函数：用于动态分配内存，并初始化为0，返回指向分配内存的指针，分配失败返回NULL
    void* calloc (size_t num, size_t size);分配num个大小为size的空间
    5. 内存泄漏：程序运行过程中，动态分配的内存没有被释放，导致内存无法被回收，最终导致程序崩溃或系统资源耗尽
    6. 内存越界：访问了未分配的内存或已经释放的内存，导致程序崩溃或系统资源耗尽
    7. 野指针：指针指向了已经释放的内存或未初始化的内存，导致程序崩溃或系统资源耗尽
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//变量声明区
static int global_uninit;//（全局静态变量）
int global_var_un; // 静态区（全局变量）未初始化
int global_var=10; // 静态区（全局变量）初始化

//函数声明区
void example();
void MallocManage();
//void MallocManageErro();
int* resize_array(int* old_array, int old_size, int new_size);

//主函数
int main(){
    
    return 0;
}

//函数定义区


void MallocManage(){
    char* ptr = (char*)malloc(20*sizeof(char));//动态内存分配，ptr在堆区
    if(ptr != NULL ){
        //将“hello”地址中的内容复制到ptr指向的地址中
        strcpy(ptr,"Hello");
        strcpy(ptr,"world");
        printf("%s",ptr);
    }
    free(ptr);
    ptr = NULL;
}

/*

void MallocManageErro(){
    //此处ptr本身是栈区的，但是ptr指向的是常量区“hello”的地址，常量区只能读不能写
    char* ptr = "hello";
    //strcpy（1，2）是将2的地址中的内容复制到1中,
    //此处就是将“world”这个字符串复制到ptr指向的地址中，
    //但是ptr指向的地址在常量区不能够写，所以这样的写法是错误的会报错
    strcpy(ptr,"world");
    printf("%s",ptr);

}
*/


// 实现一个函数，动态扩展数组容量
// 要求：将原数组大小从 old_size 扩展到 new_size
// 返回：新数组指针，并复制旧数据
int* resize_array(int* old_array, int old_size, int new_size){
    if(old_size >= new_size) return old_array;

    int* new_array = (int*)malloc(new_size*sizeof(int));

    if(NULL != new_array){
        for(int i = 0;i < old_size;i++){
            new_array[i] = old_array[i];
        }
    }
    free(old_array);
    return new_array;
    /*
    主函数部分
    int* arr =(int *)malloc(12*sizeof(int));
    for(int j = 0;j < 12;j++){
        arr[j] = j*2;
    }

    arr = resize_array(arr,12,20);
    if(NULL != arr){
        for(int i = 0;i < 11;i++){
            printf("%d\n",arr[i]);
        }
    }  
    free(arr);
    arr = NULL;
    return 0;
    */
}