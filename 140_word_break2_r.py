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
        str_len = len(s)
        self.recur("", s, wordDict, res, str_len)
        return res

    def recur(self, cur_str: str, rest_str: str, wordDict: list, res: list, size: int):
        for i in range(size):
            head_str: str = rest_str[:i + 1]
            if head_str in wordDict:
                tail_str: str = rest_str[i + 1:]
                if not tail_str:
                    res_str = cur_str + head_str
                    res.append(res_str)
                else:
                    res_str = cur_str + head_str + " "
                    self.recur(res_str, tail_str, wordDict, res, size-i-1)


if __name__ == "__main__":
    # sss = "catsanddog"
    # wordDict = ["cat", "cats", "and", "sand", "dog"]
    sss = "pineapplepenapple"
    wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
    res = Solution().wordBreak(sss, wordDict)
    print("res: ", res)
