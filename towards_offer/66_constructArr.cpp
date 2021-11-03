// B[i] = A[0] * A[1] * ... * A[i-1] * A[i + 1] * ...A[n-1]; 
// 拆分为
// B[i] = 
// A[0] * A[1] * ... * A[i-1] 
// * 
// A[i + 1] * ...A[n-1]; 
// 两个部分

class Solution {
public:
    vector<int> constructArr(vector<int> &a) {
        int len = a.size();
        if (len == 0)
            return {};

        vector<int> b(len, 1);
        for (int i = 1; i < len; ++i) {
            b[i] = b[i - 1] * a[i - 1];
        }

        int tmp = 1;
        for (int i = len - 2; i >= 0; --i) {
            tmp *= a[i + 1];
            b[i] *= tmp;
        }

        return b;
    }
};