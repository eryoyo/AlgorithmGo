//给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。 
//
// 你可以按 任何顺序 返回答案。 
//
// 
//
// 示例 1： 
//
// 
//输入：n = 4, k = 2
//输出：
//[
//  [2,4],
//  [3,4],
//  [2,3],
//  [1,2],
//  [1,3],
//  [1,4],
//] 
//
// 示例 2： 
//
// 
//输入：n = 1, k = 1
//输出：[[1]] 
//
// 
//
// 提示： 
//
// 
// 1 <= n <= 20 
// 1 <= k <= n 
// 
// Related Topics 数组 回溯 
// 👍 639 👎 0

/*
 * 题解
类似于排列问题，我们也可以进行回溯。排列回溯的是交换的位置，而组合回溯的是否把当
前的数字加入结果中。
 */

#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> comb(k, 0);
        int count = 0;
        backtracking(ans, comb, count, 1, n, k);
        return ans;
    }

    void backtracking(vector<vector<int>>& ans, vector<int>& comb,
                      int& count, int pos, int n, int k){
        if(count == k){
            ans.push_back(comb);
            return;
        }
        for(int i = pos; i <= n; ++i){
            comb[count++] = i;
            backtracking(ans, comb, count, i + 1, n, k);
            --count;
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)
