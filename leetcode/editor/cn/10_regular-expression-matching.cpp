//给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。 
//
// 
// '.' 匹配任意单个字符 
// '*' 匹配零个或多个前面的那一个元素 
// 
//
// 所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。 
// 
//
// 示例 1： 
//
// 
//输入：s = "aa" p = "a"
//输出：false
//解释："a" 无法匹配 "aa" 整个字符串。
// 
//
// 示例 2: 
//
// 
//输入：s = "aa" p = "a*"
//输出：true
//解释：因为 '*' 代表可以匹配零个或多个前面的那一个元素, 在这里前面的元素就是 'a'。因此，字符串 "aa" 可被视为 'a' 重复了一次。
// 
//
// 示例 3： 
//
// 
//输入：s = "ab" p = ".*"
//输出：true
//解释：".*" 表示可匹配零个或多个（'*'）任意字符（'.'）。
// 
//
// 示例 4： 
//
// 
//输入：s = "aab" p = "c*a*b"
//输出：true
//解释：因为 '*' 表示零个或多个，这里 'c' 为 0 个, 'a' 被重复一次。因此可以匹配字符串 "aab"。
// 
//
// 示例 5： 
//
// 
//输入：s = "mississippi" p = "mis*is*p*."
//输出：false 
//
// 
//
// 提示： 
//
// 
// 0 <= s.length <= 20 
// 0 <= p.length <= 30 
// s 可能为空，且只包含从 a-z 的小写字母。 
// p 可能为空，且只包含从 a-z 的小写字母，以及字符 . 和 *。 
// 保证每次出现字符 * 时，前面都匹配到有效的字符 
// 
// Related Topics 递归 字符串 动态规划 
// 👍 2275 👎 0

/*
 * 题解
我们可以使用一个二维数组 dp，其中 dp[i][j] 表示以 i 截止的字符串是否可以被以 j 截止的
正则表达式匹配。根据正则表达式的不同情况，即字符、星号，点号，我们可以分情况讨论来更
新 dp 数组，其具体代码如下。
 */

#include<string>
#include<vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for(int i = 1; i < n + 1; ++i){
            if(p[i - 1] == '*'){
                dp[0][i] = dp[0][i - 2];
            }
        }
        for(int i = 1; i < m + 1; ++i){
            for(int j = 1; j < n + 1; ++j){
                if(p[j - 1] == '.'){
                    dp[i][j] = dp[i - 1][j - 1];
                }else if(p[j - 1] != '*'){
                    //当前位为字母
                    dp[i][j] = dp[i - 1][j - 1] && p[j - 1] == s[i - 1];
                }else if(p[j - 2] != s[i - 1] && p[j - 2] != '.'){
                    dp[i][j] = dp[i][j - 2];
                }else{
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j] || dp[i][j - 2];
                }
            }
        }
        return dp[m][n];
    }
};
//leetcode submit region end(Prohibit modification and deletion)
