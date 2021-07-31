//
// Created by eryo on 2021/7/31.
//

#include <stdio.h>
#include <vector>
#include <set>
#include <algorithm>

/*
	求子集2-90

	已知一组数（其中有重复元素）， 求这组数可以组成的所有子集
	结果中不可以有重复的子集 [2, 1, 2]和[1, 2, 2]是重复集合

	方法：
		先对数据进行排序然后用set去重复

	04 77:55 2/6
*/

class Solution{
public:
    std::vector<std::vector<int> > subsetsWithDup(std::vector<int>& nums){
        std::vector<std::vector<int> > result;
        std::vector<int> item;
        std::set<std::vector<int> > res_set;		//去重的set
        std::sort(nums.begin(), nums.end());		//对数组进行排序
        result.push_back(item);
        generate(0, nums, result, item, res_set);
        return result;
    }
private:
    void generate(int i,
                  std::vector<int>& nums,
                  std::vector<std::vector<int> > &result,
                  std::vector<int> &item,
                  std::set<std::vector<int> > res_set){
        if(i >= nums.size()){
            return;
        }
        item.push_back(nums[i]);
        if(res_set.find(item) == res_set.end()){
            result.push_back(item);
            res_set.insert(item);
        }
        generate(i + 1, nums, result, item, res_set);
        item.pop_back();
        generate(i + 1, nums, result, item, res_set);
    }
};

int main(){
    Solution s;
    std::vector<int> vec = {0, 1, 2, 3, 4};
    std::vector<std::vector<int> > result =  s.subsetsWithDup(vec);
    for(int i = 0; i < result.size(); i++){
        for(int j = 0; j < result[i].size(); j++){
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    return 0;
}