//
// Created by eryo on 2021/7/31.
//

#include <stdio.h>
#include <vector>

/*
	三角形-120

	给定一个二维数组，其保存了一个数字三角形，求从数字三角形顶端到底端各数字
	和最小的路径之和，每次可以向下走相邻的两个位置

	方法：
		dp[i][j]:表示数组三角形第i行第j列的最优解
		从上往下递推 从下往上递推√
*/

class Solution{
public:
    int minimumTotal(std::vector<std::vector<int> >& triangle){
        if(triangle.size() == 0){
            return 0;
        }
        std::vector<std::vector<int> > dp;
        for(int i = 0; i < triangle.size(); i++){
            dp.push_back(std::vector<int>());
            for(int j = 0; j < triangle[i].size(); j++){
                dp[i].push_back(0);
            }
        }
        for(int i = 0; i < dp.size(); i++){
            dp[dp.size() - 1][i] = triangle[dp.size() - 1][i];
        }
        for(int i = dp.size() - 2; i >= 0; i--){
            for(int j = 0; j < dp[i].size(); j++){
                dp[i][j] = std::min(dp[i + 1][j], dp[i + 1][j + 1]) + triangle[i][j];
            }
        }
        return dp[0][0];
    }
};