//
// Created by eryo on 2021/7/31.
//

#include <stdio.h>
#include <vector>
#include <string>

/*
	N皇后问题-51

	将N个皇后摆放到N*N的棋盘中，互相不可攻击，问有多少种摆放方式
	每一种摆放方式具体是怎么样的（攻击：上下左右斜对角的一整条线共8条线）

	方法：回溯法
*/

class Solution{
public:
    //外层表示摆放的方式数， 内层表示棋盘，n表示几皇后
    std::vector<std::vector<std::string> > solveNQueens(int n){
        //mark数组'0'表示可放皇后，'1'表示不可放皇后
        std::vector<std::vector<std::string> > result;	//存储最终结果
        std::vector<std::vector<int> > mark;	//标记棋盘是否可以放置皇后的二维数组
        std::vector<std::string> location;		//储存某一个摆放结果，当找到结果后，将结果push到result中
        for(int i = 0; i < n; i++){
            mark.push_back(std::vector<int>());	//初始化mark数组和location数组
            for(int j = 0; j < n; j++){
                mark[i].push_back(0);
            }
            location.push_back("");
            location[i].append(n, '.');
        }
        generate(0, n, location, result, mark);
        return result;
    }

    void generate(int k, int n,		//k表示完成了几个皇后的放置，n表示皇后总数
                  std::vector<std::string> &location,	//某次结果储存在location中
                  std::vector<std::vector<std::string> > &result,//储存最终结果
                  std::vector<std::vector<int> > &mark){//表示棋盘的标记数组
        if(k == n){
            result.push_back(location);
            return;
        }
        for(int i = 0; i < n; i++){
            if(mark[k][i] == 0){
                std::vector<std::vector<int> > tmp_mark = mark;	//便于回溯
                location[k][i] = 'Q';
                put_down_the_queen(k, i, mark);

                generate(k + 1, n, location, result, mark);//递归下一行皇后

                mark = tmp_mark;		//回溯之后进行的工作
                location[k][i] = '.';
            }
        }
    }

    //第x行，第y列放置皇后，mark[行][列]表示一张棋盘
    void put_down_the_queen(int x, int y, std::vector<std::vector<int> > &mark){
        static const int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};//方向数组
        static const int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};//8个方向
        mark[x][y] = 1;
        for(int i = 1; i < mark.size(); i++){
            for(int j = 0; j < 8; j++){	//8个方向，每个方向向外延伸1至N-1
                int new_x = x + i * dx[j];
                int new_y = y + i * dy[j];
                if(new_x >= 0 && new_x < mark.size()
                   && new_y >= 0 && new_y < mark.size()){
                    mark[new_x][new_y] = 1;
                }
            }
        }
    }
};

int main(){
    std::vector<std::vector<std::string> > result;
    Solution s;
    result = s.solveNQueens(8);
    for(int i = 0; i < result.size(); i++){
        printf("i = %d\n", i);
        for(int j = 0; j < result[i].size(); j++){
            printf("%s\n", result[i][j].c_str());
        }
        printf("\n");
    }
}