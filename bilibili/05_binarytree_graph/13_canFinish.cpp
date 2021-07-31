//
// Created by eryo on 2021/7/31.
//

#include <stdio.h>
#include <vector>
#include <queue>

/*
	课程安排-207

	已知有n个课程，标记从0到n-1，课程之间是有依赖关系的
	例如希望完成A课程，可能需要先完成B课程，已知n个课程
	的依赖关系，求是否可以将n个课程全部完成

	方法1：宽度优先搜索
		构建图，并判断是否有环，如果有环则不能完成这些课程

		首先将入度为0的结点添加到队列，然后弹出该节点，
		该节点所有指向的结点的入度均减1，看最后是否所有结点的入度均为0
		如果都为0则这些课程都可以完成
*/

//图的邻接表数据结构
struct GraphNode{
    int label;		//图的顶点的值
    std::vector<GraphNode*> neighbors;	//相邻结点指针数组
    GraphNode(int x) : label(x) {}
};

class Solution{
public:
    bool canFinish(int numCourses, //依赖关系<课程1，课程2>课程1依赖课程2
                   std::vector<std::pair<int, int> >& prerequisites){
        std::vector<GraphNode*> graph;	//邻接表
        std::vector<int> degree;	//入度数组

        for(int i = 0; i < numCourses; i++){
            graph.push_back(new GraphNode(i));
            degree.push_back(0);
        }
        for(int i = 0; i < prerequisites.size(); i++){	//构建图
            GraphNode *begin = graph[prerequisites[i].second];
            GraphNode *end = graph[prerequisites[i].first];
            begin->neighbors.push_back(end);	//课程2指向课程1
            degree[prerequisites[i].first]++;	//课程2指向课程1
        }
        std::queue<GraphNode*> Q;
        for(int i = 0; i < numCourses; i++){
            if(degree[i] == 0){
                Q.push(graph[i]);	//没有访问过，进行深搜
            }
        }
        while(!Q.empty()){
            GraphNode* node = Q.front();
            Q.pop();
            for(int i = 0; i < node->neighbors.size(); i++){
                degree[node->neighbors[i]->label]--;
                if(degree[node->neighbors[i]->label] == 0){
                    Q.push(node->neighbors[i]);
                }
            }
        }
        for(int i = 0; i < numCourses; i++){
            delete graph[i];
        }
        for(int i = 0; i < numCourses; i++){
            if(degree[i]){
                return false;
            }
        }
        return true;
    }
};

int main(){
    return 0;
}