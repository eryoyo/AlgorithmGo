//
// Created by eryo on 2021/7/31.
//

#include <stdio.h>
#include <vector>
#include <queue>

/*
	预备知识-图的宽度优先遍历

	图由顶点的有穷非空集合和顶点之间边的集合组成，G(V, E)
*/

//图的邻接表数据结构
struct GraphNode{
    int label;		//图的顶点的值
    std::vector<GraphNode*> neighbors;	//相邻结点指针数组
    GraphNode(int x) : label(x) {}
};

void BFS_graph(GraphNode* node, int visit[]){
    std::queue<GraphNode*> Q;
    Q.push(node);
    visit[node->label] = 1;
    while(!Q.empty()){
        GraphNode* node = Q.front();
        Q.pop();
        printf("%d ", node->label);
        for(int i = 0; i < node->neighbors.size(); i++){
            if(visit[node->neighbors[i]->label] == 0){
                Q.push(node->neighbors[i]);
                visit[node->neighbors[i]->label] = 1;
            }
        }
    }
}

int main(){
    const int MAX_N = 5;	//5个顶点
    GraphNode *Graph[MAX_N];

    for(int i = 0; i < MAX_N; i++){
        Graph[i] = new GraphNode(i);
    }

    Graph[0]->neighbors.push_back(Graph[4]);
    Graph[0]->neighbors.push_back(Graph[2]);
    Graph[1]->neighbors.push_back(Graph[0]);
    Graph[1]->neighbors.push_back(Graph[2]);
    Graph[2]->neighbors.push_back(Graph[3]);
    Graph[3]->neighbors.push_back(Graph[4]);
    Graph[4]->neighbors.push_back(Graph[3]);

    int visit[MAX_N] = {0};	//标记已访问的顶点
    for(int i = 0; i < MAX_N; i++){
        if(!visit[i]){
            printf("From label(%d) : ", i);
            BFS_graph(Graph[i], visit);
            printf("\n");
        }
    }
    for(int i = 0; i < MAX_N; i++){
        delete Graph[i];
    }
    return 0;
}