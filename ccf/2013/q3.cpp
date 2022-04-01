//
// Created by eryo on 2021/9/23.
//

#include<bits/stdc++.h>

using namespace std;

int main(){
    int n = 0;
    scanf("%d", &n);
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for(int i = 1; i <= n; ++i){
        scanf("%d", &dp[1][i]);
    }
    int ans = 0;
    for(int i = 2; i <= n; ++i){
        for(int j = 1; j <= n - i + 1; ++j){
            if(dp[1][j + i - 1] < dp[i - 1][j]){
                dp[i][j] = dp[1][j + i - 1];
            }else{
                dp[i][j] = dp[i - 1][j];
            }
            ans = max(ans, i * dp[i][j]);
        }
    }
    printf("%d", ans);
}