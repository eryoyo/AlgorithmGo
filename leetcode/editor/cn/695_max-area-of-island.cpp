//给定一个包含了一些 0 和 1 的非空二维数组 grid 。 
//
// 一个 岛屿 是由一些相邻的 1 (代表土地) 构成的组合，这里的「相邻」要求两个 1 必须在水平或者竖直方向上相邻。你可以假设 grid 的四个边缘都被 
//0（代表水）包围着。 
//
// 找到给定的二维数组中最大的岛屿面积。(如果没有岛屿，则返回面积为 0 。) 
//
// 
//
// 示例 1: 
//
// [[0,0,1,0,0,0,0,1,0,0,0,0,0],
// [0,0,0,0,0,0,0,1,1,1,0,0,0],
// [0,1,1,0,1,0,0,0,0,0,0,0,0],
// [0,1,0,0,1,1,0,0,1,0,1,0,0],
// [0,1,0,0,1,1,0,0,1,1,1,0,0],
// [0,0,0,0,0,0,0,0,0,0,1,0,0],
// [0,0,0,0,0,0,0,1,1,1,0,0,0],
// [0,0,0,0,0,0,0,1,1,0,0,0,0]]
// 
//
// 对于上面这个给定矩阵应返回 6。注意答案不应该是 11 ，因为岛屿只能包含水平或垂直的四个方向的 1 。 
//
// 示例 2: 
//
// [[0,0,0,0,0,0,0,0]] 
//
// 对于上面这个给定的矩阵, 返回 0。 
//
// 
//
// 注意: 给定的矩阵grid 的长度和宽度都不超过 50。 
// Related Topics 深度优先搜索 广度优先搜索 并查集 数组 矩阵 
// 👍 522 👎 0

/*
 * 题解
此题是十分标准的搜索题，我们可以拿来练手深度优先搜索。一般来说，深度优先搜索类型
的题可以分为主函数和辅函数，主函数用于遍历所有的搜索位置，判断是否可以开始搜索，如果
可以即在辅函数进行搜索。辅函数则负责深度优先搜索的递归调用。当然，我们也可以使用栈
（stack）实现深度优先搜索，但因为栈与递归的调用原理相同，而递归相对便于实现，因此刷题时
笔者推荐使用递归式写法，同时也方便进行回溯（见下节）。不过在实际工程上，直接使用栈可
能才是最好的选择，一是因为便于理解，二是更不易出现递归栈满的情况。我们先展示使用栈的
写法。
 */

#include<vector>
#include<stack>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> direction{-1, 0, 1, 0, -1};

    int maxAreaOfIsland(vector<vector<int>>& grid){
        if(grid.empty() || grid[0].empty()){
            return 0;
        }
        int max_area = 0;
        for(int i = 0; i < grid.size(); ++i){
            for(int j = 0; j < grid[0].size(); ++j){
                max_area = max(max_area, dfs_2(grid, i, j));
            }
        }
        return max_area;
    }

    /*
     * 在辅函数里，一个一定要注意的点是辅函数内递归搜索时，边界条件的判定。边界判定一般
有两种写法，一种是先判定是否越界，只有在合法的情况下才进行下一步搜索（即判断放在调用
递归函数前）；另一种是不管三七二十一先进行下一步搜索，待下一步搜索开始时再判断是否合
法（即判断放在辅函数第一行）。我们这里分别展示这两种写法。
     */

    int dfs_1(vector<vector<int>>& grid, int r, int c){
        if(grid[r][c] == 0){
            return 0;
        }
        grid[r][c] = 0;
        int x;
        int y;
        int area = 1;
        for(int i = 0; i < 4; i++){
            x = r + direction[i];
            y = c + direction[i + 1];
            if(x >= 0 && x < grid.size() &&
            y >= 0 && y < grid[0].size()){
                area += dfs_1(grid, x, y);
            }
        }
        return area;
    }

    int dfs_2(vector<vector<int>>& grid, int r, int c){
        if(r < 0 || r >= grid.size() ||
        c < 0 || c >= grid[0].size() || grid[r][c] == 0){
            return 0;
        }
        grid[r][c] = 0;
        return 1 + dfs_2(grid, r + 1, c)
        + dfs_2(grid, r - 1, c)
        + dfs_2(grid, r, c + 1)
        + dfs_2(grid, r, c - 1);
    }

//    int maxAreaOfIsland(vector<vector<int>>& grid) {
//        int m = grid.size();
//        int n = m ? grid[0].size() : 0;
//        int local_area; //储存当前岛屿面积
//        int area = 0;   //储存最大面积
//        int x;
//        int y;
//        for(int i = 0; i < m; i++){
//            for(int j = 0; j < n; j++){
//                if(grid[i][j]){
//                    local_area = 1;
//                    grid[i][j] = 0;
//                    stack<pair<int, int> > island;
//                    island.push({i, j});
//                    while(!island.empty()){
//                        auto [r, c] = island.top();
//                        island.pop();
//                        for(int k = 0; k < 4; k++){
//                            x = r + direction[k];
//                            y = c + direction[k + 1];
//                            if(x >= 0 && x < m &&
//                            y >= 0 && y < n && grid[x][y] == 1){
//                                grid[x][y] = 0;
//                                ++local_area;
//                                island.push({x, y});
//                            }
//                        }
//                    }
//                    area = max(area, local_area);
//                }
//            }
//        }
//        return area;
//    }
};
//leetcode submit region end(Prohibit modification and deletion)
