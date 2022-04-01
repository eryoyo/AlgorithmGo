//
// Created by eryo on 2021/9/23.
//

#include<bits/stdc++.h>

using namespace std;

int main(){
    int n = 0;
    scanf("%d", &n);
    int sum = 3;
    int mod = 1e9 + 7;
    for(int i = 5; i <= n; ++i){
        sum = sum * (i * 10 - 1) % mod;
    }
    printf("%d", sum);
}