//
// Created by eryo on 2021/7/31.
//

#include <stdio.h>
#include <queue>

/*
	预备知识-STL优先级队列（二叉堆）

	big_heap.empty():判断堆是否为空
	big_heap.pop():弹出堆顶元素（最大值）
	big_heap.push(x):将元素x添加至二叉堆
	big_heap.top():返回堆顶元素（最大值）
	big_heap.size():返回堆中元素个数
*/

int main(){
    //std::priority_queue<int> big_heap;		//默认构造最大堆
    //最小堆构造方法
    std::priority_queue<int, std::vector<int>, std::greater<int> > small_heap;
    //最大堆构造方法
    std::priority_queue<int, std::vector<int>, std::less<int> > big_heap;

    if(big_heap.empty()){
        printf("big_heap is empty!\n");
    }
    int test[] = {6, 10, 1, 7, 99, 4, 33};
    for(int i = 0; i < 7; i++){
        big_heap.push(test[i]);
    }
    printf("big_heap.top = %d\n", big_heap.top());
    big_heap.push(1000);
    printf("big_heap.top = %d\n", big_heap.top());
    for(int i = 0; i < 3; i++){
        big_heap.pop();
    }
    printf("big_heap.top = %d\n", big_heap.top());
    printf("big_heap.size = %d\n", big_heap.size());
    return 0;
}