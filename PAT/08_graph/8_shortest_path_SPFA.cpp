//
// Created by eryo on 2021/9/5.
//

//bellman的改进算法-SPFA算法
/*
 bellman算法有许多的重复计算，结点只有在他本身的值
 已经被改变的前提之下才可能改变他的邻接点的值

 所以创建一个队列，最初只有起点入栈，每次都从栈中取出一个点
 更新该点连接的点的值，如果更新之后该点不在队列中将该点加入队列

 不断重复直到队列为空（说明没有负环）或某个顶点入栈次数达到V-1次

 O(kE)
 */

#include<vector>
#include <cstring>
#include <queue>

using namespace std;

const int MAXV = 1000;  //最大顶点数
const int INF = 0x3fffffff;

struct Node{
    int v;  //邻接边的目标顶点
    int dis;    //邻接边的边权
};

vector<Node> Adj[MAXV];
int n;
int num[MAXV];  //记录结点入队次数
int d[MAXV];
bool inq[MAXV];     //记录结点是否在栈中

bool SPFA(int s){
    memset(inq, false, sizeof(inq));
    memset(num, 0, sizeof(num));
    fill(d, d + MAXV, INF);
    queue<int> Q;
    Q.push(s);
    inq[s] = true;
    num[s]++;
    d[s] = 0;
    while(!Q.empty()){
        int u = Q.front();
        Q.pop();
        inq[u] = false;
        for(int j = 0; j < Adj[u].size(); ++j){
            int v = Adj[u][j].v;
            int dis = Adj[u][j].dis;
            if(d[u] + dis < d[v]){
                d[v] = d[u] + dis;
                if(!inq[v]){
                    Q.push(v);
                    inq[v] = true;
                    num[v]++;
                    if(num[v] >= n){
                        return false;
                    }
                }
            }
        }
    }
    return true;
}