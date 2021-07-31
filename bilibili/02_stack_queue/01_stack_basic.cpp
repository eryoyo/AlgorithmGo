//
// Created by eryo on 2021/7/31.
//

#include <stdio.h>
#include <stack>

/*
	预备知识：STL stack栈

	S.top():取出栈顶
	S.empty():判断栈是否为空
	S.push(x):将x添加到栈
	S.pop():弹出栈顶
	S.size():栈存储元素的个数
*/

int main(){
    std::stack<int> S;
    if(S.empty()){
        printf("S is empty!\n");
    }
    S.push(5);
    S.push(6);
    S.push(10);
    printf("S.top = %d\n", S.top());
    S.pop();
    S.pop();
    printf("S.top = %d\n", S.top());
    printf("S.size = %d\n", S.size());
    return 0;
}