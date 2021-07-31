//
// Created by eryo on 2021/7/31.
//

#include <stdio.h>
#include <vector>

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
        if(sum % 4){
            return false;
        }
        int target = sum / 4;
        std::vector<int> ok_subset;	//满足和为target的边组合集合
        std::vector<int> ok_half;	//满足条件的两条边的集合
        int all = 1 << nums.size();
        for(int i = 0; i < all; i++){
            int sum = 0;
            for(int j = 0; j < nums.size(); j++){
                if(i & (1 << j)){
                    sum += nums[j];
                }
            }
            if(sum == target){
                ok_subset.push_back(i);
            }
        }
        for(int i = 0; i < ok_subset.size(); i++){
            for(int j = i + 1; j < ok_subset.size(); j++){
                if((ok_subset[i] & ok_subset[j]) == 0){
                    ok_half.push_back(ok_subset[i] | ok_subset[j]);
                }
            }
        }
        for(int i = 0; i < ok_half.size(); i++){
            for(int j = i + 1; j < ok_half.size(); j++){
                if((ok_half[i] & ok_half[j]) == 0){
                    return true;
                }
            }
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