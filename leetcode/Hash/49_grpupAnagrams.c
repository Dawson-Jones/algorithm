#include "utils/utilsLib.h"

#define matrix_append(matrix, pos, str) \
    matrix.elem[pos].str_arr[matrix.elem[pos].len++] = str

typedef struct hash_s hash_t;;
struct hash_s {
    char *sorted_str;
    int val;

    // avoid hash collision
    hash_t *next;
};

typedef struct {
    char *str_arr[100];
    int len;
} anagram_t;

typedef struct {
    // 第一层的
    anagram_t *elem;
    int len;
} anagrams_t;

int cmp(const void *x, const void *y) {
    return *(char *) x > *(char *) y;
}

char ***groupAnagrams(char **strs, int strsSize, int *returnSize, int **returnColumnSizes) {
    hash_t hash_map[255];
    memset(hash_map, 0, sizeof(hash_t) * 255);
    anagram_t anagrams[100];
    anagrams_t res = {anagrams, 0};

    int i, j, pos;
    for (i = 0; i < strsSize; ++i) {
        j = 0;
        pos = 0;
        while (strs[i][j] != '\0') {
            pos += strs[i][j++];
        }
        pos %= 255;

//        char sorted_str[100];
        char *sorted_str = (char *) malloc(sizeof(char) * 100);
        strcpy(sorted_str, strs[i]);
        qsort(sorted_str, j, sizeof(char), cmp);
        if (!hash_map[pos].sorted_str) {
            hash_map[pos].sorted_str = sorted_str;
            hash_map[pos].val = res.len++;
            matrix_append(res, hash_map[pos].val, strs[i]);
        } else {
            // hash collision
            hash_t *cursor = &hash_map[pos];
            while (strcmp(cursor->sorted_str, sorted_str) != 0) {
                if (!cursor->next) {
                    hash_t temp = {sorted_str, res.len++, 0};
                    cursor->next = &temp;
                }
                cursor = cursor->next;
            }
            matrix_append(res, cursor->val, strs[i]);
        }
    }

    // prepare to return
    char ***real_res = (char ***) malloc(sizeof(char **) * res.len);
    *returnSize = res.len;
    for (i = 0; i < res.len; ++i) {
        char **str_arr = (char **) malloc(sizeof(char *) * res.elem[i].len);
        *returnColumnSizes[i] = res.elem[i].len;
        for (j = 0; j < res.elem[i].len; ++j) {
            str_arr[j] = res.elem[i].str_arr[j];
        }
        real_res[i] = str_arr;
    }

    return real_res;
}

/*
 * 给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。

 * 输入: ["eat", "tea", "tan", "ate", "nat", "bat"]
 * 输出:
 * [
 *  ["ate","eat","tea"],
 *  ["nat","tan"],
 *  ["bat"]
 * ]
*/

// 存在数组越界的可能, leetcode提交不过
int main() {
    int col1;
    int col2;
    int col3;

    int *returnColumnSize[3] = {&col1, &col2, &col3};
    int returnSize;
    char *strs[] = {"eat", "bdt", "tbd", "tea", "ate", "nat", "tan"};
//    char *strs[] = {"eat", "tea", "tan", "ate", "nat", "bat"};
    char ***res = groupAnagrams(strs, 7, &returnSize, returnColumnSize);
    for (int i = 0; i < returnSize; ++i) {
        for (int j = 0; j < *returnColumnSize[i]; ++j) {
            printf("res: %s ---- %d\n", res[i][j], i);
        }
    }
    return 0;
}