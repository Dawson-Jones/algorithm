class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        int cur_sum;
        while ((cur_sum = nums[l] + nums[r]) != target) {
            if (cur_sum > target)
                r--;
            else
                l++;
        }
        
        return {nums[l], nums[r]};
    }
};
