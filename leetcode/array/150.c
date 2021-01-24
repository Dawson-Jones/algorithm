#include "utils/utilsLib.h"

typedef struct {
    int *num;
    size_t len;
} rpn_t;

int evalRPN(char ** tokens, int tokensSize){
    int my_nums[tokensSize];

    rpn_t r = { my_nums, 0 };
    for (int i = 0; i < tokensSize; ++i) {
        switch (tokens[i][0]) {
            case '+':
                r.num[r.len-2] = r.num[r.len-2] + r.num[r.len-1];
                r.len = --r.len;
                break;
            case '-':
                if (tokens[i][1] != '\0') {
                    r.num[r.len++] = atoi(tokens[i]);
                } else {
                    r.num[r.len - 2] = r.num[r.len - 2] - r.num[r.len - 1];
                    r.len = --r.len;
                }
                break;
            case '*':
                r.num[r.len-2] = r.num[r.len-2] * r.num[r.len-1];
                r.len = --r.len;
                break;
            case '/':
                r.num[r.len-2] = r.num[r.len-2] / r.num[r.len-1];
                r.len = --r.len;
                break;
            default:
                r.num[r.len++] = atoi(tokens[i]);
                break;
        }
    }

    return *r.num;
}