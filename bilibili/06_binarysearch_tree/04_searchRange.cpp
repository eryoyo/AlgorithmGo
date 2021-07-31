//
// Created by eryo on 2021/7/31.
//

#include <stdio.h>
#include <vector>

/*
	区间查找-34

	给定一个排序数组nums和目标值target，其中nums里有重复元素，
	如果target在nums里面存在 ，则返回target所在区间所在的左右端点下标，
	如果未出现，则返回[-1, -1]

	方法：
		 寻找左右端点

	06 67:38 2/5
*/

class Solution{
public:
    int left_bound(std::vector<int>& nums, int target){
        int begin = 0;
        int end = nums.size() - 1;
        while(begin <= end){
            int mid = (begin + end) / 2;
            if(target == nums[mid]){
                if(mid == 0 || nums[mid - 1] < target){		//为左端点的条件
                    return mid;
                }
                end = mid - 1;
            }else if(target > nums[mid]){
                begin = mid + 1;
            }else if(target < nums[mid]){
                end = mid - 1;
            }
        }
        return -1;
    }

    int right_bound(std::vector<int>& nums, int target){
        int begin = 0;
        int end = nums.size() - 1;
        while(begin <= end){
            int mid = (begin + end) / 2;
            if(target == nums[mid]){
                if(mid == nums.size() - 1 || nums[mid + 1] > target){	//为右端点的条件
                    return mid;
                }
                begin = mid + 1;
            }else if(target > nums[mid]){
                begin = mid + 1;
            }else if(target < nums[mid]){
                end = mid - 1;
            }
        }
        return -1;
    }

    std::vector<int> searchRange(std::vector<int>& nums, int target){
        std::vector<int> result;
        result.push_back(left_bound(nums, target));
        result.push_back(right_bound(nums, target));
        return result;
    }
};

int main(){
    int test[] = {5, 7, 7, 8, 8, 8, 8, 10};
    Solution s;
    std::vector<int> nums;
    for(int i = 0; i < 8; i++){
        nums.push_back(test[i]);
    }
    for(int i = 0; i < 12; i++){
        std::vector<int> result = s.searchRange(nums, i);
        printf("%d : [%d, %d]\n", i, result[0], result[1]);
    }
    return 0;
}