//给你一个二进制字符串数组 strs 和两个整数 m 和 n 。 
//
// 
// 请你找出并返回 strs 的最大子集的大小，该子集中 最多 有 m 个 0 和 n 个 1 。 
//
// 如果 x 的所有元素也是 y 的元素，集合 x 是集合 y 的 子集 。 
// 
//
// 
//
// 示例 1： 
//
// 
//输入：strs = ["10", "0001", "111001", "1", "0"], m = 5, n = 3
//输出：4
//解释：最多有 5 个 0 和 3 个 1 的最大子集是 {"10","0001","1","0"} ，因此答案是 4 。
//其他满足题意但较小的子集包括 {"0001","1"} 和 {"10","1","0"} 。{"111001"} 不满足题意，因为它含 4 个 1 ，大于 
//n 的值 3 。
// 
//
// 示例 2： 
//
// 
//输入：strs = ["10", "0", "1"], m = 1, n = 1
//输出：2
//解释：最大的子集是 {"0", "1"} ，所以答案是 2 。
// 
//
// 
//
// 提示： 
//
// 
// 1 <= strs.length <= 600 
// 1 <= strs[i].length <= 100 
// strs[i] 仅由 '0' 和 '1' 组成 
// 1 <= m, n <= 100 
// 
// Related Topics 数组 字符串 动态规划 
// 👍 531 👎 0

/*
 * 题解
这是一个多维费用的 0-1 背包问题，有两个背包大小，0 的数量和 1 的数量。我们在这里直
接展示三维空间压缩到二维后的写法。
 */

#include<vector>
#include <string>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for(const string &str : strs){
            auto [count0, count1] = count(str);
            for(int i = m; i >= count0; --i){
                for(int j = n; j >= count1; --j){
                    dp[i][j] = max(dp[i][j], 1 + dp[i - count0][j - count1]);
                }
            }
        }
        return dp[m][n];
    }

    pair<int, int> count(const string &s){
        int count0 = s.length();
        int count1 = 0;
        for(const char &c : s){
            if(c == '1'){
                ++count1;
                --count0;
            }
        }
        return make_pair(count0, count1);
    }
};
//leetcode submit region end(Prohibit modification and deletion)
