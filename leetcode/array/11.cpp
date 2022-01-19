class Solution {
public:
    int maxArea(vector<int>& height) {
        int r = height.size() - 1;
        int l = 0;

        int best = 0;
        while (l < r) {
            int cur = min(height[l], height[r]) * (r - l);
            best = best > cur ? best : cur;
            
            height[l] < height[r] ? l++ : r--;
        }
        
        return best;
    }
};