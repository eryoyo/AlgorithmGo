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
		进行剪枝操作，递归调用时，计算已选择元素的和sum，若sum>target
		不进行更深的搜索，直接返回

	04 101:18 3/6
*/

class Solution{
	public:
		std::vector<std::vector<int> > combinationSum2(std::vector<int> &candidates, int target){
			std::vector<int> item;
			std::vector<std::vector<int> > result;
			std::set<std::vector<int> > res_set;
			std::sort(candidates.begin(), candidates.end());
			result.push_back(item);
			generate(0, candidates, result, item, res_set, 0, target);
			return result;
		}

	private:
		void generate(int i, std::vector<int> &nums,
						std::vector<std::vector<int> > &result,
						std::vector<int> &item,
						std::set<std::vector<int> > res_set,
						int sum, int target){	//sum为当前子集item中的元素和
			if(i >= nums.size() || sum > target){	//剪枝条件
				return;		//当元素已经被选完或者元素和超过了target
			}
			sum += nums[i];
			item.push_back(nums[i]);
			if(sum == target && res_set.find(item) == res_set.end()){
				res_set.insert(item);
				result.push_back(item);
			}
			generate(i + 1, nums, result, item, res_set, sum, target);
			sum -= nums[i];		//回溯后，sum将nums[i]减去
			item.pop_back();
			generate(i + 1, nums, result, item, res_set, sum, target);
		}
};

int main(){

}