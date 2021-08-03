//在给定的二维二进制数组 A 中，存在两座岛。（岛是由四面相连的 1 形成的一个最大组。） 
//
// 现在，我们可以将 0 变为 1，以使两座岛连接起来，变成一座岛。 
//
// 返回必须翻转的 0 的最小数目。（可以保证答案至少是 1 。） 
//
// 
//
// 示例 1： 
//
// 
//输入：A = [[0,1],[1,0]]
//输出：1
// 
//
// 示例 2： 
//
// 
//输入：A = [[0,1,0],[0,0,0],[0,0,1]]
//输出：2
// 
//
// 示例 3： 
//
// 
//输入：A = [[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
//输出：1 
//
// 
//
// 提示： 
//
// 
// 2 <= A.length == A[0].length <= 100 
// A[i][j] == 0 或 A[i][j] == 1 
// 
// Related Topics 深度优先搜索 广度优先搜索 数组 矩阵 
// 👍 175 👎 0

/*
 * 题解
本题实际上是求两个岛屿间的最短距离，因此我们可以先通过任意搜索方法找到其中一个岛
屿，然后利用广度优先搜索，查找其与另一个岛屿的最短距离。
 */

#include <vector>
#include<queue>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> direction = {-1, 0, 1, 0, -1};

    int shortestBridge(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> points;
        //dfs寻找第一个岛屿，并将1全部赋值为2
        bool flipped = false;
        for(int i = 0; i < m; ++i){
            if(flipped){
                break;
            }
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == 1){
                    dfs(points, grid, m, n, i, j);
                    flipped = true;
                    break;
                }
            }
        }

        //bfs寻找第二个岛屿，并将过程中经过的0赋值为2
        int x;
        int y;
        int level = 0;
        while(!points.empty()){
            ++level;
            int n_points = points.size();
            while(n_points--){
                auto [r, c] = points.front();
                points.pop();
                for(int k = 0; k < 4; ++k){
                    x = r + direction[k];
                    y = c + direction[k + 1];
                    if(x >= 0 && y >= 0 && x < m && y < n){
                        if(grid[x][y] == 2){
                            continue;
                        }
                        if(grid[x][y] == 1){
                            return level;
                        }
                        points.push({x, y});
                        grid[x][y] = 2;
                    }
                }
            }
        }
        return 0;
    }

    void dfs(queue<pair<int, int>> &points,
             vector<vector<int>>& grid,
             int m, int n, int i, int j){
        if(i < 0 || j < 0 || i == m || j == n || grid[i][j] == 2){
            return;
        }
        if(grid[i][j] == 0){
            points.push({i, j});
            return;
        }
        grid[i][j] = 2;
        dfs(points, grid, m, n, i - 1, j);
        dfs(points, grid, m, n, i + 1, j);
        dfs(points, grid, m, n, i, j - 1);
        dfs(points, grid, m, n, i, j + 1);
    }
};
//leetcode submit region end(Prohibit modification and deletion)
