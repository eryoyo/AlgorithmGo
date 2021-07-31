//
// Created by eryo on 2021/7/31.
//

#include <stdio.h>
#include <vector>

/*
	最长上升子序列-300

	已知一个未排序数组，求这个数组最长上升子序列的长度

	方法：
		dp[i]:表示以第i个元素为结尾的最长子序列
*/

class Solution{
public:
    int lengthOfLIS(std::vector<int>& nums){
        if(nums.size() == 0){
            return 0;
        }
        std::vector<int> dp(nums.size(), 0);
        dp[0] = 1;
        int LIS = 1;
        for(int i = 1; i < dp.size(); i++){
            for(int j = 0; j < i; j++){
                if(nums[j] < nums[i] && dp[i] < dp[j] + 1){
                    dp[i] = dp[j] + 1;
                }
            }
            if(LIS < dp[i]){
                LIS = dp[i];
            }
        }
    }
};