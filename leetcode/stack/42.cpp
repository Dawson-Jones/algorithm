class Solution {
private:
    int m_res = 0;
public:
    int trap(vector<int>& height) {
        stack<int> stk;
        int btm_h, l_idx, h;
        for (int r_idx = 0; r_idx < height.size(); ++r_idx) {
            while (!stk.empty() && height[stk.top()] < height[r_idx]) {
                btm_h = height[stk.top()];
                stk.pop();
                if (stk.empty())
                    break;
                
                l_idx = stk.top();
                h = min(height[l_idx], height[r_idx]) - btm_h;
                m_res += (r_idx - l_idx - 1) * h;           
            }
            
            stk.push(r_idx);
        }
        
        return m_res;
    }
};
