//
// Created by eryo on 2021/7/31.
//

#include <stdio.h>
#include <queue>
#include <vector>

/*
	数组中第k大的数-215

	已知一个未排序的数组，求这个数组中第k大的数

	方法：
		维护一个K大小的堆，当堆中元素数量小于K时，直接加到堆里面，
		否则，当新元素大于堆顶元素就弹出堆顶，将新元素加入到堆。
*/

class Solution{
public:
    int findKthLargest(std::vector<int>& nums, int k){
        std::priority_queue<int, std::vector<int>, std::greater<int> > Q;
        for(int i = 0; i < nums.size(); i++){
            if(Q.size() < k){
                Q.push(nums[i]);
            }else if(Q.top() < nums[i]){
                Q.pop();
                Q.push(nums[i]);
            }
        }
        return Q.top();
    }
};

int main(){

}