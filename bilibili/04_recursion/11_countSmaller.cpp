//
// Created by eryo on 2021/7/31.
//

#include <stdio.h>
#include <vector>

/*
	逆序数-315

	已知数组nums，求新数组count，
	count[i]代表在nums[i]右侧且比nums[i]小的元素个数


*/

class Solution{
public:
    std::vector<int> countSmaller(std::vector<int> &nums){
        std::vector<std::pair<int, int> > vec;
        std::vector<int> count;
        for(int i = 0; i < nums.size(); i++){
            vec.push_back(std::make_pair(nums[i], i));
            count.push_back(0);
        }
        merge_sort(vec, count);
        return count;
    }

private:
    void merge_sort_two_vec(std::vector<std::pair<int, int> > &sub_vec1,
                            std::vector<std::pair<int, int> > &sub_vec2,
                            std::vector<std::pair<int, int> > &vec,
                            std::vector<int> &count){
        int i = 0;
        int j = 0;
        while(i < sub_vec1.size() && j < sub_vec2.size()){
            if(sub_vec1[i].first <= sub_vec2[j].first){
                vec.push_back(sub_vec1[i]);
                count[sub_vec1[i].second] += j;		//!!!!!!!!!!!!
                i++;
            }else{
                vec.push_back(sub_vec2[j]);
                j++;
            }
        }
        for(; i < sub_vec1.size(); i++){
            vec.push_back(sub_vec1[i]);
            count[sub_vec1[i].second] += j;			//!!!!!!!!!!!
        }
        for(; j < sub_vec2.size(); j++){
            vec.push_back(sub_vec2[j]);
        }
    }

    void merge_sort(std::vector<std::pair<int, int> > &vec,
                    std::vector<int> &count){
        if(vec.size() < 2){
            return;
        }
        int mid = vec.size() / 2;			//对原问题进行拆解，再分别求解
        std::vector<std::pair<int, int> > sub_vec1;
        std::vector<std::pair<int, int> > sub_vec2;
        for(int i = 0; i < mid; i++){
            sub_vec1.push_back(vec[i]);
        }
        for(int i = mid; i < vec.size(); i++){
            sub_vec2.push_back(vec[i]);
        }
        merge_sort(sub_vec1, count);
        merge_sort(sub_vec2, count);
        vec.clear();
        merge_sort_two_vec(sub_vec1, sub_vec2, vec, count);
    }
};

int main(){
    std::vector<int> vec;
    int test[] = {5, -7, 9, 1, 3, 5, -2, 1};
    for(int i = 0; i < 8; i++){
        vec.push_back(test[i]);
    }
    Solution s;
    std::vector<int> result = s.countSmaller(vec);
    for(int i = 0; i < result.size(); i++){
        printf("[%d]", result[i]);
    }
    printf("\n");
    return 0;
}