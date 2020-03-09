"""
给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，
判定 s 是否可以被空格拆分为一个或多个在字典中出现的单词。

说明：
拆分时可以重复使用字典中的单词。
你可以假设字典中没有重复的单词。
"""
class Solution:
    # def wordBreak(self, s: str, wordDict: List[str]) -> bool:
    def wordBreak(self, s: str, wordDict: list) -> bool:
        if not s:
            return True
        str_len = len(s)
        for i in range(str_len):
            for j in range(1, str_len+1):
                if s[i:j] in wordDict:
                    return self.wordBreak(s[j:], wordDict)
        return False

        

    
if __name__ == "__main__":
    s = "applepenapple"
    wordDict = ["apple", "pen"]
    s = "catsandog"
    wordDict = ["cats", "dog", "sand", "and", "cat"]
    s = "aaaaaaa"
    wordDict = ["aaaa","aaa"]
    res = Solution().wordBreak(s, wordDict)
    print(res)

