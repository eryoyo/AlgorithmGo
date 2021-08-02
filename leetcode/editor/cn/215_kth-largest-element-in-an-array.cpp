//给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。 
//
// 请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。 
//
// 
//
// 示例 1: 
//
// 
//输入: [3,2,1,5,6,4] 和 k = 2
//输出: 5
// 
//
// 示例 2: 
//
// 
//输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
//输出: 4 
//
// 
//
// 提示： 
//
// 
// 1 <= k <= nums.length <= 104 
// -104 <= nums[i] <= 104 
// 
// Related Topics 数组 分治 快速选择 排序 堆（优先队列） 
// 👍 1204 👎 0

/*
 * 题解
快速选择一般用于求解 k-th Element 问题，可以在 O(n) 时间复杂度，O(1) 空间复杂度完成求
解工作。快速选择的实现和快速排序相似，不过只需要找到第 k 大的枢（pivot）即可，不需要对
其左右再进行排序。与快速排序一样，快速选择一般需要先打乱数组，否则最坏情况下时间复杂
度为 O(n2)，我们这里为了方便省略掉了打乱的步骤。
 */

#include<vector>
#include<iostream>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int l = 0;
        int r = nums.size() - 1;
        int target = nums.size() - k;
        while(l < r){
            int mid = quickSelection(nums, l, r);
            if(mid == target){
                return nums[mid];
            }
            if(mid < target){
                l = mid + 1;
            } else{
                r = mid - 1;
            }
        }
        return nums[l];
    }

    int quickSelection(vector<int> &nums, int l, int r){
        int i = l + 1;
        int j = r;
        while(true){
            while(i < r && nums[i] <= nums[l]){
                ++i;
            }
            while(l < j && nums[j] >= nums[l]){
                --j;
            }
            if(i >= j){
                break;
            }
            swap(nums[i], nums[j]);
        }
        swap(nums[l], nums[j]);
        return j;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
