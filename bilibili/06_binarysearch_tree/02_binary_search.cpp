//
// Created by eryo on 2021/7/31.
//

#include <stdio.h>
#include <vector>

/*
	二分查找（循环版）
*/

bool binary_search(std::vector<int> sort_array, int target){
    int begin = 0;
    int end = sort_array.size() - 1;
    while(begin <= end){
        int mid = (begin + end) / 2;
        if(target == sort_array[mid]){
            return true;
        }else if(target > sort_array[mid]){
            begin = mid + 1;
        }else if(target < sort_array[mid]){
            end = mid - 1;
        }
    }
    return false;
}