//树可以看成是一个连通且 无环 的 无向 图。 
//
// 给定往一棵 n 个节点 (节点值 1～n) 的树中添加一条边后的图。添加的边的两个顶点包含在 1 到 n 中间，且这条附加的边不属于树中已存在的边。图的信
//息记录于长度为 n 的二维数组 edges ，edges[i] = [ai, bi] 表示图中在 ai 和 bi 之间存在一条边。 
//
// 请找出一条可以删去的边，删除后可使得剩余部分是一个有着 n 个节点的树。如果有多个答案，则返回数组 edges 中最后出现的边。 
//
// 
//
// 示例 1： 
//
// 
//
// 
//输入: edges = [[1,2], [1,3], [2,3]]
//输出: [2,3]
// 
//
// 示例 2： 
//
// 
//
// 
//输入: edges = [[1,2], [2,3], [3,4], [1,4], [1,5]]
//输出: [1,4]
// 
//
// 
//
// 提示: 
//
// 
// n == edges.length 
// 3 <= n <= 1000 
// edges[i].length == 2 
// 1 <= ai < bi <= edges.length 
// ai != bi 
// edges 中无重复元素 
// 给定的图是连通的 
// 
// Related Topics 深度优先搜索 广度优先搜索 并查集 图 
// 👍 370 👎 0

/*
 * 题解
因为需要判断是否两个节点被重复连通，所以我们可以使用并查集来解决此类问题。具体实
现算法如下所示。
 */

#include <vector>
#include <numeric>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class UF {
    vector<int> id, size;
public:
    UF(int n): id(n), size(n, 1) {
        iota(id.begin(), id.end(), 0); // iota函数可以把数组初始化为0到n-1
    }
    int find(int p) {
        while (p != id[p]) {
            id[p] = id[id[p]]; // 路径压缩，使得下次查找更快
            p = id[p];
        }
        return p;
    }
    void connect(int p, int q) {
        int i = find(p), j = find(q);
        if (i != j) {
// 按秩合并：每次合并都把深度较小的集合合并在深度较大的集合下面
            if (size[i] < size[j]) {
                id[i] = j;
                size[j] += size[i];
            } else {
                id[j] = i;
                size[i] += size[j];
            }
        }
    }
    bool isConnected(int p, int q) {
        return find(p) == find(q);
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        UF uf(n + 1);
        for (auto e: edges) {
            int u = e[0], v = e[1];
            if (uf.isConnected(u, v)) {
                return e;
            }
            uf.connect(u, v);
        }
        return vector<int>{-1, -1};
    }
};
//leetcode submit region end(Prohibit modification and deletion)
