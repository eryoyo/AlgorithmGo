//给定一个整数数组，其中第 i 个元素代表了第 i 天的股票价格 。 
//
// 设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）: 
//
// 
// 你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。 
// 卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。 
// 
//
// 示例: 
//
// 输入: [1,2,3,0,2]
//输出: 3 
//解释: 对应的交易状态为: [买入, 卖出, 冷冻期, 买入, 卖出] 
// Related Topics 数组 动态规划 
// 👍 842 👎 0

/*
 * 题解
我们可以使用状态机来解决这类复杂的状态转移问题，通过建立多个状态以及它们的转移方
式，我们可以很容易地推导出各个状态的转移方程。如图所示，我们可以建立四个状态来表示带
有冷却的股票交易，以及它们的之间的转移方式。
 */

#include<vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 0){
            return 0;
        }
        vector<int> buy(n);
        vector<int> sell(n);
        vector<int> s1(n);
        vector<int> s2(n);
        s1[0] = buy[0] = -prices[0];
        sell[0] = s2[0] = 0;
        for(int i = 1; i < n; i++){
            buy[i] = s2[i - 1] - prices[i];
            s1[i] = max(buy[i - 1], s1[i - 1]);
            sell[i] = max(buy[i - 1], s1[i - 1]) + prices[i];
            s2[i] = max(s2[i - 1], sell[i - 1]);
        }
        return max(sell[n - 1], s2[n - 1]);
    }
};
//leetcode submit region end(Prohibit modification and deletion)
