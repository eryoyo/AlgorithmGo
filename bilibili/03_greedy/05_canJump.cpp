//
// Created by eryo on 2021/7/31.
//

#include <stdio.h>
#include <vector>

/*
	跳跃游戏-55

	一个数组储存了非负整型数据，数组中的第i个元素nums[i]，代表了可以从数组
	第i个位置最多向前跳跃nums[i]步；已知数组各元素的情况，求这个数组是否可以
	从数组的第0个位置跳跃到数组的最后一个元素的位置

	方法：
		已知nums，则有index这个数组储存第i个位置最远可以跳到的位置nums[i] + i
		每次跳跃应该跳跃到可跳跃范围内index最大的位置
*/

class Solution{
public:
    bool canJump(std::vector<int>& nums){
        std::vector<int> index;		//最远可跳至的位置
        for(int i = 0; i < nums.size(); i++){
            index.push_back(i + nums[i]);
        }
        int jump = 0;
        int max_index = index[0];
        while(jump <= max_index && jump < nums.size()){
            //循环直到jump跳到了当前可以跳到的最远位置或到达数组尾部
            if(max_index < index[jump]){
                max_index = index[jump];	//获取到更远的index时更新max_index
            }
            jump++;
        }
        if(jump == nums.size()){
            return true;
        }
        return false;
    }
};

int main(){

}