class Solution {
private:
    unordered_map<char, vector<int>> map;

    bool match(string s) {
        int last_idx = -1;
        for (auto c: s) {
            if (!map.count(c))
                return false;

            vector<int> idx = map[c];
            for (auto i: idx) {
                if (i > last_idx) {
                    last_idx = i;
                    goto jmp;
                }
            }
            return false;
        jmp:
            ;
        }
        return true;
    }
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        string res = "";
        for (int i = 0; i < s.length(); ++i) {
            map[s[i]].push_back(i);
        }

        sort(dictionary.begin(), dictionary.end(), [&](const string &x, const string &y) -> bool {
            return x.length() > y.length() || x.length() == y.length() && x.compare(y) < 0;
        });
        for (auto str: dictionary) {
            if (match(str)) {
                if (str.length() > res.length())
                    res = str;
            }
        }

        return res;
    }
};

