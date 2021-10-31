// deque
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0)
            return {};
        deque<int> dq;
        for (int i = 0; i < k; ++i) {
            while (!dq.empty() && nums[i] >= nums[dq.back()])
                dq.pop_back();
            dq.push_back(i);
        }
        vector <int> ans = {nums[dq.front()]};
        for (int i = k; i < n; ++i) {
            while (!dq.empty() && nums[i] >= nums[dq.back()])
                dq.pop_back();

            dq.push_back(i);
            while (dq.front() <= i - k)
                dq.pop_front();

            ans.push_back(nums[dq.front()]);
        }

        return ans;
    }
};