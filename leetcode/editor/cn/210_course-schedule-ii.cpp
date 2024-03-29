//现在你总共有 n 门课需要选，记为 0 到 n-1。 
//
// 在选修某些课程之前需要一些先修课程。 例如，想要学习课程 0 ，你需要先完成课程 1 ，我们用一个匹配来表示他们: [0,1] 
//
// 给定课程总量以及它们的先决条件，返回你为了学完所有课程所安排的学习顺序。 
//
// 可能会有多个正确的顺序，你只要返回一种就可以了。如果不可能完成所有课程，返回一个空数组。 
//
// 示例 1: 
//
// 输入: 2, [[1,0]] 
//输出: [0,1]
//解释: 总共有 2 门课程。要学习课程 1，你需要先完成课程 0。因此，正确的课程顺序为 [0,1] 。 
//
// 示例 2: 
//
// 输入: 4, [[1,0],[2,0],[3,1],[3,2]]
//输出: [0,1,2,3] or [0,2,1,3]
//解释: 总共有 4 门课程。要学习课程 3，你应该先完成课程 1 和课程 2。并且课程 1 和课程 2 都应该排在课程 0 之后。
//     因此，一个正确的课程顺序是 [0,1,2,3] 。另一个正确的排序是 [0,2,1,3] 。
// 
//
// 说明: 
//
// 
// 输入的先决条件是由边缘列表表示的图形，而不是邻接矩阵。详情请参见图的表示法。 
// 你可以假定输入的先决条件中没有重复的边。 
// 
//
// 提示: 
//
// 
// 这个问题相当于查找一个循环是否存在于有向图中。如果存在循环，则不存在拓扑排序，因此不可能选取所有课程进行学习。 
// 通过 DFS 进行拓扑排序 - 一个关于Coursera的精彩视频教程（21分钟），介绍拓扑排序的基本概念。 
// 
// 拓扑排序也可以通过 BFS 完成。 
// 
// 
// Related Topics 深度优先搜索 广度优先搜索 图 拓扑排序 
// 👍 447 👎 0

/*
 * 拓扑排序（topological sort）是一种常见的，对有向无环图排序的算法。给定有向无环图中的
N 个节点，我们把它们排序成一个线性序列；若原图中节点 i 指向节点 j，则排序结果中 i 一定在
j 之前。拓扑排序的结果不是唯一的，只要满足以上条件即可。

题解
我们可以先建立一个邻接矩阵表示图，方便进行直接查找。这里注意我们将所有的边反向，
使得如果课程 i 指向课程 j，那么课程 i 需要在课程 j 前面先修完。这样更符合我们的直观理解。
拓扑排序也可以被看成是广度优先搜索的一种情况：我们先遍历一遍所有节点，把入度为 0
的节点（即没有前置课程要求）放在队列中。在每次从队列中获得节点时，我们将该节点放在目
前排序的末尾，并且把它指向的课程的入度各减 1；如果在这个过程中有课程的所有前置必修课
都已修完（即入度为 0），我们把这个节点加入队列中。当队列的节点都被处理完时，说明所有的
节点都已排好序，或因图中存在循环而无法上完所有课程。
 */

#include <vector>
#include<queue>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>());
        vector<int> indegree(numCourses, 0), res;
        for (const auto & prerequisite: prerequisites) {
            graph[prerequisite[1]].push_back(prerequisite[0]);
            ++indegree[prerequisite[0]];
        }
        queue<int> q;
        for (int i = 0; i < indegree.size(); ++i) {
            if (!indegree[i]) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int u = q.front();
            res.push_back(u);
            q.pop();
            for (auto v: graph[u]) {
                --indegree[v];
                if (!indegree[v]) {
                    q.push(v);
                }
            }
        }
        for (int i = 0; i < indegree.size(); ++i) {
            if (indegree[i]) {
                return vector<int>();
            }
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
