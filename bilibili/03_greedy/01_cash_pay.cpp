//
// Created by eryo on 2021/7/31.
//

#include <stdio.h>

/*
	预备知识-贪心法，钞票支付问题

	有1元，5元 ，10元，20元，100元，200元的钞票无穷多张，
	用这些钞票支付X元，最少需要多少张

	方法：
		尽可能多的使用面值较大的钞票
*/

int main(){
    const int RMB[] = {200, 100, 20, 10, 5, 1};	//钞票金额
    const int NUM = 6;		//6种面值
    int X = 628;
    int count = 0;
    for(int i = 0; i < NUM; i++){
        int use = X / RMB[i];
        count += use;
        X = X - RMB[i] * use;
        printf("需要面额为%d的%d张，", RMB[i], use);
        printf("剩余需要支付金额%d.\n", X);
    }
    printf("总共需要%d张\n", count);
    return 0;
}