//
// Created by eryo on 2021/7/31.
//

#include <stdio.h>
#include <vector>

/*
	求子集-78

	回溯法：试探法，当探索到某一步发现该选择达不到目标，就退回一步重新选择

	已知一组数（其中无重复元素）， 求这组数可以组成的所有子集
	结果中不可以有重复的子集

	方法：
		对于每个元素都有试探放入和不放入两个选项
		选择放入该元素，递归的进行后续元素的选择

	04 48.11 1/6
*/

class Solution{
public:
    std::vector<std::vector<int> > subsets(std::vector<int>& nums){
        std::vector<std::vector<int> > result;		//存储最终结果的result
        std::vector<int> item;		//回溯时，产生各个子集的数组
        result.push_back(item);		//将空集push进result
        generate(0, nums, item, result);
        return result;
    }

private:
    void generate(int i, std::vector<int>& nums, std::vector<int>& item, std::vector<std::vector<int> >& result){
        if(i >= nums.size()){				//递归的结束条件
            return;
        }
        item.push_back(nums[i]);			//
        result.push_back(item);				//将当前生成的子集添加进入result
        generate(i + 1, nums, item, result);//第一次递归调用
        //printf("有%d完成了\n", i + 1);
        item.pop_back();					//
        generate(i + 1, nums, item, result);//第二次递归调用
        //printf("无%d完成了\n", i + 1);
    }
};

int main(){
    Solution s;
    std::vector<int> vec = {0, 1, 2, 3, 4};
    std::vector<std::vector<int> > result =  s.subsets(vec);
    for(int i = 0; i < result.size(); i++){
        for(int j = 0; j < result[i].size(); j++){
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    return 0;
}