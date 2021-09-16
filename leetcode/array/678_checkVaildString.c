bool checkValidString(char * s){
    int left_min = 0;
    int left_max = 0;
    while (*s) {
        if (*s == '(') {
            left_min++;
            left_max++;
        } else if (*s == '*') {
            left_min--;
            left_max++;
        } else {
            left_min--;
            left_max--;
        }
        if (left_max < 0)
            return false;
        if (left_min < 0)
            left_min = 0;
        s++;
        
    }
    
    return left_min == 0;
}
