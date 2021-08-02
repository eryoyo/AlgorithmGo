//老师想给孩子们分发糖果，有 N 个孩子站成了一条直线，老师会根据每个孩子的表现，预先给他们评分。 
//
// 你需要按照以下要求，帮助老师给这些孩子分发糖果： 
//
// 
// 每个孩子至少分配到 1 个糖果。 
// 评分更高的孩子必须比他两侧的邻位孩子获得更多的糖果。 
// 
//
// 那么这样下来，老师至少需要准备多少颗糖果呢？ 
//
// 
//
// 示例 1： 
//
// 
//输入：[1,0,2]
//输出：5
//解释：你可以分别给这三个孩子分发 2、1、2 颗糖果。
// 
//
// 示例 2： 
//
// 
//输入：[1,2,2]
//输出：4
//解释：你可以分别给这三个孩子分发 1、2、1 颗糖果。
//     第三个孩子只得到 1 颗糖果，这已满足上述两个条件。 
// Related Topics 贪心 数组 
// 👍 607 👎 0

/*
 * 题解
做完了题目 455，你会不会认为存在比较关系的贪心策略一定需要排序或是选择？虽然这一
道题也是运用贪心策略，但我们只需要简单的两次遍历即可：把所有孩子的糖果数初始化为 1；
先从左往右遍历一遍，如果右边孩子的评分比左边的高，则右边孩子的糖果数更新为左边孩子的
糖果数加 1；再从右往左遍历一遍，如果左边孩子的评分比右边的高，且左边孩子当前的糖果数
不大于右边孩子的糖果数，则左边孩子的糖果数更新为右边孩子的糖果数加 1。通过这两次遍历，
分配的糖果就可以满足题目要求了。这里的贪心策略即为，在每次遍历中，只考虑并更新相邻一
侧的大小关系。
在样例中，我们初始化糖果分配为 [1,1,1]，第一次遍历更新后的结果为 [1,1,2]，第二次遍历
更新后的结果为 [2,1,2]。
 */

#include<vector>
#include<iostream>
#include <numeric>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int candy(vector<int>& ratings) {
        int size = ratings.size();
        if(size < 2){
            return size;
        }
        vector<int> num(size ,1);
        for(int i = 1; i < size; i++){
            if(ratings[i] > ratings[i - 1]){
                num[i] = num[i - 1] + 1;
            }
        }
        for(int i = size - 1; i > 0; i--){
            if(ratings[i - 1] > ratings[i]){
                num[i - 1] = max(num[i - 1], num[i] + 1);
            }
        }
        return accumulate(num.begin(), num.end(), 0);
    }
};
//leetcode submit region end(Prohibit modification and deletion)
