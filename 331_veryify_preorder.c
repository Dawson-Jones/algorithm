#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool isValidSerialization(char *preorder) {
    if (*++preorder == '\0') {
        if (*(preorder - 1) == '#') return true;
        else return false;
    }
    if (*(preorder - 1) == '#' && *(preorder + 1) == '#') return false;
    int slots = 2;
    while (*preorder != '\0') {
        if (!slots) return false;
        switch (*preorder++) {
            case ',':
                break;
            case '#':
                slots--;
                break;
            default:
                slots++;
                while (*preorder != ',' && *preorder != '\0') preorder++;
                break;
        }
    }
    return slots == 0;
}

int main() {
    char *str = "9,3,4,#,#,1,#,#,2,#,6,#,#";
    int res = isValidSerialization(str);
    printf("res: %d", res);
}