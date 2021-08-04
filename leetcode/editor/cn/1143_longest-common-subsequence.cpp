//给定两个字符串 text1 和 text2，返回这两个字符串的最长 公共子序列 的长度。如果不存在 公共子序列 ，返回 0 。 
//
// 一个字符串的 子序列 是指这样一个新的字符串：它是由原字符串在不改变字符的相对顺序的情况下删除某些字符（也可以不删除任何字符）后组成的新字符串。 
//
// 
// 例如，"ace" 是 "abcde" 的子序列，但 "aec" 不是 "abcde" 的子序列。 
// 
//
// 两个字符串的 公共子序列 是这两个字符串所共同拥有的子序列。 
//
// 
//
// 示例 1： 
//
// 
//输入：text1 = "abcde", text2 = "ace" 
//输出：3  
//解释：最长公共子序列是 "ace" ，它的长度为 3 。
// 
//
// 示例 2： 
//
// 
//输入：text1 = "abc", text2 = "abc"
//输出：3
//解释：最长公共子序列是 "abc" ，它的长度为 3 。
// 
//
// 示例 3： 
//
// 
//输入：text1 = "abc", text2 = "def"
//输出：0
//解释：两个字符串没有公共子序列，返回 0 。
// 
//
// 
//
// 提示： 
//
// 
// 1 <= text1.length, text2.length <= 1000 
// text1 和 text2 仅由小写英文字符组成。 
// 
// Related Topics 字符串 动态规划 
// 👍 631 👎 0

/*
 * 题解
对于子序列问题，第二种动态规划方法是，定义一个 dp 数组，其中 dp[i] 表示到位置 i 为止
的子序列的性质，并不必须以 i 结尾。这样 dp 数组的最后一位结果即为题目所求，不需要再对每
个位置进行统计。
在本题中，我们可以建立一个二维数组 dp，其中 dp[i][j] 表示到第一个字符串位置 i 为止、到
第二个字符串位置 j 为止、最长的公共子序列长度。这样一来我们就可以很方便地分情况讨论这
两个位置对应的字母相同与不同的情况了。
 */

#include <string>
#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for(int i = 1; i <= m; ++i){
            for(int j = 1; j <= n; ++j){
                if(text1[i - 1] == text2[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }else{
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[m][n];
    }
};
//leetcode submit region end(Prohibit modification and deletion)
