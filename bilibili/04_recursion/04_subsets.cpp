//
// Created by eryo on 2021/7/31.
//

#include <stdio.h>
#include <vector>

/*
	求子集-78

	已知一组数（其中无重复元素）， 求这组数可以组成的所有子集
	结果中不可以有重复的子集

	&：按位与
	|：按位或
	^：按位异或， 相同取0，不同取1
	<<：左移，乘以2
	>>：右移，除以2

	方法：集合可以看做二进制数
	例如A用100表示，用100与某数判断A是否出现
*/

class Solution{
public:
    std::vector<std::vector<int> > subsets(std::vector<int>& nums){
        std::vector<std::vector<int> > result;
        int all_set = 1<<nums.size();		//1<<n即为2^n
        for(int i = 0; i < all_set; i++){	//遍历所有集合
            std::vector<int> item;
            for(int j = 0; j < nums.size(); j++){
                if(i & (1<<j)){
                    item.push_back(nums[j]);
                }
            }
            result.push_back(item);
        }
        return result;
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