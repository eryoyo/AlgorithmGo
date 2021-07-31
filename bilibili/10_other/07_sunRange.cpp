//
// Created by eryo on 2021/7/31.
//

#include <stdio.h>
#include <vector>

/*
	区域和的查询-307

	给定一个整数数组nums，求这个整数数组中，下标i到下标j之间的数字和(i <= j)，
	在求和的过程中可能需要更新数组的某个元素a[i]
*/

class NumArray{
public:
    NumArray(std::vector<int> nums){
        if(nums.size() == 0){
            return;
        }
        int n = nums.size() * 4;
        for(int i = 0; i < n; i++){
            _value.push_back(0);
        }
        build_segment_tree(_value, nums, 0, 0, nums.size() - 1);
        _right_end = nums.size() - 1;
    }
    //将位置i上的数字变为val，i从0开始
    void update(int i, int val){
        update_segment_tree(_value, 0, 0, _right_end, i, val);
    }
    //包括nums[i]和nums[j]
    int sumRange(int i, int j){
        return sum_range_segment_tree(_value, 0, 0, _right_end, i, j);
    }
private:
    std::vector<int> _value;
    int _right_end;
};