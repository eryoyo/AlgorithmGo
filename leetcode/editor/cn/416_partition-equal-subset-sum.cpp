//给你一个 只包含正整数 的 非空 数组 nums 。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [1,5,11,5]
//输出：true
//解释：数组可以分割成 [1, 5, 5] 和 [11] 。 
//
// 示例 2： 
//
// 
//输入：nums = [1,2,3,5]
//输出：false
//解释：数组不能分割成两个元素和相等的子集。
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 200 
// 1 <= nums[i] <= 100 
// 
// Related Topics 数组 动态规划 
// 👍 879 👎 0

/*
 * 题解
本题等价于 0-1 背包问题，设所有数字和为 sum，我们的目标是选取一部分物品，使得它们
的总和为 sum/2。这道题不需要考虑价值，因此我们只需要通过一个布尔值矩阵来表示状态转移
矩阵。注意边界条件的处理。
 */

#include<vector>
#include <numeric>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool canPartition(vector<int>& nums) {
//        int sum = accumulate(nums.begin(), nums.end(), 0);
//        if(sum % 2){
//            return false;
//        }
//        int target = sum / 2;
//        int n = nums.size();
//        //状态转移方程为到dp[i][j]，i表示到第i个数，能否和为j
//        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));
//        for(int i = 0; i <= n; ++i){
//            dp[i][0] = true;
//        }
//        for(int i  = 1; i <= n; ++i){
//            for(int j = 1; j <= target; ++j){
//                if(j >= nums[i - 1]){
//                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
//                }else{
//                    dp[i][j] = dp[i - 1][j];
//                }
//            }
//        }
//        return dp[n][target];

        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2){
            return false;
        }
        int target = sum / 2;
        int n = nums.size();
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        for(int i = 1; i <= n; ++i){
            for(int j = target; j >= nums[i - 1]; --j){
                dp[j] = dp[j] || dp[j - nums[i - 1]];
            }
        }
        return dp[target];
    }
};
//leetcode submit region end(Prohibit modification and deletion)
