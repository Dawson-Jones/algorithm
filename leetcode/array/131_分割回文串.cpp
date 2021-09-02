#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    vector<vector<string>> partition(string s){
        vector<vector<string>> res;
        vector<string> cur;
        dfs(s, cur, res);
        return res;
    }

    bool isPalindrome(string s){
        return s == string(s.rbegin(), s.rend());
    }

    void dfs(string s, vector<string> &cur, vector<vector<string>> &res){
        if (s == ""){
            res.push_back(cur);
            return;
        }

        for (int i = 1; i <= s.length(); ++i){
            string sub = s.substr(0, i);
            if (isPalindrome(sub)){
                cur.push_back(sub);
                dfs(s.substr(i, s.length() - i), cur, res);
                cur.pop_back();
            }
        }
    }
};