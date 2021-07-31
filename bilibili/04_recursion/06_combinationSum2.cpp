//
// Created by eryo on 2021/7/31.
//

#include <stdio.h>
#include <vector>
#include <set>
#include <algorithm>

/*
	组合数之和2-40

	已知一组数（其中有重复元素），求这组数可以组成的所有子集中，
	子集中的各个 元素和为整数target的子集，结果中无重复的子集

	方法：
		用前述的方法会超时，过多的错误尝试浪费了时间
*/

class Solution{
	public:
		std::vector<std::vector<int> > combinationSum2(std::vector<int> &candidates, int target){
			std::vector<int> item;
			std::vector<std::vector<int> > result;
			std::set<std::vector<int> > res_set;
			std::sort(candidates.begin(), candidates.end());
			result.push_back(item);
			generate(0, candidates, result, item, res_set);

			std::vector<std::vector<int> > target_result;
			for(int i = 0; i < result.size(); i++){
				int sum = 0;
				for(int j = 0; j < result[i].size(); j++){
					sum += result[i][j];
				}
				if(sum == target){
					target_result.push_back(result[i]);
				}
			}
			return target_result;
		}

	private:
		void generate(int i, std::vector<int> &nums,
						std::vector<std::vector<int> > &result,
						std::vector<int> &item,
						std::set<std::vector<int> > res_set){
			if(i >= nums.size()){
				return;
			}
			item.push_back(nums[i]);
			if(res_set.find(item) == res_set.end()){
				res_set.insert(item);
				result.push_back(item);
			}
			generate(i + 1, nums, result, item, res_set);
			item.pop_back();
			generate(i + 1, nums, result, item, res_set);
		}
};

int main(){

}