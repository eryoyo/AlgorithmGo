//给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。 
//
// 如果数组中不存在目标值 target，返回 [-1, -1]。 
//
// 进阶： 
//
// 
// 你可以设计并实现时间复杂度为 O(log n) 的算法解决此问题吗？ 
// 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [5,7,7,8,8,10], target = 8
//输出：[3,4] 
//
// 示例 2： 
//
// 
//输入：nums = [5,7,7,8,8,10], target = 6
//输出：[-1,-1] 
//
// 示例 3： 
//
// 
//输入：nums = [], target = 0
//输出：[-1,-1] 
//
// 
//
// 提示： 
//
// 
// 0 <= nums.length <= 105 
// -109 <= nums[i] <= 109 
// nums 是一个非递减数组 
// -109 <= target <= 109 
// 
// Related Topics 数组 二分查找 
// 👍 1126 👎 0

/*
 * 题解
这道题可以看作是自己实现 C++ 里的 lower_bound 和 upper_bound 函数。这里我们尝试
使用左闭右开的写法，当然左闭右闭也可以。
 */

#include<vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int lower_bound(vector<int>& nums, int target){
        int left = 0;
        int right = nums.size();
        int mid;
        while(left < right){
            mid = left + (right - left) / 2;
            if(nums[mid] >= target){
                right = mid;
            } else{
                left = mid + 1;
            }
        }
        return left;
    }

    int upper_bound(vector<int> &nums, int target){
        int left = 0;
        int right = nums.size();
        int mid;
        while(left < right){
            mid = left + (right - left) / 2;
            if(nums[mid] > target){
                right = mid;
            } else{
                left = mid + 1;
            }
        }
        return left;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty()){
            return vector<int>{-1, -1};
        }
        int lower = lower_bound(nums, target);
        int upper = upper_bound(nums, target) - 1;
        if(lower == nums.size() || nums[lower] != target){
            return vector<int>{-1, -1};
        }
        return vector<int>{lower, upper};
    }
};
//leetcode submit region end(Prohibit modification and deletion)
