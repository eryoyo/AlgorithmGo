//
// Created by eryo on 2021/7/31.
//

#include <stdio.h>
#include <vector>

/*
	预备知识-图的定义-邻接表-搜索常使用

	图由顶点的有穷非空集合和顶点之间边的集合组成，G(V, E)
*/

//图的邻接表数据结构
struct GraphNode{
    int label;		//图的顶点的值
    std::vector<GraphNode*> neighbors;	//相邻结点指针数组
    GraphNode(int x) : label(x) {}
};

int main(){
    const int MAX_N = 5;	//5个顶点
    GraphNode *Graph[MAX_N];

    for(int i = 0; i < MAX_N; i++){
        Graph[i] = new GraphNode(i);
    }

    Graph[0]->neighbors.push_back(Graph[2]);
    Graph[0]->neighbors.push_back(Graph[4]);
    Graph[1]->neighbors.push_back(Graph[0]);
    Graph[1]->neighbors.push_back(Graph[2]);
    Graph[2]->neighbors.push_back(Graph[3]);
    Graph[3]->neighbors.push_back(Graph[4]);
    Graph[4]->neighbors.push_back(Graph[3]);

    printf("Graph:\n");
    for(int i = 0; i < MAX_N; i++){
        printf("Label<%d> : ", i);
        for(int j = 0; j < Graph[i]->neighbors.size(); j++){
            printf("%d ", Graph[i]->neighbors[j]->label);
        }
        printf("\n");
    }
    return 0;
}