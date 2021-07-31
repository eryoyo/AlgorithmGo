//
// Created by eryo on 2021/7/31.
//
#include <stdio.h>
#include <vector>

/*
	最长上升子序列-300

	已知一个未排序数组，求这个数组最长上升子序列的长度

	方法：
		使用一个栈，stack[i]代表长度为i+1的上升子序列最后
		一个元素的最小可能取值
		复杂度：由n^2优化到nlogn
*/

class Solution{
public:
    int binary_search(std::vector<int> nums, int target){
        int index = -1;
        int begin = 0;
        int end = nums.size() - 1;
        while(index == -1){
            int mid = (begin + end) / 2;
            if(target == nums[mid]){
                index = mid;
            }else if(target > nums[mid]){
                if(mid == nums.size() - 1 || target < nums[mid + 1]){
                    index = mid + 1;
                }else{
                    begin = mid + 1;
                }
            }else{
                if(mid == 0 || target < nums[mid - 1]){
                    index = mid
                }else{
                    end = mid - 1;
                }
            }
        }
        return index;
    }

    int lengthOfLIS(std::vector<int>& nums){
        if(nums.size() == 0){
            return 0;
        }
        std::vector<int> stack;
        stack.push_back(nums[0]);
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > stack.back()){
                stack.push_back(nums[i]);
            }else{
                int pos = binary_search(stack, nums[i]);
                stack[pos] = nums[i];
            }
        }
        return stack.size();
    }
};