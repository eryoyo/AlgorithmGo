//给定一个整数数组 prices ，它的第 i 个元素 prices[i] 是一支给定的股票在第 i 天的价格。 
//
// 设计一个算法来计算你所能获取的最大利润。你最多可以完成 k 笔交易。 
//
// 注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。 
//
// 
//
// 示例 1： 
//
// 
//输入：k = 2, prices = [2,4,1]
//输出：2
//解释：在第 1 天 (股票价格 = 2) 的时候买入，在第 2 天 (股票价格 = 4) 的时候卖出，这笔交易所能获得利润 = 4-2 = 2 。 
//
// 示例 2： 
//
// 
//输入：k = 2, prices = [3,2,6,5,0,3]
//输出：7
//解释：在第 2 天 (股票价格 = 2) 的时候买入，在第 3 天 (股票价格 = 6) 的时候卖出, 这笔交易所能获得利润 = 6-2 = 4 。
//     随后，在第 5 天 (股票价格 = 0) 的时候买入，在第 6 天 (股票价格 = 3) 的时候卖出, 这笔交易所能获得利润 = 3-0 = 3 
//。 
//
// 
//
// 提示： 
//
// 
// 0 <= k <= 100 
// 0 <= prices.length <= 1000 
// 0 <= prices[i] <= 1000 
// 
// Related Topics 数组 动态规划 
// 👍 552 👎 0

/*
 * 题解
如果 k 大约总天数，那么我们一旦发现可以赚钱就进行买卖。如果 k 小于总天数，我们可以
建立两个动态规划数组 buy 和 sell，对于每天的股票价格，buy[j] 表示在第 j 次买入时的最大收
益，sell[j] 表示在第 j 次卖出时的最大收益。
 */

#include<vector>
#include <climits>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int days = prices.size();
        if(days < 2){
            return 0;
        }
        if(k >= days){
            return maxProfitUnlimited(prices);
        }
        vector<int> buy(k + 1, INT_MIN);
        vector<int> sell(k + 1, 0);
        for(int i = 0; i < days; ++i){
            for(int j = 1; j <= k; ++j){
                buy[j] = max(buy[j], sell[j - 1] - prices[i]);
                sell[j] = max(sell[j], buy[j] + prices[i]);
            }
        }
        return sell[k];
    }

    int maxProfitUnlimited(vector<int> prices){
        int maxProfit = 0;
        for(int i = 1; i < prices.size(); ++i){
            if(prices[i] > prices[i - 1]){
                maxProfit += prices[i] - prices[i - 1];
            }
        }
        return maxProfit;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
