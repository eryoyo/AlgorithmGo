//
// Created by eryo on 2021/7/31.
//

#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

/*
	最优加油方法-POJ-2431

	已知一条公路上，有一个起点和一个终点，这之间有n个加油站，
	已知从这n个加油站到终点的距离d与各个加油站可以加油的量l;
	起点位置到终点的距离L与起始时刻油箱中汽油量P；假设使用1个
	单位的汽油即可走1个单位的距离，油箱没有上限，最少加几次油，
	可以从起点开至终点，如果无法到达终点，返回-1

	方法：
		每次向前走一个加油站，判断能否走到，如果可以就接着往前走，
		并将当前加油站的油量加到最大堆里面，如果不能到下一个加油站就
		依次从最大堆里面弹出油量大的那个加油，
		直到加了全部的油也到不了下一个车站就返回-1
*/

bool cmp(const std::pair<int, int> &a, const std::pair<int, int> &b){
    return a.first > b.first;
}

int get_minimum_stop(int L, int P, std::vector<std::pair<int, int> > &stop){
    //L为起点到终点的距离，P为起始时的汽油量
    //pair<加油站到终点的距离，加油站汽油量>
    std::priority_queue<int> Q;		//储存油量的最大堆
    int result = 0;		//记录加油的次数
    stop.push_back(std::make_pair(0, 0));	//将终点作为一个停靠点，加入数组
    std::sort(stop.begin(), stop.end(), cmp);
    //将停靠点到终点的距离从大到小排序
    for(int i = 0; i < stop.size(); i++){
        int dis = L - stop[i].first;
        while(!Q.empty() && P < dis){
            P += Q.top();
            Q.pop();
            result++;
        }
        if(Q.empty() && P < dis){
            return -1;
        }
        P = P - dis;
        L = stop[i].first;
        Q.push(stop[i].second);
    }
    return result;
}

int main(){

}