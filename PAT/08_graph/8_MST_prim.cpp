//
// Created by eryo on 2021/9/5.
//

//Minimum Spanning Tree最小生成树
/*
 无向图
 贪心思想
 */

//prim
/*
 将顶点分为两个集合，每次从未到达城市中选择一个距离已到达城市最近的点
 将该点加入到已到达集合

 思想和Dijkstra极为相似，只不过每次选择为到达结点的方法
 从到达起点最近变为离已到达结点群最近
 */

#include<algorithm>

using namespace std;

const int MAXV = 1000;  //最大顶点数
const int INF = 1000000000;

int n;
int G[MAXV][MAXV];
int d[MAXV];        //起点到已到达顶点集合的最短路径长度
int pre[MAXV];      //表示最短路径路上该点的前一个结点
bool vis[MAXV] = {false};

//求最短路径的长度，默认从0号结点开始
int prim_matrix(){
    fill(d, d + MAXV, INF);
    for(int i = 0; i < n; ++i){
        pre[i] = i;
    }
    d[0] = 0;
    int ans = 0;        //存放最小生成树的边权之和
    for(int i = 0; i < n; ++i){
        int u = -1;
        int MIN = INF;
        //找到未访问结点中距离起点最小的
        for(int j = 0; j < n; ++j){
            if(!vis[j] && d[j] < MIN){
                u = j;
                MIN = d[j];
            }
        }
        //没有找到，表示不连通
        if(u == -1){
            return -1;
        }
        //标记该点为已访问，更新该点的邻居结点
        vis[u] = true;
        ans += d[u];
        for(int v = 0; v < n; ++v){
            if(!vis[v] && G[u][v] != INF && G[u][v] < d[v]){
                d[v] = G[u][v];
                pre[v] = u;     //记录前驱
            }
        }
    }
    return ans;
}