#include<stdio.h>
int maxArea(int* height, int heightSize){
    int left = 0;
    int right = heightSize-1;
    int currentMax = 0;
    while(left!=right){
        int currentArea;
        int length = right-left;
        if(height[left]>height[right]){
            currentArea = height[right]*length;
            right--;
        }else{
            currentArea = height[left]*length;
            left++;
        }
        if(currentArea>currentMax) currentMax = currentArea;
    }
    return currentMax;

}

int main(){
    int array[9] = {1,8,6,2,5,4,8,3,7};
    int res = maxArea(array, 9);
    printf("res: %d\n", res);
}
