//
// Created by eryo on 2021/7/31.
//

#include <stdio.h>

/*
	递归函数

*/

void compute_sum(int i, int &sum){
    if(i > 3){
        return;			//i>3时，结束递归调用
    }
    sum += i;
    compute_sum(i + 1, sum);
}

int main(){
    int sum = 0;
    compute_sum(1, sum);
    printf("sum = %d\n", sum);
    return 0;
}