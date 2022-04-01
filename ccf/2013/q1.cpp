//
// Created by eryo on 2021/9/23.
//

#include<bits/stdc++.h>

using namespace std;

int main(){
    map<int, int> mp;
    int max_num = 0;
    int ans = 0;
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        int temp = 0;
        scanf("%d", &temp);
        ++mp[temp];
        if(max_num < mp[temp]){
            max_num = mp[temp];
            ans = temp;
        }else if(max_num == mp[temp]){
            if(temp < ans){
                ans = temp;
            }
        }
    }
    printf("%d", ans);
}