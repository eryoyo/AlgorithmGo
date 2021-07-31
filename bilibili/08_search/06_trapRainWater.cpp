//
// Created by eryo on 2021/7/31.
//

#include <stdio.h>
#include <vector>
#include <queue>

/*
	收集雨水-407

	已知一个m*n的二维数组，数组储存正整数，代表一个个单元的高度（立方体），
	将这些立方体想象成水槽，问如果下雨这些立方体中会有多少积水

	方法：
		带优先级的广度优先搜索,使用优先级队列，即堆
*/

struct Qitem{
    int x;
    int y;
    int h;
    Qitem(int _x, int _y, int _h) : x(_x), y(_y), h(_h){}
};

struct cmp{
    bool operator()(const Qitem &a, const Qitem &b){
        return a.h > b.h;
    }
};

class Solution{
public:
    int trapRainWater(std::vector<std::vector<int> >& heightMap){
        std::priority_queue<Qitem, std::vector<Qitem>, cmp> Q;
        //矩阵的行或列数小于3则肯定无法积水
        if(heightMap.size() < 3 || heightMap[0].size() < 3){
            return 0;
        }
        int row = heightMap.size();
        int column = heightMap[0].size();
        //初始化mark数组
        std::vector<std::vector<int> > mark;
        for(int i = 0; i < row; i++){
            mark.push_back(std::vector<int>());
            for(int j = 0; j < column; j++){
                mark[i].push_back(0);
            }
        }
        //将四周的点加入到队列
        for(int i = 0; i < row; i++){
            Q.push(Qitem(i, 0, heightMap[i][0]));
            mark[i][0] = 1;
            Q.push(Qitem(i, column - 1, heightMap[i][column - 1]));
            mark[i][column - 1] = 1;
        }
        for(int i = 1; i < column - 1; i++){
            Q.push(Qitem(0, i, heightMap[0][i]));
            mark[0][i] = 1;
            Q.push(Qitem(row - 1, i, heightMap[row - 1][i]));
            mark[row - 1][i] = 1;
        }
        //方向数组
        static const int dx[] = {-1, 1, 0, 0};
        static const int dy[] = {0, 0, -1, 1};
        int result = 0;
        while(!Q.empty()){
            int x = Q.top().x;
            int y = Q.top().y;
            int h = Q.top().h;
            Q.pop();
            for(int i = 0; i < 4; i++){
                int newx = x + dx[i];
                int newy = y + dy[i];
                if(newx < 0 || newx >= row || newy < 0 || newy >= column || mark[newx][newy]){
                    continue;
                }
                if(h > heightMap[newx][newy]){
                    result += h - heightMap[newx][newy];
                    heightMap[newx][newy] = h;
                }
                Q.push(Qitem(newx, newy, heightMap[newx][newy]));
                mark[newx][newy] = 1;
            }
        }
        return result;
    }
};

int main(){
    int test[][10] = {
            {1, 4, 3, 1, 3, 2},
            {3, 2, 1, 3, 2, 4},
            {2, 3, 3, 2, 3, 1}
    };
    std::vector<std::vector<int> > heightMap;
    for(int i = 0; i < 3; i++){
        heightMap.push_back(std::vector<int>());
        for(int j = 0; j < 6; j++){
            heightMap[i].push_back(test[i][j]);
        }
    }
    Solution s;
    printf("%d\n", s.trapRainWater(heightMap));
    return 0;
}