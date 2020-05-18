/**
示例

[[0,0,1,0,0,0,0,1,0,0,0,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,1,1,0,1,0,0,0,0,0,0,0,0],
 [0,1,0,0,1,1,0,0,1,0,1,0,0],
 [0,1,0,0,1,1,0,0,1,1,1,0,0],
 [0,0,0,0,0,0,0,0,0,0,1,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,0,0,0,0,0,0,1,1,0,0,0,0]]
对于上面这个给定矩阵应返回 6。注意答案不应该是11，因为岛屿只能包含水平或垂直的四个方向的‘1’。

*/

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>

void recursive(int**grid, int x, int y, int *area, int row_len, int col_len){
    grid[x][y] = 0;
    (*area)++;
    int top_x = x-1;
    int btm_x = x+1;
    int left_y = y-1;
    int right_y = y+1;
    if(top_x>=0&&grid[top_x][y]==1)         recursive(grid, top_x, y, area, row_len, col_len);
    if(btm_x<row_len&&grid[btm_x][y]==1)    recursive(grid, btm_x, y, area, row_len, col_len);
    if(left_y>=0&&grid[x][left_y]==1)       recursive(grid, x, left_y, area, row_len, col_len);
    if(right_y<col_len&&grid[x][right_y]==1)recursive(grid, x, right_y, area, row_len, col_len);
}

int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize){
    int maxArea = 0;
    int currentArea = 0;
    for(int i=0;i<gridSize;i++){
        for(int j=0;j<gridColSize[i];j++){
            if(grid[i][j]==1){
                // 递归周围
                recursive(grid, i, j, &currentArea, gridSize, gridColSize[0]);
                maxArea = maxArea>currentArea?maxArea:currentArea;
                currentArea = 0;
            }
        }
    }
    return maxArea;
}


int main(int argc, char const *argv[]){
    int *board[8];
    int a[] = {0,0,1,0,0,0,0,1,0,0,0,0,0};
    int b[] = {0,0,0,0,0,0,0,1,1,1,0,0,0};
    int c[] = {0,1,1,0,1,0,0,0,0,0,0,0,0};
    int d[] = {0,1,0,0,1,1,0,0,1,0,1,0,0};
    int e[] = {0,1,0,0,1,1,0,0,1,1,1,0,0};
    int f[] = {0,0,0,0,0,0,0,0,0,0,1,0,0};
    int g[] = {0,0,0,0,0,0,0,1,1,1,0,0,0};
    int h[] = {0,0,0,0,0,0,0,1,1,0,0,0,0};
    board[0] = a;
    board[1] = b;
    board[2] = c;
    board[3] = d;
    board[4] = e;
    board[5] = f;
    board[6] = g;
    board[7] = h;

    int boardSize[8];
    for(int i = 0;i<8;i++)
        boardSize[i] = 13;
    int res = maxAreaOfIsland(board, 8, boardSize);
    printf("res: %d\n", res);
    return 0;
}
