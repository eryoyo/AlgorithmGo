//给定一个 m x n 的非负整数矩阵来表示一片大陆上各个单元格的高度。“太平洋”处于大陆的左边界和上边界，而“大西洋”处于大陆的右边界和下边界。 
//
// 规定水流只能按照上、下、左、右四个方向流动，且只能从高到低或者在同等高度上流动。 
//
// 请找出那些水流既可以流动到“太平洋”，又能流动到“大西洋”的陆地单元的坐标。 
//
// 
//
// 提示： 
//
// 
// 输出坐标的顺序不重要 
// m 和 n 都小于150 
// 
//
// 
//
// 示例： 
//
// 
//
// 
//给定下面的 5x5 矩阵:
//
//  太平洋 ~   ~   ~   ~   ~ 
//       ~  1   2   2   3  (5) *
//       ~  3   2   3  (4) (4) *
//       ~  2   4  (5)  3   1  *
//       ~ (6) (7)  1   4   5  *
//       ~ (5)  1   1   2   4  *
//          *   *   *   *   * 大西洋
//
//返回:
//
//[[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]] (上图中带括号的单元).
// 
//
// 
// Related Topics 深度优先搜索 广度优先搜索 数组 矩阵 
// 👍 272 👎 0

/*
 * 题解
虽然题目要求的是满足向下流能到达两个大洋的位置，如果我们对所有的位置进行搜索，那
么在不剪枝的情况下复杂度会很高。因此我们可以反过来想，从两个大洋开始向上流，这样我们
只需要对矩形四条边进行搜索。搜索完成后，只需遍历一遍矩阵，满足条件的位置即为两个大洋
向上流都能到达的位置。
 */

#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> direction{-1, 0, 1, 0, -1};

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if(heights.empty() || heights[0].empty()){
            return {};
        }
        vector<vector<int>> ans;
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<bool>> can_reach_p(m, vector<bool>(n, false));
        vector<vector<bool>> can_reach_a(m, vector<bool>(n, false));
        for(int i = 0; i < m; ++i){
            dfs(heights, can_reach_p, i, 0);
            dfs(heights, can_reach_a, i, n - 1);
        }
        for(int i = 0; i < n; ++i){
            dfs(heights, can_reach_p, 0, i);
            dfs(heights, can_reach_a, m - 1, i);
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(can_reach_p[i][j] && can_reach_a[i][j]){
                    ans.push_back(vector<int>{i, j});
                }
            }
        }
        return ans;
    }

    void dfs(const vector<vector<int>>& matrix, vector<vector<bool>>& can_reach,
             int r, int c){
        if(can_reach[r][c]){
            return;
        }
        can_reach[r][c] = true;
        int x;
        int y;
        for(int i = 0; i < 4; ++i){
            x = r + direction[i];
            y = c + direction[i + 1];
            if(x >= 0 && x < matrix.size()
            && y >= 0 && y < matrix[0].size()
            && matrix[r][c] <= matrix[x][y]){
                dfs(matrix, can_reach, x, y);
            }
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)
