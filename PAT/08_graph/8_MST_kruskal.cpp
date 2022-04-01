//
// Created by eryo on 2021/9/5.
//

//最小生成树-kruskal算法
/*
 每次选择权重最小的边，假如该边两端的点不在同一个集合
 就将该边加入最小生成树
 */

#include<cstdio>
#include<algorithm>

using namespace std;

const int MAXV = 110;
const int MAXE = 10010;

struct edge{
    int u, v;
    int cost;
}E[MAXE];

bool cmp(edge a, edge b){
    return a.cost < b.cost;
}

int father[MAXV];
int findFather(int x){
    int a = x;
    while(x != father[x]){
        x = father[x];
    }
    while(a != father[a]){
        int z = a;
        a = father[a];
        father[z] = x;
    }
    return x;
}

int kruskal(int n, int m){
    int ans = 0;
    int Num_Edge = 0;
    for(int i = 0; i < n; ++i){
        father[i] = i;
    }
    sort(E, E + m, cmp);
    for(int i = 0; i < m; ++i){
        int faU = findFather(E[i].u);
        int faV = findFather(E[i].v);
        if(faU != faV){
            father[faU] = faV;
            ans += E[i].cost;
            Num_Edge++;
            if(Num_Edge == n - 1){
                break;
            }
        }
    }
    if(Num_Edge != n - 1){
        return -1;
    }
    return ans;
}