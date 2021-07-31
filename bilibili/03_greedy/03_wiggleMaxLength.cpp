//
// Created by eryo on 2021/7/31.
//

#include <stdio.h>
#include <vector>

/*
	摇摆序列-376

	摇摆序列：两个相邻元素的差恰好正负交替，
	一个元素数量小于二的序列直接为摇摆序列
	现给一个随机序列，求这个序列满足摇摆序列定义的最长子序列长度

	方法：
		状态机：BEGIN，UP，DOWN
		BEGIN-->		nums[i-1] = nums[i]		-->BEGIN
		BEGIN-->		nums[i-1] < nums[i]		-->UP
		BEGIN-->		nums[i-1] > nums[i]		-->DOWM
		UP-->			nums[i-1] <= nums[i]	-->UP
		UP-->			nums[i-1] > nums[i]		-->DOWM
		DOWN-->			nums[i-1] >= nums[i]	-->DOWN
		DOWN-->			nums[i-1] < nums[i]		-->UP
*/

class Solution{
public:
    int wiggleMaxLength(std::vector<int>& nums){
        if(nums.size() < 2){
            return nums.size();
        }
        static const int BEGIN = 0;
        static const int UP = 1;
        static const int DOWN = 2;
        int STATE = BEGIN;
        int max_length = 1;		//摇摆序列1最大长度至少为1
        //从第二个元素开始扫描
        for(int i = 1; i < nums.size(); i++){
            switch(STATE){
                case BEGIN:
                    if(nums[i-1] < nums[i]){
                        STATE = UP;
                        max_length++;
                    }else if(nums[i-1] > nums[i]){
                        STATE = DOWN;
                        max_length++;
                    }
                    break;
                case UP:
                    if(nums[i-1] > nums[i]){
                        STATE = DOWN;
                        max_length++;
                    }
                    break;
                case DOWN:
                    if(nums[i-1] < nums[i]){
                        STATE = UP;
                        max_length++;
                    }
                    break;
            }
        }
        return max_length;
    }
};

int main(){

}