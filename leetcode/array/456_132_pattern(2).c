#include "utils/utilsLib.h"


bool find132pattern(int *arr, size_t size) {
    if (size < 3) return false;
    int s3 = INT32_MIN;
    int stack[size];
    int stk_l = 0;
    for (int i = size-1; i >= 0; --i) {
        if (arr[i] < s3) return true;
        while (stk_l > 0 && arr[i] > stack[stk_l-1]) {
            s3 = stack[--stk_l];
        }
        stack[stk_l++] = arr[i];
    }
    return false;
}

int main() {
    int arr[] = {1,2,3,3,3,4,5,3};
    printf("res: %d\n", find132pattern(arr, sizeof(arr)/ sizeof(int)));
}