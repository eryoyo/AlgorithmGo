//给你一个整数数组 nums ，设计算法来打乱一个没有重复元素的数组。 
//
// 实现 Solution class: 
//
// 
// Solution(int[] nums) 使用整数数组 nums 初始化对象 
// int[] reset() 重设数组到它的初始状态并返回 
// int[] shuffle() 返回数组随机打乱后的结果 
// 
//
// 
//
// 示例： 
//
// 
//输入
//["Solution", "shuffle", "reset", "shuffle"]
//[[[1, 2, 3]], [], [], []]
//输出
//[null, [3, 1, 2], [1, 2, 3], [1, 3, 2]]
//
//解释
//Solution solution = new Solution([1, 2, 3]);
//solution.shuffle();    // 打乱数组 [1,2,3] 并返回结果。任何 [1,2,3]的排列返回的概率应该相同。例如，返回 [3, 
//1, 2]
//solution.reset();      // 重设数组到它的初始状态 [1, 2, 3] 。返回 [1, 2, 3]
//solution.shuffle();    // 随机返回数组 [1, 2, 3] 打乱后的结果。例如，返回 [1, 3, 2]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 200 
// -106 <= nums[i] <= 106 
// nums 中的所有元素都是 唯一的 
// 最多可以调用 5 * 104 次 reset 和 shuffle 
// 
// Related Topics 数组 数学 随机化 
// 👍 147 👎 0

/*
 * 题解
我们采用经典的 Fisher-Yates 洗牌算法，原理是通过随机交换位置来实现随机打乱，有正向
和反向两种写法，且实现非常方便。注意这里“reset”函数以及类的构造函数的实现细节。
 */

#include<vector>
#include <cstdlib>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    vector<int> origin;
public:
    Solution(vector<int>& nums) : origin(move(nums)) {}
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return origin;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        if(origin.empty()){
            return {};
        }
        vector<int> shuffled(origin);
        int n = origin.size();
        //可以使用反向和正向洗牌，效果相同
        //反向洗牌：
        for(int i = n - 1; i >= 0; --i){
            swap(shuffled[i], shuffled[rand() % (i + 1)]);
        }
        //正向洗牌：
//        for(int i = 0; i < n; ++i){
//            int pos = rand() % (n - i);
//            swap(shuffled[i], shuffled[i + pos]);
//        }
        return shuffled;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
//leetcode submit region end(Prohibit modification and deletion)
