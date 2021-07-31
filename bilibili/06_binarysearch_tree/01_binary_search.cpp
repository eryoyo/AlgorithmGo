//
// Created by eryo on 2021/7/31.
//

#include <stdio.h>
#include <vector>

/*
	二分查找(递归版）

	已知一个排序数组A，一个乱序数组B，求B中元素在A中是否出现，结果储存在C中

	方法：二分查找、折半查找
*/

bool binary_search(std::vector<int> &sort_array, int begin, int end, int target){
    if(begin > end){
        return false;
    }
    int mid = (begin + end) / 2;
    if(target == sort_array[mid]){
        return true;
    }else if(target > sort_array[mid]){
        binary_search(sort_array, mid + 1, end, target);
    }else{
        binary_search(sort_array, begin, mid - 1, target);
    }
}

int main(){

}