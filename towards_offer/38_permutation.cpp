// 没做出来, 需要再看
class Solution {
private:
    vector<string> res;

    void backtrack(string &s, int x) {
        if (x == s.size() - 1) {
            res.push_back(s);
            return;
        }

        set<int> st;
        for (int i = x; i < s.size(); ++i) {
            if (st.find(s[i]) != st.end())
                continue;
            st.insert(s[i]);
            swap(s[i], s[x]);
            backtrack(s, x + 1);
            swap(s[i], s[x]);
        }
    }

public:
    vector<string> permutation(string s) {
        backtrack(s, 0);
        return res;
    }
};