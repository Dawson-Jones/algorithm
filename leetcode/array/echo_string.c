/*
 * 给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
*/

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

typedef int bool;

int helper(char *s, int left, int right){
    while (left>=0){
        if(s[left]!=s[right])
            return 0;
        left--;
        right++;
    }
    return 1;
}

bool isPalindrome(char *s){
    // s中去掉所有非字母和数字
    int travl_p = 0;
    int cur = 0;
    char cur_char;
    // '0' - 48, 'A' - 65, 'a' - 97
    while((cur_char = *(s+travl_p))!='\0'){
        if((cur_char>='0'&&cur_char<='9')||(cur_char>='a'&&cur_char<='z')){
            *(s+cur) = cur_char;
            cur++;
        }
        if(cur_char>='A'&&cur_char<='Z'){
            // 大写转小写
            cur_char += 32;
            *(s+cur) = cur_char;
            cur++;
        }
        travl_p++;
    }
    *(s+cur) = '\0';
    if(*s=='\0')
        return 1;
    int mid = cur / 2;
    // odd
    if (cur%2)
        return helper(s, mid, mid);
    // even
    return helper(s, mid-1, mid);
}

int main(int argc, char const *argv[]){
    char *s = "A man, a plan, a canal: Panama";
    bool res = isPalindrome(s);
    printf("string s: %d", res);
    return 0;
}
