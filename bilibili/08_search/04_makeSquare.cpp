//
// Created by eryo on 2021/7/31.
//

#include <stdio.h>
#include <vector>
#include <algorithm>

/*
	火柴棍摆正方形-473

	已知一个数组，保存了n个火柴棍，n <= 15, 问是否可以用这n个火柴摆成一个正方形

*/

class Solution{
	public:
		bool makesquare(std::vector<int>& nums){
			if(nums.size() < 4){
				return false;
			}
			int sum = 0;
			for(int i = 0; i < nums.size(); i++){
				sum += nums[i];
			}
			if(sum % 4 != 0){
				return false;
			}
			std::sort(nums.rbegin(), nums.rend());
			int bucket[4] = {0};
			return generate(0, nums, sum / 4, bucket);
		}

		bool generate(int i, std::vector<int>& nums, int target, int bucket[]){
			if(i == nums.size()){
				return bucket[0] == target && bucket[1] == target
					&& bucket[2] == target && bucket[3] == target;
			}
			for(int j = 0; j < 4; j++){
				if(bucket[j] + nums[i] > target){
					continue;
				}
				bucket[j] += nums[i];
				if(generate(i + 1, nums, target, bucket)){
					return true;
				}
				bucket[j] -= nums[i];
			}
			return false;
		}
};

int main(){
	std::vector<int> nums;
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(4);
	nums.push_back(3);
	nums.push_back(2);
	nums.push_back(3);
	Solution s;
	printf("%d\n", s.makesquare(nums));
	return 0;
}