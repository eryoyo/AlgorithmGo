//
// Created by eryo on 2021/7/31.
//

#include <stdio.h>
#include <vector>
#include <queue>

/*
	岛屿数量-200

	用一个二维数组代表一张地图，这张地图由字符‘0’和字符‘1’组成，
	其中‘0’字符代表水域，‘1’字符代表小岛土地，小岛‘1’被水‘0’包围，
	当小岛土地‘1’在水平和垂直方向相连接时，认为是同一块土地，求这张地图中小岛的数量


*/

class Solution{
	public:
		void DFS(std::vector<std::vector<int> > &mark,
			std::vector<std::vector<char> > &grid,
			int x, int y){
			mark[x][y] = 1;
			static const int dx[] = {-1, 1, 0, 0};
			static const int dy[] = {0, 0, -1, 1};
			for(int i = 0; i < 4; i++){
				int newx = x + dx[i];
				int newy = y + dy[i];
				if(newx < 0 || newx >= mark.size() ||
					newy < 0 || newy >= mark[newx].size()){
					continue;
				}
				if(grid[newx][newy] == '1' && mark[newx][newy] == 0){
					DFS(mark, grid, newx, newy);
				}
			}
		}

		void BFS(std::vector<std::vector<int> > &mark,
			std::vector<std::vector<char> > &grid,
			int x, int y){
			static const int dx[] = {-1, 1, 0, 0};
			static const int dy[] = {0, 0, -1, 1};
			std::queue<std::pair<int, int> > Q;
			Q.push(std::make_pair(x, y));
			mark[x][y] = 1;
			while(!Q.empty()){
				x = Q.front().first;
				y = Q.front().second;
				Q.pop();
				for(int i = 0; i < 4; i++){
					int newx = dx[i] + x;
					int newy = dy[i] + y;
					if(newx < 0 || newx >= mark.size() ||
						newy < 0 || newy >= mark[newx].size()){
						continue;
					}
					if(mark[newx][newy] == 0 && grid[newx][newy] == '1'){
						Q.push(std::make_pair(newx, newy));
						mark[newx][newy] = 1;
					}
				}
			}
		}

		int numIslands(std::vector<std::vector<char> >& grid){
			int island_num = 0;
			std::vector<std::vector<int> > mark;
			for(int i = 0; i < grid.size(); i++){
				mark.push_back(std::vector<int>());
				for(int j = 0; j < grid[i].size(); j++){
					mark[i].push_back(0);
				}
			}
			for(int i = 0; i < grid.size(); i++){
				for(int j = 0; j < grid[i].size(); j++){
					if(mark[i][j] == 0 && grid[i][j] == '1'){
						BFS(mark, grid, i, j);
						island_num++;
					}
				}
			}
			return island_num;
		}
};

int main(){
	std::vector<std::vector<char> > grid;
	char str[10][10] = {"11100", "11000", "00100", "00011"};
	for(int i = 0; i < 4; i++){
		grid.push_back(std::vector<char>());
		for(int j = 0; j < 5; j++){
			grid[i].push_back(str[i][j]);
		}
	}
	Solution s;
	printf("%d\n", s.numIslands(grid));
	return 0;
}