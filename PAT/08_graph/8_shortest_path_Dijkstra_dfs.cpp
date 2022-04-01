//
// Created by eryo on 2021/9/5.
//

//首先用Dijkstra算法记录所有的最短路径，然后从这些路径中选出最短的一条
/*
 之前pre数组储存一个前驱结点，现在改为储存所有最优的前驱结点
 变为vector或set类型
 */
/*
 第一步：
 也就是在每次从未到达结点集合中挑选出一个距离起点最近的结点的时候
 用该节点更新其相邻结点
 更新方法：
 如果使得结点距离起点的距离更近就将前驱清空，将当前结点压入
 如果使得距离没有变化，就将该节点直接假如到pre里面

 第二步：
 上面记录了所有的最短路径，接下来就要遍历所有的最短路径获得使得第二标尺最优的路径
 dfs

 */

#include<algorithm>
#include<vector>

using namespace std;

const int MAXV = 1000;  //最大顶点数
const int INF = 1000000000;

int n;
int G[MAXV][MAXV];
int d[MAXV];        //起点到各个点的最短路径长度
vector<int> pre[MAXV];      //表示最短路径路上该点的前一个结点
bool vis[MAXV] = {false};

//求最短路径的长度
void Dijkstra_matrix(int s){
    fill(d, d + MAXV, INF);
    d[s] = 0;
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
            return;
        }
        //标记该点为已访问，更新该点的邻居结点
        vis[u] = true;
        for(int v = 0; v < n; ++v){
            if(!vis[v] && G[u][v] != INF){
                if(d[u] + G[u][v] < d[v]){
                    d[v] = d[u] + G[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                }else if(d[u] + G[u][v] == d[v]){
                    pre[v].push_back(u);
                }
            }
        }
    }
}

int st;     //起点
int optvalue;   //保存第二标尺的临时最优值
vector<int> path;   //最优路径
vector<int> tempPath;   //临时路径
void DFS(int v){
    if(v == st){
        tempPath.push_back(v);
        int value;
        /*
         * 计算value的值，也就是根据第二标尺计算当前临时路径
         */
        if(value > optvalue){
            optvalue = value;
            path = tempPath;
        }
        tempPath.pop_back();
        return;
    }
    tempPath.push_back(v);
    for(int i = 0; i < pre[v].size(); ++i){
        DFS(pre[v][i]);
    }
    tempPath.pop_back();
}