//给定一个正整数数组 w ，其中 w[i] 代表下标 i 的权重（下标从 0 开始），请写一个函数 pickIndex ，它可以随机地获取下标 i，选取下标 
//i 的概率与 w[i] 成正比。 
//
// 
// 
//
// 例如，对于 w = [1, 3]，挑选下标 0 的概率为 1 / (1 + 3) = 0.25 （即，25%），而选取下标 1 的概率为 3 / (1 +
// 3) = 0.75（即，75%）。 
//
// 也就是说，选取下标 i 的概率为 w[i] / sum(w) 。 
//
// 
//
// 示例 1： 
//
// 输入：
//["Solution","pickIndex"]
//[[[1]],[]]
//输出：
//[null,0]
//解释：
//Solution solution = new Solution([1]);
//solution.pickIndex(); // 返回 0，因为数组中只有一个元素，所以唯一的选择是返回下标 0。 
//
// 示例 2： 
//
// 输入：
//["Solution","pickIndex","pickIndex","pickIndex","pickIndex","pickIndex"]
//[[[1,3]],[],[],[],[],[]]
//输出：
//[null,1,1,1,1,0]
//解释：
//Solution solution = new Solution([1, 3]);
//solution.pickIndex(); // 返回 1，返回下标 1，返回该下标概率为 3/4 。
//solution.pickIndex(); // 返回 1
//solution.pickIndex(); // 返回 1
//solution.pickIndex(); // 返回 1
//solution.pickIndex(); // 返回 0，返回下标 0，返回该下标概率为 1/4 。
//
//由于这是一个随机问题，允许多个答案，因此下列输出都可以被认为是正确的:
//[null,1,1,1,1,0]
//[null,1,1,1,1,1]
//[null,1,1,1,0,0]
//[null,1,1,1,0,1]
//[null,1,0,1,0,0]
//......
//诸若此类。
// 
//
// 
//
// 提示： 
//
// 
// 1 <= w.length <= 10000 
// 1 <= w[i] <= 10^5 
// pickIndex 将被调用不超过 10000 次 
// 
// Related Topics 数学 二分查找 前缀和 随机化 
// 👍 105 👎 0

/*
 * 题解
我们可以先使用 partial_sum 求前缀和（即到每个位置为止之前所有数字的和），这个结果
对于正整数数组是单调递增的。每当需要采样时，我们可以先随机产生一个数字，然后使用二分
法查找其在前缀和中的位置，以模拟加权采样的过程。这里的二分法可以用 lower_bound 实现。
以样例为例，权重数组[1,3]的前缀和为[1,4]。如果我们随机生成的数字为1，那么 lower_bound
返回的位置为 0；如果我们随机生成的数字是 2、3、4，那么 lower_bound 返回的位置为 1。
关于前缀和的更多技巧，我们将在接下来的章节中继续深入讲解。
 */

#include<vector>
#include <numeric>
#include <cstdlib>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    vector<int> sums;
public:
    Solution(vector<int>& w) : sums(move(w)) {
        partial_sum(sums.begin(), sums.end(), sums.begin());
    }
    
    int pickIndex() {
        int pos = (rand() % sums.back()) + 1;
        return lower_bound(sums.begin(), sums.end(), pos) - sums.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
//leetcode submit region end(Prohibit modification and deletion)
