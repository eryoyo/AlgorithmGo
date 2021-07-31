//
// Created by eryo on 2021/7/31.
//

#include <stdio.h>
#include <vector>

/*
	打家劫舍-198

	在一条直线上，有n个房屋，每个房屋中有数量不等的财宝，有一个盗贼
	希望从房屋中盗取财宝，由于房屋中有报警器，如果同时从相邻的两个房屋中
	盗取财宝就会触发报警器，问在不触发报警器的前提下，最多可获取多少个财宝

	方法：
		1.确认原问题和子问题
			原问题为求n个房间的最优解，子问题为求前1个房间，前2个房间，。。。，
			前n-1个房间的最优解
		2.确认状态：
			第i个状态即为前i个房间能够获得的最大财宝（最优解）
		3.确认边界状态
			前1个房间的最优解：第一个房间的财宝
			前2个房间的最优解：前两个房间财宝的较大值
		4.状态转移方程：
			选择第i个房间：前i-2个房间的最大财宝和第i个房间的财宝之和
			不选择第i个房间：前i-1个房间的最大财宝
			 dp[i] = max(dp[i - 1], dp[i - 2] + nums[i])
*/

class Solution{
public:
    int rob(std::vector<int>& nums){
        if(nums.size() == 0){
            return 0;
        }
        if(nums.size() == 1){
            return nums[0];
        }
        std::vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        dp[1] = std::max(nums[0], nums[1]);
        for(int i = 2; i < nums.size(); i++){
            dp[i] = std::max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return dp[nums.size() - 1];
    }
};