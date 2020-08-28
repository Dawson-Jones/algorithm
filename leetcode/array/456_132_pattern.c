#include "utils/utilsLib.h"

bool find132pattern(int *arr, size_t size) {
    if (size < 3) return false;

    int cur_min = *arr;
    int prev = *arr;

    for (int i = 1; i < size; ++i) {
        if (arr[i] <= prev) {
            cur_min = cur_min < arr[i] ? cur_min : arr[i];
        } else {
            for (int j = i+1; j < size; ++j) {
                if (arr[j] < arr[i] && arr[j] > cur_min)
                    return true;
            }
        }
        prev = arr[i];
    }
    return false;
}

int main() {
    int arr[] = {1,2,3,3,3,4,5,3};
    printf("res: %d\n", find132pattern(arr, sizeof(arr)/ sizeof(int)));
}