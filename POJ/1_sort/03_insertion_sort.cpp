//
// Created by eryo on 2021/8/2.
//

#include<vector>
#include<iostream>

using namespace std;

void insertion_sort(vector<int> &nums, int n){
    for(int i = 0; i < n; ++i){
        for(int j = i; j > 0 && nums[j] < nums[j - 1]; --j){
            swap(nums[j], nums[j - 1]);
        }
    }
}

int main(){
    vector<int> nums = {2, 6, 9, 8, 5, 3};
    insertion_sort(nums, nums.size());
    for(int i = 0; i < nums.size(); i++){
        cout<<nums[i]<<" ";
    }
}