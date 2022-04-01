//
// Created by eryo on 2021/9/5.
//

//有向无环图-DAG-directed acyclic graph

//拓扑排序
/*
 将有向无环图的所有顶点排成一个线性序列

 定义一个队列，将所有入度为0的结点加入到队列，取队首结点，
 将能从该节点到达的顶点的入度减1，假如入度变为0就加入队列
 */

#include<vector>
#include<queue>

using namespace std;

const int MAXV = 100;

vector<int> G[MAXV];
int n;  //结点数
int m;  //边数
int inDegree[MAXV];

bool topologicalSort(){
    int num = 0;    //记录加入到拓扑序列的顶点数
    queue<int> q;
    for(int i = 0; i < n; ++i){
        if(inDegree[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i = 0; i < G[u].size(); ++i){
            int v = G[u][i];
            inDegree[v]--;
            if(inDegree[v] == 0){
                q.push(v);
            }
        }
        G[u].clear();
        num++;
    }
    if(num == n){
        return true;
    }
    return false;
}