//
// Created by eryo on 2021/7/31.
//

#include <stdio.h>
#include <vector>

/*
	找零钱-322

	已知不同面值的钞票，求如何用最少数量的钞票组成某个金额，求可以使用
	的最少钞票数量，如果任意数量的一致面值钞票都无法组成该金额，返回-1

	方法：
		状态i可由i-1, i-2, i-5, i-7, i-10状态转移得到，钞票面值[1, 2, 5, 7, 10]
		dp[i] = min(dp[i-1],dp[i-2],dp[i-5],dp[i-7],dp[i-10]) + 1
		dp[i]是金额i使用钱数的最小张数
*/

class Solution{
public:
    int coinChange(std::vector<int>& coins, int amount){
        std::vector<int> dp;
        for(int i = 0; i <= amount; i++){
            dp.push_back(-1);	//最初所有金额的最优解均为-1，不可到达
        }
        dp[0] = 0;	//金额0最优解0
        for(int i = 1; i <= amount; i++){
            for(int j = 0; j < coins.size(); j++){
                if(i - coins[j] >= 0 && dp[i - coins[j]] != -1){
                    if(dp[i] == -1 || dp[i] > dp[i - coins[j]] + 1){
                        dp[i] = dp[i - coins[j]] + 1;
                    }
                }
            }
        }
        return dp[amount];
    }
};