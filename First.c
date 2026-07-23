#include<stdio.h>
int main()
{
    printf("hello");
    int a = 10;
    printf("%d", a);
    int b[] = {1, 2, 3, 4, 5};
    for(int i = 0; i < 5; i++)
    {
        printf("%d", b[i]);
    }
    return 0;
}