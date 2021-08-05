//存在一个 无向图 ，图中有 n 个节点。其中每个节点都有一个介于 0 到 n - 1 之间的唯一编号。给你一个二维数组 graph ，其中 graph[u]
// 是一个节点数组，由节点 u 的邻接节点组成。形式上，对于 graph[u] 中的每个 v ，都存在一条位于节点 u 和节点 v 之间的无向边。该无向图同时具有
//以下属性：
// 
// 不存在自环（graph[u] 不包含 u）。 
// 不存在平行边（graph[u] 不包含重复值）。 
// 如果 v 在 graph[u] 内，那么 u 也应该在 graph[v] 内（该图是无向图） 
// 这个图可能不是连通图，也就是说两个节点 u 和 v 之间可能不存在一条连通彼此的路径。 
// 
//
// 二分图 定义：如果能将一个图的节点集合分割成两个独立的子集 A 和 B ，并使图中的每一条边的两个节点一个来自 A 集合，一个来自 B 集合，就将这个图称
//为 二分图 。 
//
// 如果图是二分图，返回 true ；否则，返回 false 。 
//
// 
//
// 示例 1： 
//
// 
//输入：graph = [[1,2,3],[0,2],[0,1,3],[0,2]]
//输出：false
//解释：不能将节点分割成两个独立的子集，以使每条边都连通一个子集中的一个节点与另一个子集中的一个节点。 
//
// 示例 2： 
//
// 
//输入：graph = [[1,3],[0,2],[1,3],[0,2]]
//输出：true
//解释：可以将节点分成两组: {0, 2} 和 {1, 3} 。 
//
// 
//
// 提示： 
//
// 
// graph.length == n 
// 1 <= n <= 100 
// 0 <= graph[u].length < n 
// 0 <= graph[u][i] <= n - 1 
// graph[u] 不会包含 u 
// graph[u] 的所有值 互不相同 
// 如果 graph[u] 包含 v，那么 graph[v] 也会包含 u 
// 
// Related Topics 深度优先搜索 广度优先搜索 并查集 图 
// 👍 285 👎 0

/*
 * 二分图算法也称为染色法，是一种广度优先搜索。如果可以用两种颜色对图中的节点进行着
色，并且保证相邻的节点颜色不同，那么图为二分。

题解
利用队列和广度优先搜索，我们可以对未染色的节点进行染色，并且检查是否有颜色相同的
相邻节点存在。注意在代码中，我们用 0 表示未检查的节点，用 1 和 2 表示两种不同的颜色。
 */

#include <vector>
#include<queue>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        if (n == 0) {
            return true;
        }
        vector<int> color(n, 0);
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (!color[i]) {
                q.push(i);
                color[i] = 1;
            }
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                for (const int & j: graph[node]) {
                    if (color[j] == 0) {
                        q.push(j);
                        color[j] = color[node] == 2 ? 1 : 2;
                    } else if (color[node] == color[j]) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
