//
// Created by eryo on 2021/9/4.
//

#include<vector>

using namespace std;

const int MAXV = 1000;
const int INF = 1000000000;

int n, G[MAXV][MAXV];
bool vis[MAXV] = {false};

void dfs_matrix(int u, int depth){
    vis[u] = true;
    for(int v = 0; v < n; ++v){
        if(!vis[v] && G[u][v] != INF){
            dfs_matrix(v, depth + 1);
        }
    }
}

vector<int> Adj[MAXV];

void dfs_table(int u, int depth){
    vis[u] = true;
    for(int i = 0; i < Adj[u].size(); ++i){
        int v = Adj[u][i];
        if(!vis[v]){
            dfs_table(v, depth + 1);
        }
    }
}
