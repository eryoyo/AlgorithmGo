//
// Created by eryo on 2021/7/31.
//

#include <stdio.h>
#include <vector>

/*
	爬楼梯-70

	在爬楼梯时，每次可向上走一阶台阶或两阶台阶，问有n阶楼梯有多少种上楼方式

	方法：dynamic programming
		得到递推公式：dp[i] = dp[i - 1] + dp[i - 2]

	动态规划原理：
		1、确认原问题与子问题：
			原问题：求n阶台阶的所有走法的数量
			子问题：求n-1,n-2,...,1阶台阶的走法
		2、确认状态：
			本题的动态规划状态单一，第i个状态即为i阶台阶的所有走法数量
		3、确认边界状态的值：
			阶数为1和2的走法数量
		4、确认状态转移方程： dp[i] = dp[i - 1] + dp[i - 2]
*/

class Solution{
public:
    int climbStairs(int n){
        std::vector<int> dp(n + 3, 0);
        dp[1] = 1;
        dp[2] = 2;
        for(int i = 3; i <= n; i++){
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

int main(){
    Solution s;
    printf("%d\n", s.climbStairs(3));
    return 0;
}