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