#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>

/*
给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
*/

int expandFromCenter(char *s, int left, int right, int N){
    while(left>=0&&right<N&&s[left]==s[right]){
            left--;
            right++;
        }
    return right-left-1;
}

char *longestPalindrome(char *s){
    int N = strlen(s);              // N 字符串长度
    if(!N) return "";
    int start_p = 0;
    int end_p = 0;        

    for(int i=0;i<N;i++){
        int odd_len = expandFromCenter(s, i, i, N);
        int even_len = expandFromCenter(s, i, i+1, N);
        if(odd_len>end_p-start_p) {
            start_p = i-odd_len/2;
            end_p = i+odd_len/2;
        }
        if(even_len>end_p-start_p){
            start_p = i-even_len/2+1;
            end_p = i+even_len/2;
        }
    }
    *(s+end_p+1) = '\0';
    return s+start_p;
}

int main(int argc, char const *argv[])
{
    char s[1000];
    scanf("%s", s);
    char *res = longestPalindrome(s);
    printf("longest substring is: %s\n", res);
    return 0;
}
