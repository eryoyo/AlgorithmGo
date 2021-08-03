//给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [1,2,3]
//输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
// 
//
// 示例 2： 
//
// 
//输入：nums = [0,1]
//输出：[[0,1],[1,0]]
// 
//
// 示例 3： 
//
// 
//输入：nums = [1]
//输出：[[1]]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 6 
// -10 <= nums[i] <= 10 
// nums 中的所有整数 互不相同 
// 
// Related Topics 数组 回溯 
// 👍 1474 👎 0

/*
 * 题解
怎样输出所有的排列方式呢？对于每一个当前位置 i，我们可以将其于之后的任意位置交换，
然后继续处理位置 i+1，直到处理到最后一位。为了防止我们每此遍历时都要新建一个子数组储
存位置 i 之前已经交换好的数字，我们可以利用回溯法，只对原数组进行修改，在递归完成后再
修改回来。
我们以样例[1,2,3]为例，按照这种方法，我们输出的数组顺序为[[1,2,3], [1,3,2], [2,1,3], [2,3,1],
[3,1,2], [3,2,1]]，可以看到所有的排列在这个算法中都被考虑到了。
 */

#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        backtracking(nums, 0, ans);
        return ans;
    }

    void backtracking(vector<int> &nums, int level, vector<vector<int>> &ans){
        if(level == nums.size() - 1){
            ans.push_back(nums);
            return;
        }
        for(int i = level; i < nums.size(); i++){
            swap(nums[i], nums[level]);
            backtracking(nums, level + 1, ans);
            swap(nums[i], nums[level]);
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)
