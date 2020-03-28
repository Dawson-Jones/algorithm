/*
给定一个单词列表，我们将这个列表编码成一个索引字符串 S 与一个索引列表 A。
例如，如果这个列表是 ["time", "me", "bell"]，
我们就可以将其表示为 S = "time#bell#" 和 indexes = [0, 2, 5]。
对于每一个索引，我们可以通过从字符串 S 中索引的位置开始读取字符串，直到 "#" 结束，来恢复我们之前的单词列表。

输入: words = ["time", "me", "bell"]
输出: 10
说明: S = "time#bell#" ， indexes = [0, 2, 5] 。
 */

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>

int minimumLengthEncoding(char ** words, int wordsSize){
    // every words length
    int words_len[wordsSize];

    for(int i=0; i<wordsSize;i++){
        words_len[i] = strlen(words[i]);
        for(int j=0;j<i;i++){
            if(words_len[j]>)
        }
    }

}