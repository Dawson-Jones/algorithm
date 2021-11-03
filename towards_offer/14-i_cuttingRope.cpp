// 贪心, 没啥意思
class Solution {
public:
    int cuttingRope(int n) {
        if (n <= 3)
            return n - 1;
        int a = n / 3;
        int b = n % 3;
        if (b == 0)
            return pow(3, a);
        else if (b == 1)
            return pow(3, a - 1) * 4;
        else // (b == 2)
            return pow(3, a) * 2;
    }
};