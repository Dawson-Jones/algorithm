#include<stdio.h>

int superEggDrop(int K, int N){  // K个鸡蛋N层楼, 最少需要几步测出来

    // dp[][]表示在 F步,K个鸡蛋的情况下, 可以测试的最大楼层 
    int dp[N+1][K+1];
    /*
    Q: 为什么 int dp[N+1][K+1] 可以表示所有的情况
    A: 在K个鸡蛋N层楼中, 随着K的增加, F的次数逐渐减少
       F最多的时候, 是在 K==1 的时候, 这时找到pivotal floor的F次数是最多的--N
    */
    for(int i=0;i<N+1;i++)
        for(int j=0;j<K+1;j++)
            dp[i][j] = 0;
    
    for(int f=1;f<=N;f++)
        for(int k=1;k<=K;k++){
            dp[f][k] = dp[f-1][k-1] + dp[f-1][k] + 1;
            if(dp[f][k]>=N)
                return f;
        }
    return 0;
}

int main(int argc, char const *argv[])
{
    int res = superEggDrop(2, 100);
    printf("%d\n", res);
    return 0;
}
