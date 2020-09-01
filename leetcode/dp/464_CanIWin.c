/*
给定一个整数 maxChoosableInteger （整数池中可选择的最大数）和另一个整数 desiredTotal（累计和），判断先出手的玩家是否能稳赢（假设两位玩家游戏时都表现最佳）
你可以假设 maxChoosableInteger 不会大于 20， desiredTotal 不会大于 300。


输入：
maxChoosableInteger = 10
desiredTotal = 11

输出：
false

解释：
无论第一个玩家选择哪个整数，他都会失败。
第一个玩家可以选择从 1 到 10 的整数。
如果第一个玩家选择 1，那么第二个玩家只能选择从 2 到 10 的整数。
第二个玩家可以通过选择整数 10（那么累积和为 11 >= desiredTotal），从而取得胜利.
同样地，第一个玩家选择任意其他整数，第二个玩家都会赢。
*/
#include "utils/utilsLib.h"

bool dfs(int maxChoosableInterger, int desiredTotal, int state, int *dp);

bool canIWin(int maxChoosableInteger, int desiredTotal){
    if (maxChoosableInteger >= desiredTotal) return true;
    if ((1 + maxChoosableInteger) * maxChoosableInteger / 2 < desiredTotal) return false;

    int dp[(1 << maxChoosableInteger) - 1];    // 所有的选取方式的输赢
    memset(dp, -1, sizeof(dp));

    return dfs(maxChoosableInteger, desiredTotal, 0, dp);
}

bool dfs(int maxChoosableInterger, int desiredTotal, int state, int *dp) {
    if (dp[state] != -1) return dp[state];

    for (int i = 1; i <= maxChoosableInterger; ++i) {
       int temp = (1 << (i - 1));
       if (!(temp & state)) {   // 该位未被使用
          if (desiredTotal - i <= 0 || 
              !dfs(maxChoosableInterger, desiredTotal - i, temp | state, dp)) {
              // 这里需要是 ！dfs， 因为接下来是对方选， 对方和我们是相反的
              dp[state] = 1;
              return true;
          }
       }
    }
    
    // 遍历所有都赢不了
    dp[state] = 0;
    return false;
}
