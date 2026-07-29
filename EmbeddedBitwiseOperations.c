/*位操作
    与（&，&&），或（｜，｜｜），非（～按位取反，！逻辑非），异或（相同为0，相异为1）
    2.2  特定位清零用&
    1.（任何数，其实就是1或者0）与1位与无变化，与0位与变成0。
    举例：假设原来32位寄存器中的值为：0xAAAAAAAA,我们希望将bit8~bit15清零而其他位不变，可以将这个数与0xFFFF00FF进行位与即可。
    2.3  特定位置1用|
    1.（任何数，其实就是1或者0）与1位或变成1，与0位或无变化。
    2.4  特定位取反用^
    1.（任何数，其实就是1或者0）与1位异或会取反，与0位异或无变化

*/

#include<stdio.h>
#include<stdlib.h>
/*函数声明区*/
int* Bitwise(int* a,int* b);
/*主函数*/
int main()
{
    int a = 10;
    int b = 20;
    int *arr = Bitwise(&a,&b);  
    if(arr == NULL){
        printf("内存分配失败");
        return -1;
    }
    for(int i = 0;i < 10;i++)
        printf("arr[%d] = %d\n",i,arr[i]);
    free(arr);
    arr = NULL;
    return 0;
}

/*函数定义区*/

//位操作函数
int* Bitwise(int* a,int* b){
    if(a == NULL||b == NULL)
        return NULL;
    int* arr = (int*)malloc(10*sizeof(int));
    if(NULL == arr) return NULL;
    arr[0] = *a|*b;
    arr[1] = (*a||*b)?1:0;
    arr[2] = *a&*b;
    arr[3] = (*a&&*b)?1:0;
    return arr;//返回的是int*指针