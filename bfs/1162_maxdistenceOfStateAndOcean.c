/*
N x N 的（网格） grid，用 0 和 1 标记。0 代表海洋，1 代表陆地，返回该海洋区域到离它最近的陆地区域的距离。
(x0, y0) 和 (x1, y1) 这两个区域之间的距离是 |x0 - x1| + |y0 - y1| 。
如果我们的地图上只有陆地或者海洋，请返回 -1。

输入：[[1,0,1],[0,0,0],[1,0,1]]
输出：2
解释： 
海洋区域 (1, 1) 和所有陆地区域之间的距离都达到最大，最大距离为 2。
*/

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// 超时
int maxDistance(int** grid, int gridSize, int* gridColSize)
{
    int states[gridSize * *gridColSize][2];
    int oceans[gridSize * *gridColSize][2];
    int states_nums = 0;
    int oceans_nums = 0;
    for(int i=0;i<gridSize;i++){
        for(int j=0;j<gridColSize[i];j++){
            if (grid[i][j] == 1){
                states[states_nums][0] = i;
                states[states_nums][1] = j;
                states_nums++;
            }else{
                oceans[oceans_nums][0] = i;
                oceans[oceans_nums][1] = j;
                oceans_nums++;
            }
        }
    }
    if(states_nums == 0 || oceans_nums == 0)
        return -1;

    int res = 0;
    int myabs(int, int);
    for(int i= 0;i<oceans_nums;i++){
        int distence = ~(1<<31);
        for(int j=0;j<states_nums;j++){
            int temp_distence = myabs(oceans[i][0], states[j][0]) + myabs(oceans[i][1], states[j][1]);
            distence = distence<temp_distence?distence:temp_distence;
        }
        res = res>distence?res:distence;
    }
    return res;
}
int myabs(int a, int b){
    return a-b>=0?a-b:b-a;
}

int main(int argc, char const *argv[])
{
    int first[] = {1,0,1};
    int secod[] = {0,0,0};
    int third[] = {1,0,1};
    int *grid[] = {first, secod, third};
    int col[] = {3,3,3};
    int res = maxDistance(grid, 3, col);
    printf("res: %d\n", res);
    return 0;
}
