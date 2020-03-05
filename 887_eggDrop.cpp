#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int superEggDrop(int K, int N) {
        vector<vector<int>> dp(K+1, vector<int>(N+1, 0));
        return helper(dp, K, N);
    }

    int helper(vector<vector<int>>& dp, int K, int N) {
        if (1 == K) return N;
        if (0 == N) return 0;
        if (dp[K][N]!=0) return dp[K][N];

        int res = INT_MAX;
        int l=1, r=N+1; // broken 单调递增（i-1: 随i增，单调递增）；notBroken 单调递减（N-i: 随i增，单调递减）。因此这里可以用二分来求相交点
        while (l < r) {
            int mid = (l+r)/2;
            int broken = helper(dp, K-1, mid-1);
            int notBroken = helper(dp, K, N-mid);

            if (broken > notBroken) {
                r=mid;
                res = min(res, broken+1);
            } else {
                l=mid+1;
                res = min(res, notBroken+1);
            }
        }

        dp[K][N] = res;
        return res;
    }
}