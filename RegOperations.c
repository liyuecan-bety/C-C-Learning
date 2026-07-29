/*寄存器模拟操作*/

/*头文件*/
#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
/*变量声明区*/
uint32_t status_reg = 0;
/*函数声明区*/
//reg表示寄存器，pos表示寄存器的某一位
void set_bit(uint32_t *reg,int pos);//设置寄存器用｜
void clear_bit(uint32_t *reg,int pos);//清除寄存器用&
void toggle_bit(uint32_t *reg,int pos);//翻转寄存器用^
uint32_t* read_bit(uint32_t reg);//返回寄存器的值用右移或者&1
void print_bit(uint32_t reg);//用指针打印寄存器

/*主函数*/
int main(){
    status_reg = 10;
    set_bit(&status_reg,0);
    clear_bit(&status_reg,1);
    toggle_bit(&status_reg,2);
    uint32_t* bit = (uint32_t*)malloc(32*sizeof(uint32_t));
    if(NULL == bit){
        printf("内存分配失败\n");
        return -1;
    }
    bit = read_bit(status_reg);
    for(int i = 0;i < 32;i++){
        printf("%d",bit[i]);
    }
    printf("\n");
    free(bit);
    bit = NULL;
    print_bit(status_reg);//用指针打印寄存器

    return 0;
}


/*函数定义区*/
void set_bit(uint32_t* reg,int pos){
    *reg = (*reg)|(1<<pos);
}
void clear_bit(uint32_t* reg,int pos){
    *reg = (*reg)&(~(1<<pos));
}
void toggle_bit(uint32_t* reg,int pos){
    *reg = (*reg)^(1<<pos);
}
uint32_t* read_bit(uint32_t reg){
    uint32_t *bit = (uint32_t *)malloc(32*sizeof(uint32_t));
    if(NULL == bit){
        printf("生成失败");
        return NULL;
    }
    for(int i = 32;i > 0;i--){
        bit[32-i] = (reg >> (i-1)) & 1; 
    }
    return bit;
}
void print_bit(uint32_t reg){
    uint32_t *bit = (uint32_t*)malloc(32*sizeof(uint32_t));
    for(int i = 0;i < 32;i++){
        bit[i] = (reg >> i) & 1;
        printf("%d",bit[31-i]);
    }
}