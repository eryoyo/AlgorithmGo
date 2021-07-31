//
// Created by eryo on 2021/7/31.
//

#include <stdio.h>
#include <vector>
#include <algorithm>

/*
	射击气球-452

	已知一个平面上有一定数量的气球，平面可以看作一个坐标系，
	在平面的X轴的不同位置安排弓箭手向Y轴方向射箭，弓箭可以向Y轴走无穷远
	给定气球的宽度xstart <= x <= xend，
	问至少需要多少弓箭手将全部气球打爆

	方法：
		对于某个气球至少需要一支弓箭将其击穿，在此过程中尽可能多的一支弓箭射更多的气球
		1.对各个气球进行排序，按照气球的左端点从小到大排序
		2.遍历气球数组，同时维护一个射击区间，在满足可以将当前气球击穿的情况下，
		  尽可能的击穿更多的气球，每次击穿一个气球更新一次射击区间
		3.如果新的气球没办法被击穿了，则需要增加一名弓箭手，即维护一个新的
		  射击区间

	03 182:07 6/7
*/

bool cmp(const std::pair<int, int> &a, const std::pair<int, int> &b){
    return a.first < b.first;	//无需考虑左端点相同时的排序
}

class Solution{
public:
    int findMinArrowShots(std::vector<std::pair<int, int> >& points){
        if(points.size() == 0){
            return 0;
        }
        std::sort(points.begin(), points.end(), cmp);	//对气球按照左端点从小到大排序
        int shot_num = 1;		//初始化弓箭手数量为1
        int shot_begin = points[0].first; 		//初始化射击区间
        int shot_end = points[0].second;
        for(int i = 1; i < points.size(); i++){
            if(points[i].first <= shot_end){		//更新射击区间
                shot_begin = points[i].first;
                if(shot_end > points[i].second){
                    shot_end = points[i].second;
                }
            }else{						//增加弓箭手
                shot_num++;
                shot_begin = points[i].first;
                shot_end = points[i].second;
            }
        }
        return shot_num;
    }
};

int main(){
    std::vector<std::pair<int, int> > points;
    points.push_back(std::make_pair(10, 16));
    points.push_back(std::make_pair(10, 16));
    points.push_back(std::make_pair(10, 16));
    points.push_back(std::make_pair(10, 16));
    Solution s;
    printf("%d\n", s.findMinArrowShots(points));
    return 0;
}