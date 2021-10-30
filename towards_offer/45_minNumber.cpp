class Solution {
public:
    string minNumber(vector<int>& nums) {
        string x_str, y_str;
        sort(nums.begin(), nums.end(), [&](int &x, int &y){
            x_str = to_string(x);
            y_str = to_string(y);
            return x_str + y_str < y_str + x_str;
        });
        
        string res;
        for (auto num : nums) {
            res += to_string(num);
        }
        return res;
    }
};