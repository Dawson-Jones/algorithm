"""
给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，
在字符串中增加空格来构建一个句子，使得句子中所有的单词都在词典中。返回所有这些可能的句子。

示例
输入:
s = "catsanddog"
wordDict = ["cat", "cats", "and", "sand", "dog"]
输出:
[
  "cats and dog",
  "cat sand dog"
]
"""


# 超时
class Solution:
    # def wordBreak(self, s: str, wordDict: List[str]) -> List[str]:
    def wordBreak(self, s: str, wordDict: list) -> list:
        res = []
        self.recur(s, wordDict, res, [])
        res = [" ".join(i) for i in res]
        return res
    
    def recur(self, s: str, wordDict: list, res: list, li):
        str_len = len(s)
        for i in range(str_len):
            new_str: str = s[:i+1]
            rest_str: str = s[i+1:]
            if new_str in wordDict:
                current_li = li[:]
                current_li.append(new_str)
                index: int = wordDict.index(new_str)
                self.recur(rest_str, wordDict, res, current_li)
                # new_word_Dict: list = wordDict[:index] + wordDict[index+1:]
                # self.recur(rest_str, new_word_Dict, res, current_li)
                if i+1==str_len:
                    res.append(current_li)


if __name__ == "__main__":
    # s = "catsanddog"
    # wordDict = ["cat", "cats", "and", "sand", "dog"]
    s = "pineapplepenapple"
    wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
    res = Solution().wordBreak(s, wordDict)
    print("res: ", res)


