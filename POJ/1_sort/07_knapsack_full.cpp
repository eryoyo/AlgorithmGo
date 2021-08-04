//
// Created by eryo on 2021/8/4.
//

/*
 * 在完全背包问题中，一个物品可以拿多次。如图上半部分所示，假设我们遍历到物品 i = 2，
且其体积为 w = 2，价值为 v = 3；对于背包容量 j = 5，最多只能装下 2 个该物品。那么我们的状
态转移方程就变成了 dp[2][5] = max(dp[1][5], dp[1][3] + 3, dp[1][1] + 6)。如果采用这种方法，假设
背包容量无穷大而物体的体积无穷小，我们这里的比较次数也会趋近于无穷大，远超 O(NW) 的
时间复杂度。
怎么解决这个问题呢？我们发现在 dp[2][3] 的时候我们其实已经考虑了 dp[1][3] 和 dp[2][1]
的情况，而在时 dp[2][1] 也已经考虑了 dp[1][1] 的情况。因此，如图下半部分所示，对于拿多个
物品的情况，我们只需考虑 dp[2][3] 即可，即 dp[2][5] = max(dp[1][5], dp[2][3] + 3)。这样，我们
就得到了完全背包问题的状态转移方程：dp[i][j] = max(dp[i-1][j], dp[i][j-w] + v)，其与 0-1 背包问
题的差别仅仅是把状态转移方程中的第二个 i-1 变成了 i。
 */

#include<vector>
#include<iostream>

using namespace std;

int knapsack_full(vector<int> weights, vector<int> values, int N, int W){
    vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));
    for(int i = 1; i <= N; ++i){
        int w = weights[i - 1];
        int v = values[i - 1];
        for(int j = 1; j <= W; ++j){
            if(j >= w){
                dp[i][j] = max(dp[i - 1][j], dp[i][j - w] + v);
            }else{
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[N][W];
}

int knapsack_full_advance(vector<int> weights, vector<int> values, int N, int W){
    vector<int> dp(W + 1, 0);
    for(int i = 1; i <= N; ++i){
        int w = weights[i - 1];
        int v = values[i - 1];
        for(int j = w; j <= W; ++j){
            dp[j] = max(dp[j], dp[j - w] + v);
        }
    }
    return dp[W];
}