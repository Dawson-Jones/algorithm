/*
给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。
设计一个算法来计算你所能获取的最大利润。你最多可以完成 两笔 交易。
注意: 你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

输入: [3,3,5,0,0,3,1,4]
输出: 6
解释: 在第 4 天（股票价格 = 0）的时候买入，在第 6 天（股票价格 = 3）的时候卖出，这笔交易所能获得利润 = 3-0 = 3 。
     随后，在第 7 天（股票价格 = 1）的时候买入，在第 8 天 （股票价格 = 4）的时候卖出，这笔交易所能获得利润 = 4-1 = 3
*/

#include "utils/utilsLib.h"

int maxProfit(int *prices, int pricesSize) {
    if (!(pricesSize) || pricesSize == 1) return 0;

    int cur_min = *prices;
    int most_benefit1 = 0;
    int max1[pricesSize];

    for (int i = 0; i < pricesSize; ++i) {
        if (prices[i] > cur_min)
            most_benefit1 = most_benefit1 > prices[i] - cur_min ? most_benefit1 : prices[i] - cur_min;
        else
            cur_min = prices[i];

        max1[i] = most_benefit1;
    }

    int cur_max = prices[pricesSize - 1];
    int most_benefit2 = 0;
    int max2[pricesSize];

    for (int i = pricesSize - 1; i >= 0; --i) {
        if (prices[i] < cur_max)
            most_benefit2 = most_benefit2 > cur_max - prices[i] ? most_benefit2 : cur_max - prices[i];
        else
            cur_max = prices[i];

        max2[i] = most_benefit2;
    }

    int res = INT32_MIN;
    for (int i = 0; i < pricesSize; ++i)
        res = res > (max1[i] + max2[i]) ? res : (max1[i] + max2[i]);
    return res;
}


int main() {
    int prices[] = {3, 2, 6, 5, 0, 3};
    printf("res: %d\n", maxProfit(prices, 6));
}