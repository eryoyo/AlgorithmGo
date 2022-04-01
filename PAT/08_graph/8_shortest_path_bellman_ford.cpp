//
// Created by eryo on 2021/9/5.
//

//Bellman-Ford
/*
 解决单源最短路径问题+有负权边
 */
/*
 对图中的边进行v-1轮循环，每轮循环都遍历图中的所有边，对每条边
 更新该边终点到起点的距离，复杂度为O(VE)-邻接表
 进行完循环之后，再次对每条边进行判断，如果还能更新点的距离则存在负环
 */

#include<vector>

using namespace std;

const int MAXV = 1000;  //最大顶点数
const int INF = 0x3fffffff;

struct Node{
    int v;  //邻接边的目标顶点
    int dis;    //邻接边的边权
};

vector<Node> Adj[MAXV];
int n;
int d[MAXV];

bool Bellman(int s){
    fill(d, d + MAXV, INF);
    d[s] = 0;
    //求解数组d
    for(int i = 0; i < n - 1; ++i){
        for(int u = 0; u < n; ++u){
            for(int j = 0; j < Adj[u].size(); ++j){
                int v = Adj[u][j].v;
                int dis = Adj[u][j].dis;
                if(d[u] + dis < d[v]){
                    d[v] = d[u] + dis;
                }
            }
        }
    }
    //判断是否存在负环
    for(int u = 0; u < n; ++u){
        for(int j = 0; j < Adj[u].size(); ++j){
            int v = Adj[u][j].v;
            int dis = Adj[u][j].dis;
            if(d[u] + dis < d[v]){
                return false;
            }
        }
    }
    return true;
}