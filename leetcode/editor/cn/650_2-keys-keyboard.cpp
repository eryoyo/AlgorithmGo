//最初在一个记事本上只有一个字符 'A'。你每次可以对这个记事本进行两种操作： 
//
// 
// Copy All (复制全部) : 你可以复制这个记事本中的所有字符(部分的复制是不允许的)。 
// Paste (粘贴) : 你可以粘贴你上一次复制的字符。 
// 
//
// 给定一个数字 n 。你需要使用最少的操作次数，在记事本中打印出恰好 n 个 'A'。输出能够打印出 n 个 'A' 的最少操作次数。 
//
// 示例 1: 
//
// 
//输入: 3
//输出: 3
//解释:
//最初, 我们只有一个字符 'A'。
//第 1 步, 我们使用 Copy All 操作。
//第 2 步, 我们使用 Paste 操作来获得 'AA'。
//第 3 步, 我们使用 Paste 操作来获得 'AAA'。
// 
//
// 说明: 
//
// 
// n 的取值范围是 [1, 1000] 。 
// 
// Related Topics 数学 动态规划 
// 👍 303 👎 0

/*
 * 题解
不同于以往通过加减实现的动态规划，这里需要乘除法来计算位置，因为粘贴操作是倍数增
加的。我们使用一个一维数组 dp，其中位置 i 表示延展到长度 i 的最少操作次数。对于每个位置
j，如果 j 可以被 i 整除，那么长度 i 就可以由长度 j 操作得到，其操作次数等价于把一个长度为 1
的 A 延展到长度为 i/j。因此我们可以得到递推公式 dp[i] = dp[j] + dp[i/j]。
 */

#include <vector>
#include<cmath>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minSteps(int n) {
        vector<int> dp(n + 1);
        int h = sqrt(n);
        for(int i = 2; i <= n; ++i){
            dp[i] = i;
            for(int j  =2; j <= h; ++j){
                if(i % j == 0){
                    dp[i] = dp[j] + dp[i / j];
                    break;
                }
            }
        }
        return dp[n];
    }
};
//leetcode submit region end(Prohibit modification and deletion)
