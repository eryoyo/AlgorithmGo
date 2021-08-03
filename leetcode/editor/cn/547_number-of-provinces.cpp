//
// 
// 有 n 个城市，其中一些彼此相连，另一些没有相连。如果城市 a 与城市 b 直接相连，且城市 b 与城市 c 直接相连，那么城市 a 与城市 c 间接相连
//。 
//
// 省份 是一组直接或间接相连的城市，组内不含其他没有相连的城市。 
//
// 给你一个 n x n 的矩阵 isConnected ，其中 isConnected[i][j] = 1 表示第 i 个城市和第 j 个城市直接相连，而 
//isConnected[i][j] = 0 表示二者不直接相连。 
//
// 返回矩阵中 省份 的数量。 
//
// 
//
// 示例 1： 
//
// 
//输入：isConnected = [[1,1,0],[1,1,0],[0,0,1]]
//输出：2
// 
//
// 示例 2： 
//
// 
//输入：isConnected = [[1,0,0],[0,1,0],[0,0,1]]
//输出：3
// 
//
// 
//
// 提示： 
//
// 
// 1 <= n <= 200 
// n == isConnected.length 
// n == isConnected[i].length 
// isConnected[i][j] 为 1 或 0 
// isConnected[i][i] == 1 
// isConnected[i][j] == isConnected[j][i] 
// 
// 
// 
// Related Topics 深度优先搜索 广度优先搜索 并查集 图 
// 👍 585 👎 0

/*
 * 题解
对于题目 695，图的表示方法是，每个位置代表一个节点，每个节点与上下左右四个节点相
邻。而在这一道题里面，每一行（列）表示一个节点，它的每列（行）表示是否存在一个相邻节
点。因此题目 695 拥有 m × n 个节点，每个节点有 4 条边；而本题拥有 n 个节点，每个节点最多
有 n 条边，表示和所有人都是朋友，最少可以有 1 条边，表示自己与自己相连。当清楚了图的表
示方法后，这道题与题目 695 本质上是同一道题：搜索朋友圈（岛屿）的个数（最大面积）。我
们这里采用递归的第一种写法。
 */

#include<vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int count = 0;
        vector<bool> visited(n, false);
        for(int i = 0; i < n; ++i){
            if(!visited[i]){
                dfs(isConnected, i, visited);
                ++count;
            }
        }
        return count;
    }

    void dfs(vector<vector<int>> &friends, int i, vector<bool> &visited){
        visited[i] = true;
        for(int k = 0; k < friends.size(); ++k){
            if(friends[i][k] == 1 && !visited[k]){
                dfs(friends, k, visited);
            }
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)
