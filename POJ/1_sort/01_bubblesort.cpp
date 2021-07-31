//
// Created by eryo on 2021/7/31.
//

/*
 * 冒泡排序：经历n次循环，每次都将未排序部分的最大值通过循环比较来
 * 浮到顶端，就像泡泡一样
 *
 * 是稳定排序
 */

#include<vector>
#include<iostream>

using namespace std;

void BubbleSort(vector<int> &vec){
    int temp = 0;
    int len = vec.size();
    for(int i = len - 1; i > 0; i--){
        for(int j = 0; j < i; j++){
            if(vec[j] > vec[j + 1]){
                temp = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = temp;
            }
        }//loop j
    }//loop i
}

void BubbleSort_advance(vector<int> &vec){
    int temp = 0;
    int len = vec.size();
    bool swap;
    for(int i = len - 1; i > 0; i--){
        swap = false;
        for(int j = 0; j < i; j++){
            if(vec[j] > vec[j + 1]){
                temp = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = temp;
                swap = true;
            }
        }//loop j
        if(!swap){
            break;
        }
    }//loop i
}

int main() {
    vector<int> vec = {2, 8, 1, 0, 9, 6, 5};
    int len = vec.size();
    BubbleSort(vec);
    for(int i = 0; i < len; i++){
        cout<<vec[i]<<" ";
    }
    return 0;
}