#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    string largestNumber(vector<int> &nums) {
        vector<string> strs;
        for (int num : nums) {
            strs.push_back(to_string(num));
        }

        sort(strs.begin(), strs.end(), [](string &x, string &y) -> bool {
            return x + y > y + x;
        });
        
        if (strs[0] == "0") return "0";
        string res;
        for (auto & str : strs) {
            res += str;
        }
        return res;
    }
};