bool handler_p(char *p) {
    while (*p != '\0') {
        if (*(p + 1) == '*')
            p += 2;
        else
            return false;
    }

    return true;
}


bool isMatch(char *s, char *p) {
    if (!(*s || *p))
        return true;
    if (!*p)
        return false;
    if (!*s)
        return handler_p(p);

    if (*(p + 1) == '*') {
        if (*p == *s || *p == '.')
            return isMatch(s + 1, p)         // '*' 代表了 n
                   || isMatch(s, p + 2);        // '*' 代表了 0
        // ignore '*'
        return isMatch(s, p + 2);
    }

    if (*s == *p || *p == '.')
        return isMatch(s + 1, p + 1);

    return false;
}