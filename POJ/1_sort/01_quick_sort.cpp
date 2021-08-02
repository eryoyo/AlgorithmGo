//
// Created by eryo on 2021/8/2.
//

#include<vector>
#include <iostream>

using namespace std;

void quick_sort(vector<int> &nums, int l, int r){
    if(l + 1 >= r){
        return;
    }
    int first = l;
    int last = r - 1;
    int key = nums[first];
    while(first < last){
        while(first < last && nums[last] >= key){
            --last;
        }
        nums[first] = nums[last];
        while(first < last && nums[first] <= key){
            ++first;
        }
        nums[last] = nums[first];
    }
    nums[first] = key;
    quick_sort(nums, l, first);
    quick_sort(nums, first + 1, r);
}

int main(){
    vector<int> nums = {2, 6, 9, 8, 5, 3};
    quick_sort(nums, 0, nums.size());
    for(int i = 0; i < nums.size(); i++){
        cout<<nums[i]<<" ";
    }
}