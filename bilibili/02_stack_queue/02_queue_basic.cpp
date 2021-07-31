//
// Created by eryo on 2021/7/31.
//

#include <stdio.h>
#include <queue>

/*
	预备知识：STL queue队列

	Q.empty():判断队列是否为空
	Q.front():返回队列头部元素
	Q.back():返回队列尾部元素
	Q.pop():弹出队列头部元素
	Q.push(x):将x添加至队列
	Q.size(): 返回队列储存的元素个数
*/

int main(){
    std::queue<int> Q;
    if(Q.empty()){
        printf("Q is empty!\n");
    }
    Q.push(5);
    Q.push(6);
    Q.push(10);
    printf("Q.front = %d\n", Q.front());
    Q.pop();
    Q.pop();
    printf("Q.front = %d\n", Q.front());
    Q.push(1);
    printf("Q.back = %d\n", Q.back());
    printf("Q.size = %d\n", Q.size());
    return 0;
}