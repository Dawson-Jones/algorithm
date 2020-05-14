#include "utils/utilsLib.h"

int lengthOfLongestSubstring(const char *s) {
    int mem[128];
    memset(mem, 0, sizeof(mem));
    int r = 0;
    int n;  // *s 的 int 类型
    int res = 0;
    int i;
    for (i = 0; s[i] != '\0'; ++i) {
        n = (int) s[i];
        if (!mem[n]) {
            mem[n] = i + 1;
        } else {
            res = res > i - r ? res : i - r;
            int temp = mem[n];
            while (r < temp){
                mem[s[r++]] = 0;
            }
            mem[n] = i + 1;
        }
    }
    return res > i - r ? res : i - r;
}

int main() {
    char *s = "hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyz";
    printf("res: %d", lengthOfLongestSubstring(s));
}