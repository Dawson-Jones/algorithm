/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

// 指针的 sizeof 是固定的, 不能用指针的 sizeof 对数组进行测量
#include<stdio.h>
#include<stdlib.h>
#include <string.h>

int *maxDepthAfterSplit(char *seq, int *returnSize) {
    *returnSize = (int) strlen(seq);
    int *res = (int *) malloc(*returnSize * sizeof(int));
    if (res == 0) exit(1);

    int depth = 0;
    for (int i = 0; seq[i] != '\0'; i++) {
        if (seq[i] == '(') {
            res[i] = ++depth % 2;
        } else {
            res[i] = depth-- % 2;
        }
    }
    return res;
}

int main(int argc, char const *argv[]) {
    char str[] = "((()))";
    int count;
    int *res = maxDepthAfterSplit(str, &count);
    for (int i = 0; i < count; i++)
        printf("%d ", res[i]);

    free(res);
    return 0;
}