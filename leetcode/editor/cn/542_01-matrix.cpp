//给定一个由 0 和 1 组成的矩阵 mat ，请输出一个大小相同的矩阵，其中每一个格子是 mat 中对应位置元素到最近的 0 的距离。 
//
// 两个相邻元素间的距离为 1 。 
//
// 
//
// 示例 1： 
//
// 
//
// 
//输入：mat = [[0,0,0],[0,1,0],[0,0,0]]
//输出：[[0,0,0],[0,1,0],[0,0,0]]
// 
//
// 示例 2： 
//
// 
//
// 
//输入：mat = [[0,0,0],[0,1,0],[1,1,1]]
//输出：[[0,0,0],[0,1,0],[1,2,1]]
// 
//
// 
//
// 提示： 
//
// 
// m == mat.length 
// n == mat[i].length 
// 1 <= m, n <= 104 
// 1 <= m * n <= 104 
// mat[i][j] is either 0 or 1. 
// mat 中至少有一个 0 
// 
// Related Topics 广度优先搜索 数组 动态规划 矩阵 
// 👍 461 👎 0

/*
 * 题解
一般来说，因为这道题涉及到四个方向上的最近搜索，所以很多人的第一反应可能会是广度
优先搜索。但是对于一个大小 O(mn) 的二维数组，对每个位置进行四向搜索，最坏情况的时间复
杂度（即全是 1）会达到恐怖的 O(m2n2)。一种办法是使用一个 dp 数组做 memoization，使得广
度优先搜索不会重复遍历相同位置；另一种更简单的方法是，我们从左上到右下进行一次动态搜
索，再从右下到左上进行一次动态搜索。两次动态搜索即可完成四个方向上的查找。
 */

#include <vector>
#include <climits>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        if(mat.empty()){
            return {};
        }
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> dp(n, vector<int>(m, INT_MAX - 1));
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(mat[i][j] == 0){
                    dp[i][j] = 0;
                } else{
                    if(j > 0){
                        dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
                    }
                    if(i > 0){
                        dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
                    }
                }
            }
        }
        for(int i = n - 1; i >= 0; --i){
            for(int j = m - 1; j >= 0; --j){
                if(mat[i][j] != 0){
                    if(j < m - 1){
                        dp[i][j] = min(dp[i][j], dp[i][j + 1] + 1);
                    }
                    if(i < n - 1){
                        dp[i][j] = min(dp[i][j], dp[i + 1][j] + 1);
                    }
                }
            }
        }
        return dp;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
