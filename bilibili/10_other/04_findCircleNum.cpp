//
// Created by eryo on 2021/7/31.
//

#include <stdio.h>
#include <vector>

/*
	朋友圈-547

	有N个同学，他们之间有些是朋友，有些不是。友谊之间是可以传递的，
	例如A和B是朋友，B与C是朋友，那么A与C也是朋友；朋友圈就是完成友谊
	传递后的一组朋友。给定N*N的矩阵代表同学间是否是朋友，如果M[i][j]
	= 1代表第i个学生与第j个学生是朋友，否则不是，求朋友圈的个数。
*/

class Solution{
public:
    void DFS_graph(int u, std::vector<std::vector<int> >& graph,
                   std::vector<int>& visit){
        visit[u] = 1;
        for(int i = 0; i < graph[u].size(); i++){
            if(graph[u][i] == 1 && visit[i] == 0){
                DFS_graph(i, graph, visit);
            }
        }
    }

    int findCircleNum(std::vector<std::vector<int> >& M){
        std::vector<int> visit(M.size(), 0);
        int count = 0;
        for(int i = 0; i < M.size(); i++){
            if(visit[i] == 0){
                DFS_graph(0, M, visit);
                count++;
            }
        }
        return count;
    }
};