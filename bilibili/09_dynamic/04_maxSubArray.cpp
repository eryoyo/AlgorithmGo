//
// Created by eryo on 2021/7/31.
//

#include <stdio.h>
#include <vector>

/*
	最大子段和-53

	给定一个数组，求这个数组的连续子数组中，最大的那一段的和

	方法：
		子问题：求出以每一位为结尾的子段和最大子段
		最后：返回这些子段里面最大的。
		递推公式：
			如果dp[i - 1] > 0:带上前面的子段dp[i] = dp[i - 1] + nums[i]
			如果dp[i - 1] < 0:该i位单个成为子段 dp[i] = nums[i]
*/

class Solution{
public:
    int maxSubArray(std::vector<int> &nums){
        std::vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        int max_res = dp[0];
        for(int i = 1; i < nums.size(); i++){
            dp[i] = std::max(nums[i] + dp[i - 1], nums[i]);
            if(max_res < dp[i]){
                max_res = dp[i];
            }
        }
        return max_res;
    }
};