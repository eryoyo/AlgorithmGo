//城市的天际线是从远处观看该城市中所有建筑物形成的轮廓的外部轮廓。给你所有建筑物的位置和高度，请返回由这些建筑物形成的 天际线 。 
//
// 每个建筑物的几何信息由数组 buildings 表示，其中三元组 buildings[i] = [lefti, righti, heighti] 表示： 
//
//
// 
// lefti 是第 i 座建筑物左边缘的 x 坐标。 
// righti 是第 i 座建筑物右边缘的 x 坐标。 
// heighti 是第 i 座建筑物的高度。 
// 
//
// 天际线 应该表示为由 “关键点” 组成的列表，格式 [[x1,y1],[x2,y2],...] ，并按 x 坐标 进行 排序 。关键点是水平线段的左端点。
//列表中最后一个点是最右侧建筑物的终点，y 坐标始终为 0 ，仅用于标记天际线的终点。此外，任何两个相邻建筑物之间的地面都应被视为天际线轮廓的一部分。 
//
// 注意：输出天际线中不得有连续的相同高度的水平线。例如 [...[2 3], [4 5], [7 5], [11 5], [12 7]...] 是不正确的答
//案；三条高度为 5 的线应该在最终输出中合并为一个：[...[2 3], [4 5], [12 7], ...] 
//
// 
//
// 示例 1： 
//
// 
//输入：buildings = [[2,9,10],[3,7,15],[5,12,12],[15,20,10],[19,24,8]]
//输出：[[2,10],[3,15],[7,12],[12,0],[15,10],[20,8],[24,0]]
//解释：
//图 A 显示输入的所有建筑物的位置和高度，
//图 B 显示由这些建筑物形成的天际线。图 B 中的红点表示输出列表中的关键点。 
//
// 示例 2： 
//
// 
//输入：buildings = [[0,2,3],[2,5,3]]
//输出：[[0,3],[5,0]]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= buildings.length <= 104 
// 0 <= lefti < righti <= 231 - 1 
// 1 <= heighti <= 231 - 1 
// buildings 按 lefti 非递减排序 
// 
// Related Topics 树状数组 线段树 数组 分治 有序集合 扫描线 堆（优先队列） 
// 👍 524 👎 0

/*
 * 题解
我们可以使用优先队列储存每个建筑物的高度和右端（这里使用 pair，其默认比较函数是先
比较第一个值，如果相等则再比较第二个值），从而获取目前会拔高天际线、且妨碍到前一个建
筑物（的右端端点）的下一个建筑物。
 */

#include <vector>
#include <queue>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    //左端、右端、高度
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> ans;
        //<高度,右端>
        priority_queue<pair<int, int>> max_heap;
        int i = 0;
        int len = buildings.size();
        int cur_x;
        int cur_h;
        while(i < len || !max_heap.empty()){
            if(max_heap.empty() || i < len && buildings[i][0] <= max_heap.top().second){
                cur_x = buildings[i][0];
                while(i < len && cur_x == buildings[i][0]){
                    max_heap.emplace(buildings[i][2], buildings[i][1]);
                }
            }else{
                cur_x = max_heap.top().second;
                while(!max_heap.empty() && cur_x >= max_heap.top().second){
                    max_heap.pop();
                }
            }
            cur_h = (max_heap.empty()) ? 0 : max_heap.top().first;
            if(ans.empty() || cur_h != ans.back()[1]){
                ans.push_back({cur_x, cur_h});
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
