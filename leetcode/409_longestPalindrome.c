/**
给定一个包含大写字母和小写字母的字符串，找到通过这些字母构造成的最长的回文串。
在构造过程中，请注意区分大小写。比如 "Aa" 不能当做一个回文字符串。

输入:
"abccccdd"
输出:
7

解释:
我们可以构造的最长的回文串是"dccaccd", 它的长度是 7。
*/
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>
#define COUNT 54

// COUNT 54 不会冲撞, 但是52会冲撞
// TODO: 如果hash冲撞了, next目前是指向了null, 怎么让next连接到一个新的struct?
// 目前的想法是malloc一块内存, 但是问题是后来我们怎么去释放...难道要记录哪块内存是malloc的?

typedef struct hashmap{
    char c;
    int num;
    struct hashmap *next;
} dict;

void put(char c, dict *bucket){
    if(bucket->c == '\0'){
        bucket->c = c;
        bucket->num= 1;
    }else{
        if(bucket->c == c){
            bucket->num++;
        }else{
            void init(dict *);
            init(bucket->next);
            put(c, bucket->next);
        }
    }
}

void init(dict *bucket){
    bucket->c = '\0';
    bucket->num = 0;
    bucket->next = NULL;
}

int getNumSum(dict *bucket){
    if(bucket==NULL){
        return 0;
    }
    return bucket->num/2*2 + getNumSum(bucket->next);
}

int all_even(dict *bucket){
    if(bucket==NULL) return 0;
    if(bucket->num%2==0){
        return all_even(bucket->next);
    }else{
        return 1;
    }
}

int longestPalindrome(char * s){
    if(*s=='\0') return 0;
    dict alphabet[COUNT];
    // init dict
    for(int i=0;i<COUNT;i++){
        init(&alphabet[i]);
    }

    while (*s!='\0'){
        int positon = *s % COUNT;
        put(*s, &alphabet[positon]);
        s++;
    }

    int res = 0;

    for(int i=0;i<COUNT;i++){
        if(all_even(&alphabet[i])&&res%2==0){
            res += 1;
        }
        res += getNumSum(&alphabet[i]);
    }
    return res;
}

int main(int argc, char const *argv[]){
    char s[1000];
    scanf("%s", s);
    int res = longestPalindrome(s);
    printf("longest substring is: %d\n", res);
    return 0;
}