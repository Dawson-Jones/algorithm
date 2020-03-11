#include<stdio.h>
#include<stdlib.h>
/**
 * 给第一个小朋友 1 颗糖果，第二个小朋友 2 颗，依此类推，直到给最后一个小朋友 n 颗糖果。
 * 回到队伍的起点，给第一个小朋友 n+1 颗糖果，第二个小朋友 n+2 颗，直到给最后一个小朋友 2*n 颗糖果。
  */

int* distributeCandies(int candies, int num_people, int* returnSize){
    // allocate and init 0
    int *people = (int*)malloc(num_people);
    if(people==0) exit(1);
    for(int i=0;i<num_people;i++)
        people[i] = 0;

    int current_nums = 1;
    int times = 0;
    while(candies>0){
        *people += current_nums;
        candies -=current_nums;
        current_nums++;
        times++;
        people++;
        if(times==num_people){
            people-=times;
            times = 0;
        }        
    }

    // candies 已经是负数了, 把这个负数加到前一个数上
    if(times!=0)
        *(people-1) += candies;
    else
        people[num_people-1] += candies;

    return people;
}
int main(){
    int x = 0;
    int candies = 32;
    int p_nums = 4;
    int *people = distributeCandies(candies,p_nums,&x);
    for(int i = 0;i<p_nums;i++)
        printf("%d\n", people[i]);
    free(people);
    return 0;
}
