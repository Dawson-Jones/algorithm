#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
#include<stdbool.h>

/**
 * 既然有一个数, 是大于1/2的, 那么所有的数, 一对一消耗, 最后剩下的, 一定是众数.
 */ 

int majorityElement(int* nums, int numsSize){
    int key = nums[0];
    int power = 0;
    for(int i=0;i<numsSize;i++){
        if(nums[i] == key)
            power++;
        else
            power--;
        
        if(power<=0)
            key = nums[i+1];
    }
    return key;
}

int main(int argc, char const *argv[]){
    int array[] = {2,2,1,1,1,2,2};
    int res = majorityElement(array, sizeof(array)/sizeof(int));
    printf("res: %d\n", res);
    return 0;
}
