
/* 指针相关操作 */
#include <stdio.h>

/* 函数声明*/
void Adress_point();
void Adress_BitNum(int Mode);
void Adress_pointComputer(int arr[],int size);
void doublePointer();
void ArrayPointer();
void print_f(int (*pf)[3], int x, int y);
/* 主函数 */
int main(){
    
    //数组指针
    int arr[2][3] = { 1,2,3,4,5,6};
	print_f(arr,2,3);
	return 0;
}

/* 函数定义 */

//指针地址与值的获取
void Adress_point(){
    int *intPtr = NULL;
    char *charPtr = NULL;
    float *floatPtr = NULL;
    int intPtr1 = 10;
    char charPtr1 = 'A';
    float floatPtr1 = 3.14;

    intPtr = &intPtr1;
    charPtr = &charPtr1;
    floatPtr = &floatPtr1;

    printf("Address of intPtr1: %p\n", (void*)&intPtr1);
    printf("Number of intPtr: %d\n", *intPtr);
    printf("Address of charPtr1: %p\n", (void*)&charPtr1);
    printf("Number of charPtr: %c\n", *charPtr);
    printf("Address of floatPtr1: %p\n", (void*)&floatPtr1);
    printf("Number of floatPtr1: %.2f\n", floatPtr1);
    printf("Address of intPtr: %p\n", (void*)intPtr);
    printf("Number of *intPtr: %d\n", *intPtr);
    printf("Address of charPtr: %p\n", (void*)charPtr);
    printf("Number of *charPtr: %c\n", *charPtr);
    printf("Address of floatPtr: %p\n", (void*)floatPtr);
    printf("Number of *floatPtr: %.2f\n", *floatPtr);
}
//获取数据类型的字节数
void Adress_BitNum(int Mode){
    switch(Mode){
        case 0:
            printf("Size of int : %zu bytes\n", sizeof(int));
            break;
        case 1:
            printf("Size of char : %zu bytes\n", sizeof(char));
            break;
        case 2:
            printf("Size of float : %zu bytes\n", sizeof(float));
            break;
        case 3:
            printf("Size of double : %zu bytes\n", sizeof(double));
            break;
    }
}

//指针加减法
void Adress_pointComputer(int arr[],int size){
    int *ptr = arr;
    printf("Adress of arr: %p\n", (void*)arr);
    printf("Adress of ptr: %p\n", (void*)ptr);
    printf("Adress of arr+1: %p\n", (void*)(arr + 1));
    printf("Adress of ptr+1: %p\n", (void*)(ptr + 1));
    printf("Adress of arr+2: %p\n", (void*)(arr + 2));
    printf("Adress of ptr+2: %p\n", (void*)(ptr + 2));
}

//双重指针
void doublePointer(){
    int value = 42;
    int *ptr = &value;
    int **doublePtr = &ptr;
    printf("Value: %d\n", value);
    printf("Address of value: %p\n", (void*)&value);
    printf("Value via *ptr: %d\n", *ptr);
    printf("Address of ptr: %p\n", (void*)ptr);
    printf("Adress of &ptr: %p\n", (void*)&ptr);
    printf("Value of **doublePtr: %d\n", **doublePtr);
    printf("Value of *doublePtr: %p\n", (void*)*doublePtr);
    printf("Address of doublePtr: %p\n", (void*)doublePtr);
    printf("Adress of &doublePtr: %p\n", (void*)&doublePtr);
}

//数组指针
//数组指针是数组的指针，指向整个数组，而不是数组的第一个元素。它的类型是指向数组的指针类型。
void ArrayPointer(){
    int arr[5] = {1, 2, 3, 4, 5};
    int (*ptr)[5] = &arr;
    printf("Address of arr: %p\n", (void*)arr);
    printf("Address of ptr: %p\n", (void*)ptr);
    printf("Value of arr[0]: %d\n", arr[0]);
    printf("Value of (*ptr)[0]: %d\n", (*ptr)[0]);
    printf("Value of arr[1]: %d\n", arr[1]);
    printf("Value of (*ptr)[1]: %d\n", (*ptr)[1]);
}

//利用数组指针二维数组打印
void print_f(int (*pf)[3], int x, int y){
	int i, j;
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 3; j++)
		{
            /* pf是指向arr[0][]这一整行（3个int类型，12个字节）,pf+1是指向arr[1][]这一行（12个字节）
             （*pf）是指向arr[0][0]第一行第一列的元素，即指向arr数组的首元素，*（pf+1）是arr[1][0],即第二行的第一列的元素，即第二行的首元素
              (*（pf+1）+j))指向第二行的第j个元素，*（*（pf+1）+j）解引用第二行第j列的元素地址
              */
			printf("%d ", *(*(pf + i) + j));
		}
		printf("\n");
	}
}

