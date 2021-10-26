char* replaceSpace(char* s){
    int len;
    int space = 0;
    for (len = 0; s[len]; ++len) {
        if (s[len] == ' ')
            space++;
    }
    int new_len = len + 2 * space + 1;
    char *res = (char *) calloc(new_len, sizeof(char));
    
    int i = 0, j = 0;
    while (i < new_len && j < len) {
        if (s[j] != ' ')
            res[i++] = s[j++];
        else {
            j++;
            res[i++] = '%';
            res[i++] = '2';
            res[i++] = '0';
        }
    }
    res[i] = '\0';
    return res;
}