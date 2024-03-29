#include "stdio.h"
#include "string.h"

int lengthOfLongestSubstring(char *s) {
    int st = -1, ed = 0, res = 0;
    char c;
    int map[128];
    memset(map, -1, sizeof(map));
    for (;(c = s[ed]); ++ed) {
        if (map[c] != -1 && map[c] > st) {
            st = map[c];
        }
        map[c] = ed;
        res = ed - st > res ? ed - st : res;
    }
    return res;
}

int main() {
    char *s = "hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyz\n";
    printf("res: %d", lengthOfLongestSubstring(s));
}