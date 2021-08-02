//
// Created by eryo on 2021/8/2.
//

#include<vector>
#include<iostream>

using namespace std;

void selection_sort(vector<int> &nums, int n){
    int mid;
    for(int i = 0; i < n - 1; ++i){
        mid = i;
        for(int j = i + 1; j < n; ++j){
            if(nums[j] < nums[mid]){
                mid = j;
            }
        }
        swap(nums[mid], nums[i]);
    }
}

int main(){
    vector<int> nums = {2, 6, 9, 8, 5, 3};
    selection_sort(nums, nums.size());
    for(int i = 0; i < nums.size(); i++){
        cout<<nums[i]<<" ";
    }
}