//
// Created by eryo on 2021/9/5.
//

//Activity On Vertex, AOV
/*
 顶点活动网：顶点表示活动，边集表示活动间优先关系
 */

//Activity On Edge, AOE
/*
 边活动图：带权的边表示活动，顶点表示事件，边权代表活动所需要的时间

 事件是一个瞬间，时间点

 活动表示一个过程

 关键路径：最长路径，关键路径上面的活动称为关键活动

 求最长路径：将边权全部乘以-1，然后使用bellman-ford方法求解
 */
/*
 另一种算法：事件i->活动r->事件j
 e[r], l[r]:表示活动r的最早开始时间和最迟开始时间
 ve[i], vl[i]:表示事件i的最早发生时间和最迟发生时间
 活动r的最早开始时间等于事件i的最早发生时间e[r]=ve[i]
 活动r的最晚发生时间等于事件j的最迟发生时间-活动r的持续时间l[r]=vl[j]-length[r]

 所以求活动的最早/最晚开始时间变为求事件的最早/最晚发生时间

 求事件的最早发生时间：
    等于它的前驱事件最早发生时间加上连接的边权的和的最大值

 求事件的最迟发生时间：
    等于它的后继事件的最迟发生事件减去边权的差的最小值
 */

#include<stack>
#include <queue>
#include <cstring>
#include <cstdio>

using namespace std;

const int MAXV = 100;

struct Node{
    int v;
    int w;
};

vector<Node> G[MAXV];
int e[MAXV];
int l[MAXV];
int ve[MAXV];
int vl[MAXV];
int n;
int inDegree[MAXV];

//拓扑序列
stack<int> topOrder;
//拓扑排序，顺便求ve数组
bool topologicalSort(){
    queue<int> q;
    for(int i = 0; i < n; ++i){
        if(inDegree[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int u = q.front();
        q.pop();
        topOrder.push(u);
        for(int i = 0; i < G[u].size(); ++i){
            int v = G[u][i].v;
            inDegree[v]--;
            if(inDegree[v] == 0){
                q.push(v);
            }
            if(ve[u] + G[u][i].w > ve[v]){
                ve[v] = ve[u] + G[u][i].w;
            }
        }
    }
    if(topOrder.size() == n){
        return true;
    }
    return false;
}

int CriticalPath(){
    memset(ve, 0, sizeof(ve));
    if(!topologicalSort()){
        return -1;
    }
    fill(vl, vl + n, ve[n - 1]);
    //使用拓扑排序得到的序列进行逆拓扑排序
    while(!topOrder.empty()){
        int u = topOrder.top();
        topOrder.pop();
        for(int i = 0; i < G[u].size(); ++i){
            int v = G[u][i].v;
            //用u的后继结点v的vl来更新u的vl
            if(vl[v] - G[u][i].w < vl[u]){
                vl[u] = vl[v] - G[u][i].w;
            }
        }
    }
    //遍历邻接表的所有边，计算活动的最早开始时间和最迟开始时间
    for(int u = 0; u < n; ++u){
        for(int i = 0; i < G[u].size(); ++i){
            int v = G[u][i].v;
            int w = G[u][i].w;
            int e = ve[u];
            int l = vl[v] - w;
            if(e == l){
                printf("%d->%d\n", u, v);
            }
        }
    }
    return ve[n - 1];
}