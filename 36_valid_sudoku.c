#include <stdio.h>

int isValidSudoku(char **board, int boardSize)
{

    for (int i = 0; i < boardSize; i++)
    {
        int nums1[10];
        for (int i = 0; i < 10; i++)
            nums1[i] = 0;

        int nums2[10];
        for (int i = 0; i < 10; i++)
            nums2[i] = 0;

        for (int j = 0; i < 9; j++)
        {
            if (board[i][j] != '.')
            {
                int current = board[i][j] - '0';
                nums1[current]++;
                if (nums1[current] > 1)
                {
                    return 0;
                }
            }
            if (board[j][i] != '.')
            {
                int current = board[j][i] - '0';
                nums2[current]++;
                if (nums2[current] > 1)
                {
                    return 0;
                }
            }
        }
    }
    int current_row = 0;
    while (current_row < 9)
    {
        int current_col = 0;
        int i = 0;
        for (i; i < current_row + 3; i++)
        {
            while (current_col < 9)
            {
                int nums[10];
                for (int i = 0; i < 10; i++)
                    nums[i] = 0;

                int j = 0;
                for (j; j < current_col + 3; j++)
                {
                    if (board[i][j] != '.')
                    {
                        int current = board[i][j] - '0';
                        nums[current]++;
                        if (nums[current] > 1)
                            return 0;
                    }
                }
                current_col += 3;
            }
        }
        current_row += 3;
    }
    return 1;
}

int main(int argc, char const *argv[])
{
    char *string[9];
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            *string[i] = j;
            string[i]++;
            j++;
        }
    }

    int i = isValidSudoku(string, 9);
    if (i == 0)
    {
        printf("false");
        return 0;
    }
    printf("true");
    return 0;
}
