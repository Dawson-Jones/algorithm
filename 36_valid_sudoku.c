/*
判断一个 9x9 的数独是否有效。只需要根据以下规则，验证已经填入的数字是否有效即可。

数字 1-9 在每一行只能出现一次。
数字 1-9 在每一列只能出现一次。
数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。

输入:
[
    ["5","3",".",".","7",".",".",".","."],
    ["6",".",".","1","9","5",".",".","."],
    [".","9","8",".",".",".",".","6","."],
    ["8",".",".",".","6",".",".",".","3"],
    ["4",".",".","8",".","3",".",".","1"],
    ["7",".",".",".","2",".",".",".","6"],
    [".","6",".",".",".",".","2","8","."],
    [".",".",".","4","1","9",".",".","5"],
    [".",".",".",".","8",".",".","7","9"]
]
输出: true
*/

#include <stdio.h>
#include<stdbool.h>
#include<stdlib.h>

bool isValidSudoku(char** board, int boardSize, int* boardColSize){
    int *rows[9];   // |
    int *cols[9];   // -> 一共27个指针, 都是指向不同的 int数组
    int *box[9];    // |
    for(int i = 0;i<3;i++){
        for(int j = 0;j<9;j++){
            int *temp = (int *)calloc(10, 4);
            if(temp==NULL) exit(1);
            switch (i){
            case 0:
                rows[j] = temp;
                break;
            case 1:
                cols[j] = temp;
                break;
            case 2:
                box[j] = temp;
                break;
            default:
                break;
            }
        }
    }

    for (int i = 0; i < boardSize; i++){
        for (int j = 0; j < boardColSize[i]; j++){
            if(board[i][j] == '.')
                continue;
            int cur = board[i][j] - '0';
            rows[i][cur]++;
            cols[j][cur]++;
            box[i/3*3+j/3][cur]++;
            if(rows[i][cur]>1||cols[j][cur]>1||box[i/3*3+j/3][cur]>1){
                for(int i=0;i<9;i++){
                    free(rows[i]);
                    free(cols[i]);
                    free(box[i]);
                }
                return false;
            }
        }
    }
    for(int i=0;i<9;i++){
        free(rows[i]);
        free(cols[i]);
        free(box[i]);
    }
    return true;
}


int main(int argc, char const *argv[]){
    char *board[9];
    char a[] = {'5','3','.','.','7','.','.','.','.'};
    char b[] = {'6','.','.','1','9','5','.','.','.'};
    char c[] = {'.','9','8','.','.','.','.','6','.'};
    char d[] = {'8','.','.','.','6','.','.','.','3'};
    char e[] = {'4','.','.','8','.','3','.','.','1'};
    char f[] = {'7','.','.','.','2','.','.','.','6'};
    char g[] = {'.','6','.','.','.','.','2','8','.'};
    char h[] = {'.','.','.','4','1','9','.','.','5'};
    char i[] = {'.','.','.','.','8','.','.','7','9'};
    board[0] = a;
    board[1] = b;
    board[2] = c;
    board[3] = d;
    board[4] = e;
    board[5] = f;
    board[6] = g;
    board[7] = h;
    board[8] = i;

    int boardSize[9];
    for(int i = 0;i<9;i++)
        boardSize[i] = 9;
    int res = isValidSudoku(board, 9, boardSize);
    res==0?printf("false\n"):printf("true\n");
    return 0;
}
