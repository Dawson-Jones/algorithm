class Solution {
private:
    pair<int, int> expandAroundCenter(string &s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }

        return {left + 1, right - 1};
    }

public:
    string longestPalindrome(string s) {
        int st = 0, ed = 0;
        for (int i = 0; i < s.size(); ++i) {
            auto[l1, r1] = expandAroundCenter(s, i, i);
            auto[l2, r2] = expandAroundCenter(s, i, i + 1);

            if (r1 - l1 > ed - st) {
                st = l1;
                ed = r1;
            }

            if (r2 - l2 > ed - st) {
                st = l2;
                ed = r2;
            }

        }
        return s.substr(st, ed - st + 1);
    }
};