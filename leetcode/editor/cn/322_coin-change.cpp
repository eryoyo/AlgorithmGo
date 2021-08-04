//给你一个整数数组 coins ，表示不同面额的硬币；以及一个整数 amount ，表示总金额。 
//
// 计算并返回可以凑成总金额所需的 最少的硬币个数 。如果没有任何一种硬币组合能组成总金额，返回 -1 。 
//
// 你可以认为每种硬币的数量是无限的。 
//
// 
//
// 示例 1： 
//
// 
//输入：coins = [1, 2, 5], amount = 11
//输出：3 
//解释：11 = 5 + 5 + 1 
//
// 示例 2： 
//
// 
//输入：coins = [2], amount = 3
//输出：-1 
//
// 示例 3： 
//
// 
//输入：coins = [1], amount = 0
//输出：0
// 
//
// 示例 4： 
//
// 
//输入：coins = [1], amount = 1
//输出：1
// 
//
// 示例 5： 
//
// 
//输入：coins = [1], amount = 2
//输出：2
// 
//
// 
//
// 提示： 
//
// 
// 1 <= coins.length <= 12 
// 1 <= coins[i] <= 231 - 1 
// 0 <= amount <= 104 
// 
// Related Topics 广度优先搜索 数组 动态规划 
// 👍 1404 👎 0

/*
 * 题解
因为每个硬币可以用无限多次，这道题本质上是完全背包。我们直接展示二维空间压缩为一
维的写法。
这里注意，我们把 dp 数组初始化为 amount + 2 而不是-1 的原因是，在动态规划过程中有求
最小值的操作，如果初始化成-1 则会导致结果始终为-1。至于为什么取这个值，是因为 i 最大可
以取 amount + 1，而最多的组成方式是只用 1 元硬币，因此 amount + 2 一定大于所有可能的组合
方式，取最小值时一定不会是它。在动态规划完成后，若结果仍然是此值，则说明不存在满足条
件的组合方法，返回-1。
 */

#include<vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(coins.empty()){
            return -1;
        }
        vector<int> dp(amount + 1, amount + 2);
        dp[0] = 0;
        for(int i = 1; i <= amount; ++i){
            for(const int &coin : coins){
                if(i >= coin){
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }
        return dp[amount] == amount + 2 ? -1 : dp[amount];
    }
};
//leetcode submit region end(Prohibit modification and deletion)
