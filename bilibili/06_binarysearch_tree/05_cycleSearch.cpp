//
// Created by eryo on 2021/7/31.
//

#include <stdio.h>
#include <vector>

/*
	旋转数组查找-33

	给定一个排序数组nums（nums中无重复元素），且nums可能以某个未知下标旋转
	给定目标值target，求target是否在nums中出现，若出现返回所在下标，否则返回-1

	方法：
		总有nums[begin] > nums[end]
		1.target < nums[mid]
		如果nums[begin] < nums[mid]
			递增区间：[begin, mid - 1]		target >= nums[begin]
			旋转区间：[mid + 1, end]		target < nums[begin]
		如果nums[begin] > nums[mid]
			旋转区间：[begin, mid - 1]		target接下来在旋转区间找
			递增区间：[mid + 1, end]
		如果nums[begin] = nums[mid]
			[mid + 1, end]					target在这个区间寻找例如[6, 1]
		2.target > nums[mid]
		如果nums[begin] < nums[mid]
			递增区间：[begin, mid - 1]
			旋转区间：[mid + 1, end]		target在旋转区间找
		如果nums[begin] > nums[mid]
			旋转区间：[begin, mid - 1]		target >= nums[begin]
			递增区间：[mid + 1, end]		target <nums[begin]
		如果nums[begin] = nums[mid]
			[mid + 1, end]					target在这个区间寻找例如[6, 7]

	06 114:17 3/5
*/

class Solution{
public:
    int search(std::vector<int>& nums, int target){
        int begin = 0;
        int end = nums.size() - 1;
        while(begin <= end){
            int mid = (begin + end) / 2;
            if(target == nums[mid]){
                return mid;
            }else if(target < nums[mid]){
                if(nums[begin] < nums[mid]){
                    if(target >= nums[begin]){
                        end = mid - 1;
                    }else{
                        begin = mid + 1;
                    }
                }else if(nums[begin] > nums[mid]){
                    end = mid - 1;
                }else if(nums[begin] == nums[mid]){
                    begin = mid + 1;
                }
            }else if(target > nums[mid]){
                if(nums[begin] < nums[mid]){
                    begin = mid + 1;
                }else if(nums[begin] > nums[mid]){
                    if(target >= nums[begin]){
                        end = mid - 1;
                    }else{
                        begin = mid + 1;
                    }
                }else if(nums[begin] == nums[mid]){
                    begin = mid + 1;
                }
            }
        }
        return -1;
    }
};

int main(){

}