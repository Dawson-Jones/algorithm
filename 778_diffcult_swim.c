int swimInWater(int** grid, int gridSize, int* gridColSize){
    struct road_map{
        int road_map_key[2];
        int *road_map_value[3];
    };
    struct road_map rm[100];

    int n = 0;
    int row, col = 0, 0;
    rm[n].road_map = {row, col};

    int current = grid[row][col];
    int current_max = grid[row][col];
    if (row==0&&col==0){  // {0, 0}
        rm[n].road_map_value[0] = {row, col+1};
        rm[n].road_map_value[1] = {row+1, col};
    }
    else if(row == gridSize-1&&col==gridColSize-1){
        for(int i=0;i<3;i++){
        if (rm[n].road_map_key[0] != row&&rm[n].road_map_key[1]!=col-1){
            rm[n].road_map_value[0] = {row, col-1};
        }
        else if (rm[n].road_map_key[0] != row-1&&rm[n].road_map_key[1]!=col){
            rm[n].road_map_value[1] = {row-1, col};
        }

    }

      
}
