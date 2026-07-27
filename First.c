//函数指针作为参数传递给函数
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void populate_array(int *array, size_t arraySize, int (*getNextValue)(void))
{
    for (size_t i=0; i<arraySize; i++)
        array[i] = getNextValue();
}

// 获取随机值
int getNextRandomValue(void)
{
    return rand();
}

void Array(char *str1, char *str2, char *str3)
{
    int len;
    strcpy(str3, str1);
    printf("strcpy( str3, str1) :  %s\n", str3);

    /* 连接 str1 和 str2 */
    strcat(str1, str2);
    printf("strcat( str1, str2):   %s\n", str1);

    /* 连接后，str1 的总长度 */
    len = strlen(str1);
    printf("strlen(str1) :  %d\n", len);
}

int main(void)
{
    char str1[14] = "runoob";
    char str2[14] = "google";
    char str3[14];

    int myarray[10];
    Array(str1, str2, str3);
    /* getNextRandomValue 不能加括号，否则无法编译，因为加上括号之后相当于传入此参数时传入了 int , 而不是函数指针*/
    populate_array(myarray, 10, getNextRandomValue);
    for(int i = 0; i < 10; i++) {
        printf("%d ", myarray[i]);
    }
    printf("\n");
    return 0;
}


