char findTheDifference(char *s, char *t) {
    char res = 0;
    while (*s != '\0') {
        res ^= *s++;
    }
    while (*t != '\0') {
        res ^= *t++;
    }
    
    return res;
}