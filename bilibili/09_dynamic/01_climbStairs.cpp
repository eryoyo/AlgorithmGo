//
// Created by eryo on 2021/7/31.
//

#include <stdio.h>

/*
	爬楼梯-70

	在爬楼梯时，每次可向上走一阶台阶或两阶台阶，问有n阶楼梯有多少种上楼方式
*/

class Solution{
public:
    int climbStairs(int n){
        if(n == 1 || n == 2){
            return n;
        }
        //第一步总共有两种解法，分别剩下n-1阶台阶和n-2阶台阶，递归
        return climbStairs(n - 1) + climbStairs(n - 2);
    }
};