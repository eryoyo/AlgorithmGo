//给你一个数组 points ，其中 points[i] = [xi, yi] 表示 X-Y 平面上的一个点。求最多有多少个点在同一条直线上。 
//
// 
//
// 示例 1： 
//
// 
//输入：points = [[1,1],[2,2],[3,3]]
//输出：3
// 
//
// 示例 2： 
//
// 
//输入：points = [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
//输出：4
// 
//
// 
//
// 提示： 
//
// 
// 1 <= points.length <= 300 
// points[i].length == 2 
// -104 <= xi, yi <= 104 
// points 中的所有点 互不相同 
// 
// Related Topics 几何 哈希表 数学 
// 👍 336 👎 0

/*
 * 题解
对于每个点，我们对其它点建立哈希表，统计同一斜率的点一共有多少个。这里利用的原理
是，一条线可以由一个点和斜率而唯一确定。另外也要考虑斜率不存在和重复坐标的情况。
本题也利用了一个小技巧：在遍历每个点时，对于数组中位置 i 的点，我们只需要考虑 i 之
后的点即可，因为 i 之前的点已经考虑过 i 了。
 */

#include <vector>
#include<unordered_map>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        unordered_map<double, int> hash;//斜率，点个数
        int max_count = 0;
        int same = 1;
        int same_y = 1;
        for(int i = 0; i < points.size(); ++i){
            same = 1;
            same_y = 1;
            for(int j = i + 1; j < points.size(); ++j){
                if(points[i][1] == points[j][1]){
                    ++same_y;
                    if(points[i][0] == points[j][0]){
                        ++same;
                    }
                }else{
                    double dx = points[i][0] - points[j][0];
                    double dy = points[i][1] - points[j][1];
                    ++hash[dx / dy];
                }
            }
            max_count = max(max_count, same_y);
            for(auto item : hash){
                max_count = max(max_count, same + item.second);
            }
            hash.clear();
        }
        return max_count;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
