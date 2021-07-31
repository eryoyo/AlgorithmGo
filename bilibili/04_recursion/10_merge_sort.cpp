//
// Created by eryo on 2021/7/31.
//

#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <time.h>
#include <assert.h>

/*
	预备知识-归并两个已排序数组
*/

/*
	预备知识-分治算法之归并排序

	将一个规模较大的问题分解为多个规模较小的子问题，这些问题相互独立且
	与原问题性质相同，求出这些子问题的解后进行合并就可以得到原问题的解。

	一般步骤：
		1.分解，将要解决的问题划分成若干规模较小的同类问题
		2.求解，当问题划分得足够小时，用较简单的方法求解
		3.合并，按原问题的要求，将子问题的解逐层合并构成原问题的解
*/

void merge_sort_two_vec(std::vector<int> &sub_vec1,
                        std::vector<int> &sub_vec2,
                        std::vector<int> &vec){
    int i = 0;
    int j = 0;
    while(i < sub_vec1.size() && j < sub_vec2.size()){
        if(sub_vec1[i] <= sub_vec2[j]){
            vec.push_back(sub_vec1[i]);
            i++;
        }else{
            vec.push_back(sub_vec2[j]);
            j++;
        }
    }
    for(; i < sub_vec1.size(); i++){
        vec.push_back(sub_vec1[i]);
    }
    for(; j < sub_vec2.size(); j++){
        vec.push_back(sub_vec2[j]);
    }
}

void merge_sort(std::vector<int> &vec){
    if(vec.size() < 2){
        return;
    }
    int mid = vec.size() / 2;			//对原问题进行拆解，再分别求解
    std::vector<int> sub_vec1;
    std::vector<int> sub_vec2;
    for(int i = 0; i < mid; i++){
        sub_vec1.push_back(vec[i]);
    }
    for(int i = mid; i < vec.size(); i++){
        sub_vec2.push_back(vec[i]);
    }
    merge_sort(sub_vec1);
    merge_sort(sub_vec2);
    vec.clear();
    merge_sort_two_vec(sub_vec1, sub_vec2, vec);
}

int main(){
//	std::vector<int> vec;
//	int test[] = {5, -7, 9, 8, 1, 4, -3, 10, 2, 0};
//	for(int i = 0; i < 10; i++){
//		vec.push_back(test[i]);
//	}
//	merge_sort(vec);
//	for(int i = 0; i < 10; i++){
//		printf("[%d]", vec[i]);
//	}
//	printf("\n");
//	return 0;

    std::vector<int> vec1;
    std::vector<int> vec2;
    srand(time(NULL));
    for(int i = 0; i < 10000; i++){
        int num = (rand() * rand()) % 100003;
        vec1.push_back(num);
        vec2.push_back(num);
    }
    merge_sort(vec1);
    std::sort(vec2.begin(), vec2.end());
    assert(vec1.size() == vec2.size());
    for(int i = 0; i < vec1.size(); i++){
        assert(vec1[i] == vec2[i]);
    }
    return 0;
}