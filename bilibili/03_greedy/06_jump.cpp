//
// Created by eryo on 2021/7/31.
//

#include <stdio.h>
#include <vector>

/*
	跳跃游戏-45

	一个数组储存了非负整型数据，数组中的第i个元素nums[i]，代表了可以从数组
	第i个位置最多向前跳跃nums[i]步；已知数组各元素的情况，已知这个数组可以
	从数组的第0个位置跳跃到数组的最后一个元素的位置，求最少需要跳跃几次

	方法：
		已知nums，则有index这个数组储存第i个位置最远可以跳到的位置nums[i] + i
		每次跳跃应该跳跃到可跳跃范围内index最大的位置

	03 162:37 5/7
*/

class Solution{
	public:
		int jump(std::vector<int>& nums){
			if(nums.size() < 2){
				return 0;				//如果数组长度小于2说明可以不用跳跃
			}
			int current_max_index = nums[0];	//当前可到达的最远位置
			int pre_max_max_index = nums[0];	//记录当前可跳跃范围内的最远位置
			int jump_min = 1;
			for(int i = 1; i < nums.size(); i++){	//若无法再向前移动了，才进行跳跃，即更新当前可达到的最远位置
				if(i > current_max_index){
					jump_min++;
					current_max_index = pre_max_max_index;
				}
				if(pre_max_max_index < nums[i] + i){
					pre_max_max_index = nums[i] + i;
				}
			}
			return jump_min;
		}
};

int main(){

}