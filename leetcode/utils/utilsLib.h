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

struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct ListNode {
    int val;
    struct ListNode *next;
};