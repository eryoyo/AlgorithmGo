//
// Created by eryo on 2021/9/6.
//

//字符串hash
/*
 将字符串看成26进制的数

 这样会导致产生的整数很大的情况，所以可以将进制数设成10^7的素数
 将mod设置成10^9的素数，这样既能使字符串转换为大小可以接受的整数
 发生冲突的概率也会减小
 */

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

const int MOD = 1000000007; //1e9+7
const int P = 10000019; //1e7+19

vector<int> ans;

long long hashFunc(string str){
    long long H = 0;
    for(int i = 0; i < str.length(); ++i){
        H = (H * P + str[i] - 'a') % MOD;
    }
    return H;
}