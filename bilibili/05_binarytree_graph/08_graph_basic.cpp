//
// Created by eryo on 2021/7/31.
//

#include <stdio.h>

/*
	预备知识-图的定义-邻接矩阵-带权图常使用

	图由顶点的有穷非空集合和顶点之间边的集合组成，G(V, E)
*/

int main(){
    const int MAX_N = 5;
    int Graph[MAX_N][MAX_N] = {0};
    Graph[0][2] = 1;
    Graph[0][4] = 1;
    Graph[1][0] = 1;
    Graph[1][2] = 1;
    Graph[2][3] = 1;
    Graph[3][4] = 1;
    Graph[4][3] = 1;
    printf("Graph:\n");
    for(int i = 0; i < MAX_N; i++){
        for(int j = 0; j < MAX_N; j++){
            printf("%d  ", Graph[i][j]);
        }
        printf("\n");
    }
}

