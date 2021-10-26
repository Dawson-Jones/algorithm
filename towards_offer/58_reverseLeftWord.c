char* reverseLeftWords(char* s, int n) {
    int len = strlen(s);
    char *res = (char *) malloc(sizeof(char) * len + 1);

    int pos, i;
    for (i = 0; i < len; ++i) {
        pos = (i + n) % len;
        res[i] = s[pos];
    }

    res[i] = '\0';
    return res;
}