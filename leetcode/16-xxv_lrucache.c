#include "utils/utilsLib.h"


typedef struct dl_s dl_t;
struct dl_s {
    int key;
    dl_t *next;
};

typedef struct {
    int len;
    int cap;
    int *values;
    dl_t *first;
    dl_t *last;
} LRUCache;

void trans_to_last(LRUCache *obj, dl_t *cur, int key, int val) {
    if (obj->cap == 1) {
        obj->values[key] = val;
        return;
    };

    dl_t *prev;
    while (cur) {
        if (cur->key == key) {
            if (obj->first == cur) {
                if (cur->next)
                    obj->first = cur->next;
            } else
                if (cur->next)
                    prev->next = cur->next;

            obj->last->next = cur;
            obj->last = cur;
            cur->next = NULL;
            obj->values[key] = val;
            return;
        }

        prev = cur;
        cur = cur->next;
    }
}

LRUCache *lRUCacheCreate(int capacity) {
    LRUCache *lru = (LRUCache *) malloc(sizeof(LRUCache));
    int *values = (int *) calloc(1<<15 , sizeof(int));
    lru->len = 0;
    lru->cap = capacity;
    lru->values = values;
    lru->first = NULL;
    lru->last = NULL;
    return lru;
}

int lRUCacheGet(LRUCache *obj, int key) {
    dl_t *cur = obj->first;
    int res = obj->values[key];
    if (!(cur && res)) return -1;

    trans_to_last(obj, cur, key, res);
    return res;
}

void lRUCachePut(LRUCache *obj, int key, int value) {
    if (obj->values[key]) {     // 已经存在， 替换并放到最后
        trans_to_last(obj, obj->first, key, value);
        return;
    }

    if (obj->len < obj->cap) {
        dl_t *cur = (dl_t *) malloc(sizeof(dl_t));
        if (obj->len == 0) {
            obj->first = cur;
            obj->last = cur;
        } else {
            obj->last->next = cur;
            obj->last = cur;
        }

        cur->key = key;
        cur->next = NULL;
        obj->len++;
        obj->values[key] = value;
    } else {        // 容量满了，替换最少使用的
        dl_t *cur = obj->first;
        obj->values[cur->key] = 0;
        obj->values[key] = value;
        cur->key = key;

        if (obj->cap == 1) return;

        // 替换并放到最后
        obj->first = obj->first->next;
        obj->last->next = cur;
        obj->last = cur;
        cur->next = NULL;
    }
}

void lRUCacheFree(LRUCache *obj) {
    dl_t *cur = obj->first;
    dl_t *next;
    while (cur) {
        next = cur->next;
        free(cur);
        cur = next;
    }
}

int main() {
//    LRUCache *lru = lRUCacheCreate(2);
//    lRUCachePut(lru, 1, 1);
//    lRUCachePut(lru, 2, 2);
//    printf("res: %d\n", lRUCacheGet(lru, 1));
//    lRUCachePut(lru, 3, 3);
//    printf("res: %d\n", lRUCacheGet(lru, 2));
//    lRUCachePut(lru, 4, 4);
//    printf("res: %d\n", lRUCacheGet(lru, 1));
//    printf("res: %d\n", lRUCacheGet(lru, 3));
//    printf("res: %d\n", lRUCacheGet(lru, 4));

//    LRUCache *lru = lRUCacheCreate(1);
//    lRUCachePut(lru, 2, 1);
//    printf("res: %d\n", lRUCacheGet(lru, 2));
//    lRUCachePut(lru, 3, 2);
//    printf("res: %d\n", lRUCacheGet(lru, 2));
//    printf("res: %d\n", lRUCacheGet(lru, 3));

    LRUCache *lru = lRUCacheCreate(3);
    lRUCachePut(lru, 1, 1);
    lRUCachePut(lru, 2, 2);
    lRUCachePut(lru, 3, 3);
    lRUCachePut(lru, 4, 4);
    printf("res: %d\n", lRUCacheGet(lru, 4));
    printf("res: %d\n", lRUCacheGet(lru, 3));
    printf("res: %d\n", lRUCacheGet(lru, 2));
    printf("res: %d\n", lRUCacheGet(lru, 1));
    lRUCachePut(lru, 5, 5);
    printf("res: %d\n", lRUCacheGet(lru, 1));
    printf("res: %d\n", lRUCacheGet(lru, 2));
    printf("res: %d\n", lRUCacheGet(lru, 3));
    printf("res: %d\n", lRUCacheGet(lru, 4));
    printf("res: %d\n", lRUCacheGet(lru, 5));
}