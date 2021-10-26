// same as leetcode 121
int maxProfit(int* prices, int pricesSize){
    if (pricesSize == 0)
        return 0;
    int hold = prices[0];
    int cur_max_benefit = 0;
    int cur_benefit;

    for (int i = 1; i < pricesSize; ++i) {
        if ((cur_benefit = prices[i] - hold) > 0)
            cur_max_benefit = cur_benefit > cur_max_benefit ? cur_benefit : cur_max_benefit;
        else
            hold = prices[i];
    }
    return cur_max_benefit;
}