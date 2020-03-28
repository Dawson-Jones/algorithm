/*
K个鸡蛋, N层楼, 求最坏情况下, 找到F层  (F层是鸡蛋刚好不会碎的那一层)

最坏情况: 
   1. 如果从上面往下, 鸡蛋每次都会破碎, 直到穷尽
   2. 如果从下面往上, 鸡蛋会一直不破, 直到最后一层, 也就是搜索区间穷尽.
*/
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

int calculate(int **dp, int K, int N){
   if(K==1) return N;
   if(N==0) return 0;
   if(dp[K][N]!=0) return dp[K][N];

   int res = ~(1<<31);
   for(int i=1;i<N+1;i++){
      // 没破, up, K个蛋,N-i层 | 破了, down, 从0到i层-1
      int CurToTop = calculate(dp, K, N-i);       // 破了
      int BtmToCur = calculate(dp, K-1, i-1);     // 没破
      int step = CurToTop>BtmToCur?CurToTop:BtmToCur;
      step++;
      res = res<step?res:step;
   }

   dp[K][N] = res;  // 记录
   return res;
}


int superEggDrop(int K, int N){
   int *dp[K];
   for (int i = 0;i<=K;i++){
      int *temp = (int *)malloc(4*N);
      if(temp==NULL) exit(1);
      for (int j = 0;j <= N; j++)
         temp[j] = 0;
      dp[i] = temp;
   }
   int res = calculate(dp, K, N);
   for (int i=0;i<=K;i++)
      free(dp[i]);
   return res;
}

int main(int argc, char const *argv[])
{
   int res = superEggDrop(2, 100);
   printf("%d\n", res);
   return 0;
}
