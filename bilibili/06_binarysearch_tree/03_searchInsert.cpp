//
// Created by eryo on 2021/7/31.
//

#include <stdio.h>
#include <vector>

/*
	插入位置-35

	给定一个排序数组nums（无重复元素）与目标值target，如果target在nums里面出现
	则返回target所在下标，如果target在nums里面未出现，则返回target应该插入位置的数组下标
	使得将target插入数组nums后，数组仍有序

	06 47.20 1/5
*/

class Solution{
public:
    int searchInsert(std::vector<int> &nums, int target){
        int index = -1;		//最终返回的下标，若找到则为该元素的下标，否则为要插入的位置
        int begin = 0;				//搜索区间左端点
        int end = nums.size() - 1;	// 搜索区间右端点
        while(index == -1){
            int mid = (begin + end) / 2;
            if(target == nums[mid]){
                index = mid;
            }else if(target < nums[mid]){
                if(mid == 0 || target > nums[mid - 1]){
                    index = mid;
                }
                end = mid - 1;
            }else if(target > nums[mid]){
                if(mid == nums.size() - 1 || target < nums[mid + 1]){
                    index = mid + 1;
                }
                begin = mid + 1;
            }
        }
        return index;
    }
};