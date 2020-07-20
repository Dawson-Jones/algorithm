//
// Created by Dawson-Jones on 2020/4/24.
//

#ifndef CTEST_UTILSLIB_H
#define CTEST_UTILSLIB_H

#endif //CTEST_UTILSLIB_H

#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <memory.h>
#include <stdarg.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct ListNode {
    int val;
    struct ListNode *next;
};

int min(int n, ...) {
    va_list ap;
    va_start(ap, n);

    int res = INT32_MAX;
    int temp;
    for (int i = 0; i < n; ++i) {
        temp = va_arg(ap, int);
        res = res < temp ? res : temp;
    }

    va_end(ap);
    return res;
}


int max(int n, ...) {
    va_list ap;
    va_start(ap, n);

    int res = INT32_MIN;
    int temp;
    for (int i = 0; i < n; ++i) {
        temp = va_arg(ap, int);
        res = res > temp ? res : temp;
    }

    va_end(ap);
    return res;
}


