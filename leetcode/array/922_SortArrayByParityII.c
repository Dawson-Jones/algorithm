/*
给定一个非负整数数组 A， A 中一半整数是奇数，一半整数是偶数。
对数组进行排序，以便当 A[i] 为奇数时，i 也是奇数；当 A[i] 为偶数时， i 也是偶数。
你可以返回任何满足上述条件的数组作为答案。

输入：[4,2,5,7]
输出：[4,5,2,7]
解释：[4,7,2,5]，[2,5,4,7]，[2,7,4,5] 也会被接受。
*/

void swap(int *x, int *y) {
    int t = *x;
    *x = *y;
    *y = t;
}

int *sortArrayByParityII(int *A, int ASize, int *returnSize) {
    if (!ASize) return A;
    *returnSize = ASize;

    int j = 1;
    for (int i = 0; i < ASize; i += 2) {
        if (A[i] % 2) {
            while (A[j] % 2) {
                j += 2;
            }
            swap(A + i, A + j);
        }
    }
    return A;
}