//
// Created by eryo on 2021/7/31.
//

#include <stdio.h>
#include <stack>
#include <queue>

/*
	合法的出栈序列-POJ-1363

	已知从1至n的数字序列，按顺序入栈，每个数字入栈后即可出栈
	也可在栈中停留，等待后面的数字入栈出栈后，该数字再出栈，
	求该数字序列的出栈序列是否合法

	方法：
		将元素顺序入栈，进行模拟，如果可以模拟出来则说明序列正确
		1.出栈结果储存在队列order中
		2.按元素顺序，将元素push到栈中
		3.每次push一个元素，检查1是否与队列首部元素相同，如果相同就弹出队列首元素
		  弹出栈顶元素，直到两元素不相等为止
		4.若最后栈为空，说明序列合法，否则不合法
*/

//检查序列（储存在队列中）
bool check_is_valid_order(std::queue<int> &order){
    std::stack<int> S;		//S为模拟栈
    int n = order.size();
    for(int i = 1; i <= n; i++){
        S.push(i);
        while(!S.empty() && order.front() == S.top()){
            order.pop();
            S.pop();
        }
    }
    if(!S.empty()){
        return false;
    }
    return true;
}

int main(){
    int n;
    int train;
    scanf("%d", &n);
    while(n){
        scanf("%d", &train);
        while(train){
            std::queue<int> order;
            order.push(train);
            for(int i = 1; i < n; i++){
                scanf("%d", &train);
                order.push(train);
            }
            if(check_is_valid_order(order)){
                printf("Yes\n");
            }else{
                printf("No\n");
            }
            scanf("%d", &train);
        }
        printf("\n");
        scanf("%d", &n);
    }
    return 0;
}