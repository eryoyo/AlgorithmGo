//给定一个非负整数 num。对于 0 ≤ i ≤ num 范围中的每个数字 i ，计算其二进制数中的 1 的数目并将它们作为数组返回。 
//
// 示例 1: 
//
// 输入: 2
//输出: [0,1,1] 
//
// 示例 2: 
//
// 输入: 5
//输出: [0,1,1,2,1,2] 
//
// 进阶: 
//
// 
// 给出时间复杂度为O(n*sizeof(integer))的解答非常容易。但你可以在线性时间O(n)内用一趟扫描做到吗？ 
// 要求算法的空间复杂度为O(n)。 
// 你能进一步完善解法吗？要求在C++或任何其他语言中不使用任何内置函数（如 C++ 中的 __builtin_popcount）来执行此操作。 
// 
// Related Topics 位运算 动态规划 
// 👍 778 👎 0

/*
 * 题解
本题可以利用动态规划和位运算进行快速的求解。定义一个数组 dp，其中 dp[i] 表示数字 i
的二进制含有 1 的个数。对于第 i 个数字，如果它二进制的最后一位为 1，那么它含有 1 的个数
则为 dp[i-1] + 1；如果它二进制的最后一位为 0，那么它含有 1 的个数和其算术右移结果相同，即
dp[i>>1]。
 */

#include<vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n + 1, 0);
        for(int i = 1; i <= n; ++i){
            dp[i] = i & 1 ? dp[i - 1] + 1 : dp[i >> 1];
        }
        return dp;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
