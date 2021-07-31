//
// Created by eryo on 2021/7/31.
//

#include <stdio.h>
#include <vector>
#include <algorithm>

/*
	分糖果-455

	已知一些孩子和一些糖果，每个孩子有需求因子g，每个糖果有大小s，
	当某个糖果的大小s>=某个孩子的需求因子g时，代表该糖果可以满足该孩子，
	求使用这些糖果，最多能满足多少孩子？（某个孩子最多只能用一个糖果满足）

	方法：
		先将需求因子和糖果大小数组按照从小到大排序
		尽量满足需求小的孩子
*/

class Solution{
public:
    //孩子们的需求因子数组，糖果大小数组
    int findContentChildren(std::vector<int>& g, std::vector<int>& s){
        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());
        int child = 0;			//child表示已满足了几个孩子
        int cookie = 0;			//cookie表示尝试了几个糖果
        while(cookie < s.size() && child < g.size()){
            if(g[child] < s[cookie]){
                child++;
            }
            cookie++;
        }
        return child;
    }
};

int main(){

}