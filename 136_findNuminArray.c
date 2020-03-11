#include<stdio.h>

int singleNumber(int* nums, int numsSize){
    int res = 0;
    int length = numsSize/sizeof(int);
    for(int i=0;i<length;i++)
        res ^= nums[i];
    return res;
}

int main(){
   int array[6] = {4,1,2,1,2};
   int res = singleNumber(array, 6);
   printf("res: %d\n", res);
}
