//
// Created by eryo on 2021/7/31.
//

#include <stdio.h>
#include <vector>

/*
	课程安排-207

	已知有n个课程，标记从0到n-1，课程之间是有依赖关系的
	例如希望完成A课程，可能需要先完成B课程，已知n个课程
	的依赖关系，求是否可以将n个课程全部完成

	方法1：深度优先搜索
		构建图，并判断是否有环，如果有环则不能完成这些课程

		正在搜索某一个结点（还未退出该顶点的递归深度搜索）又回到了
		该顶点，则证明有环
*/

//图的邻接表数据结构
struct GraphNode{
    int label;		//图的顶点的值
    std::vector<GraphNode*> neighbors;	//相邻结点指针数组
    GraphNode(int x) : label(x) {}
};

bool DFS_graph(GraphNode *node, std::vector<int> &visit){
    visit[node->label] = 0;
    for(int i = 0; i < node->neighbors.size(); i++){
        if(visit[node->neighbors[i]->label] == -1){
            if(DFS_graph(node->neighbors[i], visit) == 0){
                return false;
            }
        }else if(visit[node->neighbors[i]->label] == 0){
            return false;
        }
    }
    visit[node->label] = 1;
    return true;
}

class Solution{
public:
    bool canFinish(int numCourses, //依赖关系<课程1，课程2>课程1依赖课程2
                   std::vector<std::pair<int, int> >& prerequisites){
        std::vector<GraphNode*> graph;	//邻接表
        std::vector<int> visit;
        //结点访问状态，-1表示没有访问过，0表示正在访问，1表示已完成访问
        for(int i = 0; i < numCourses; i++){
            graph.push_back(new GraphNode(i));
            visit.push_back(-1);
        }
        for(int i = 0; i < prerequisites.size(); i++){	//构建图
            GraphNode *begin = graph[prerequisites[i].second];
            GraphNode *end = graph[prerequisites[i].first];
            begin->neighbors.push_back(end);	//课程2指向课程1
        }
        for(int i = 0; i < graph.size(); i++){
            if(visit[i] == -1 && !DFS_graph(graph[i], visit)){
                return false;	//没有访问过，进行深搜
            }
        }
        for(int i = 0; i < numCourses; i++){
            delete graph[i];
        }
        return true;
    }
};

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

    std::vector<int> visit;
    for(int i = 0; i < MAX_N; i++){
        visit.push_back(-1);
    }	//标记已访问的顶点
    for(int i = 0; i < MAX_N; i++){
        if(visit[i] == -1){
            printf("From label(%d) : ", i);
            printf("%d", (int)DFS_graph(Graph[i], visit));
            printf("\n");
        }
    }
    for(int i = 0; i < MAX_N; i++){
        delete Graph[i];
    }
    return 0;
}