//给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。 
//
// 子序列是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7] 的子序
//列。 
// 
//
// 示例 1： 
//
// 
//输入：nums = [10,9,2,5,3,7,101,18]
//输出：4
//解释：最长递增子序列是 [2,3,7,101]，因此长度为 4 。
// 
//
// 示例 2： 
//
// 
//输入：nums = [0,1,0,3,2,3]
//输出：4
// 
//
// 示例 3： 
//
// 
//输入：nums = [7,7,7,7,7,7,7]
//输出：1
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 2500 
// -104 <= nums[i] <= 104 
// 
//
// 
//
// 进阶： 
//
// 
// 你可以设计时间复杂度为 O(n2) 的解决方案吗？ 
// 你能将算法的时间复杂度降低到 O(n log(n)) 吗? 
// 
// Related Topics 数组 二分查找 动态规划 
// 👍 1762 👎 0

/*
 * 题解
对于子序列问题，第一种动态规划方法是，定义一个 dp 数组，其中 dp[i] 表示以 i 结尾的子
序列的性质。在处理好每个位置后，统计一遍各个位置的结果即可得到题目要求的结果。
 在本题中，dp[i] 可以表示以 i 结尾的、最长子序列长度。对于每一个位置 i，如果其之前的某
个位置 j 所对应的数字小于位置 i 所对应的数字，则我们可以获得一个以 i 结尾的、长度为 dp[j]
+ 1 的子序列。为了遍历所有情况，我们需要 i 和 j 进行两层循环，其时间复杂度为 O(n2)。
 */

#include<vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
//        int max_length = 0;
//        int n = nums.size();
//        if(n <= 1){
//            return n;
//        }
//        vector<int> dp(n, 1);
//        for(int i = 0; i < n; ++i){
//            for(int j = 0; j < i; ++j){
//                if(nums[i] > nums[j]){
//                    dp[i] = max(dp[i], dp[j] + 1);
//                }
//            }
//            max_length = max(max_length, dp[i]);
//        }
//        return max_length;

/*
 * 本题还可以使用二分查找将时间复杂度降低为 O(n log n)。我们定义一个 dp 数组，其中 dp[k]
存储长度为 k+1 的最长递增子序列的最后一个数字。我们遍历每一个位置 i，如果其对应的数字
大于 dp 数组中所有数字的值，那么我们把它放在 dp 数组尾部，表示最长递增子序列长度加 1；
如果我们发现这个数字在 dp 数组中比数字 a 大、比数字 b 小，则我们将 b 更新为此数字，使得
之后构成递增序列的可能性增大。以这种方式维护的 dp 数组永远是递增的，因此可以用二分查
找加速搜索。
 */
        int n = nums.size();
        if(n <= 1){
            return n;
        }
        vector<int> dp;
        dp.push_back(nums[0]);
        for(int i = 1; i < n; ++i){
            if(dp.back() < nums[i]){
                dp.push_back(nums[i]);
            }else{
                auto itr = lower_bound(dp.begin(), dp.end(), nums[i]);
                *itr = nums[i];
            }
        }
        return dp.size();
    }
};
//leetcode submit region end(Prohibit modification and deletion)
