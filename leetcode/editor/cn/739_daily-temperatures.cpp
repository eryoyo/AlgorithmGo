//请根据每日 气温 列表 temperatures ，请计算在每一天需要等几天才会有更高的温度。如果气温在这之后都不会升高，请在该位置用 0 来代替。 
//
// 示例 1: 
//
// 
//输入: temperatures = [73,74,75,71,69,72,76,73]
//输出: [1,1,4,2,1,1,0,0]
// 
//
// 示例 2: 
//
// 
//输入: temperatures = [30,40,50,60]
//输出: [1,1,1,0]
// 
//
// 示例 3: 
//
// 
//输入: temperatures = [30,60,90]
//输出: [1,1,0] 
//
// 
//
// 提示： 
//
// 
// 1 <= temperatures.length <= 105 
// 30 <= temperatures[i] <= 100 
// 
// Related Topics 栈 数组 单调栈 
// 👍 830 👎 0

/*
 * 题解
我们可以维持一个单调递减的栈，表示每天的温度；为了方便计算天数差，我们这里存放位
置（即日期）而非温度本身。我们从左向右遍历温度数组，对于每个日期 p，如果 p 的温度比栈
顶存储位置 q 的温度高，则我们取出 q，并记录 q 需要等待的天数为 p − q；我们重复这一过程，
直到 p 的温度小于等于栈顶存储位置的温度（或空栈）时，我们将 p 插入栈顶，然后考虑下一天。
在这个过程中，栈内数组永远保持单调递减，避免了使用排序进行比较。最后若栈内剩余一些日
期，则说明它们之后都没有出现更暖和的日期。
 */

#include<vector>
#include <stack>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n);
        stack<int> indices;
        for(int i = 0; i < n; ++i){
            while(!indices.empty()){
                int pre_index = indices.top();
                if(temperatures[i] <= temperatures[pre_index]){
                    break;
                }
                indices.pop();
                ans[pre_index] = i - pre_index;
            }
            indices.push(i);
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
