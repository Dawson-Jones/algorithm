class Solution:
    def reverseWords(self, s: str) -> str:
        s = s.strip().split(" ")
        s.reverse()
        s = [i for i in s if i]
        return " ".join(s)
