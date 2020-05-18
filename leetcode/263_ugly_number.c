#include<stdio.h>
#define true 1
#define false 0

typedef int bool;

void divided2(int *p){
    while(*p%2==0)
        *p /=2;
}
void divided3(int *p){
    while(*p%3==0)
        *p /=3;
}
void divided5(int *p){
    while(*p%5==0)
        *p /=5;
}

bool isUgly(int num){
    if(num<=0) return false;
    divided2(&num);
    divided3(&num);
    divided5(&num);
    return num==1?true:false;
}

int main(){
    bool res = isUgly(98);
    printf("the res: %d\n", res);
    return 0;
}
