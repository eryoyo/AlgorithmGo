//
// Created by eryo on 2021/7/31.
//

#include <stdio.h>
#include <vector>

/*
	地牢游戏-174

	已知一个二维数组，左上角代表骑士的位置，右下角代表公主的位置
	二维数组中储存整数，正数可以给骑士增加生命值，负数会减少骑士的生命值，
	问骑士初始时至少是多少生命值，才可保证骑士在行走的过程中
	至少保持生命值为1. 骑士只能向下或向右行走
*/

class Solution{
public:
    int calculateMinimumHP(std::vector<std::vector<int> >& dungeon){
        if(dungeon.size() == 0){
            return 0;
        }
        int row = dungeon.size();
        int column = dungeon[0].size();
        std::vector<std::vector<int> > dp(row, std::vector<int>(column, 0));
        dp[row - 1][column - 1] = std::max(1, 1 - dungeon[row - 1][column - 1]);

        for(int i = row - 2; i >= 0; i--){
            dp[i][column - 1] = std::max(1, dp[i + 1][column - 1] - dungeon[i][column - 1]);
        }

        for(int i = column - 2; i >= 0; i--){
            dp[row - 1][i] = std::max(1, dp[row - 1][i + 1] - dungeon[row - 1][i]);
        }

        for(int i = row - 2; i >= 0; i--){
            for(int j = column - 2; j >= 0; j--){
                dp[i][j] = std::max(1, std::min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j]);
            }
        }
        return dp[0][0];
    }
};