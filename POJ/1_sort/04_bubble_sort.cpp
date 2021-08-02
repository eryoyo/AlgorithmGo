//
// Created by eryo on 2021/8/2.
//

#include<vector>
#include<iostream>

using namespace std;

void bubble_sort(vector<int> &nums, int n){
    bool swapped;
    for(int i = 1; i < n; ++i){
        swapped = false;
        for(int j = 1; j < n - i + 1; ++j){
            if(nums[j] < nums[j - 1]){
                swap(nums[j], nums[j - 1]);
                swapped = true;
            }
        }
        if(!swapped){
            break;
        }
    }
}

int main(){
    vector<int> nums = {2, 6, 9, 8, 5, 3};
    bubble_sort(nums, nums.size());
    for(int i = 0; i < nums.size(); i++){
        cout<<nums[i]<<" ";
    }
}