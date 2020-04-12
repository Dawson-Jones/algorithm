#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 删除堆顶
int heapTopPop(int *heap, int size) {
    if (size == 1) { return heap[0]; }
    int top = *heap;
    heap[0] = heap[size - 1];
    int index = 0;
    int leftSubIndex;
    int rightSubIndex;
    int next;
    while (1) {
        leftSubIndex = (index + 1) * 2 - 1;
        rightSubIndex = leftSubIndex + 1;
        if (rightSubIndex >= size ||
            heap[index] > heap[next = heap[leftSubIndex] > heap[rightSubIndex] ? leftSubIndex : rightSubIndex])
            break;

        swap(&heap[index], &heap[next]);
        index = next;
    }
    return top;
}

// 堆上添加一个元素
void heapAdd(int ele, int *heap, int size) {
    heap[size] = ele;
    int index = size;
    int parentIndex;
    while (parentIndex = (index + 1) / 2 - 1, parentIndex >= 0 && heap[index] > heap[parentIndex]) {
        swap(&heap[index], &heap[parentIndex]);
        index = parentIndex;
    }
}

int cmp(const void *a, const void *b) { return *(int *) b - *(int *) a; }

int main() {
    int array[] = {2, 7, 4, 1, 8, 1};
    int size = sizeof(array) / sizeof(int);
    qsort(array, size, sizeof(int), cmp);  // 排序一个最大堆

    int top = heapTopPop(array, size);
    for (int i = 0; i < size - 1; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    printf("--> %d\n", top);

    heapAdd(5, array, size - 1);
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}