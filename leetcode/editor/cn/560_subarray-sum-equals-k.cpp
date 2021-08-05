//给定一个整数数组和一个整数 k，你需要找到该数组中和为 k 的连续的子数组的个数。 
//
// 示例 1 : 
//
// 
//输入:nums = [1,1,1], k = 2
//输出: 2 , [1,1] 与 [1,1] 为两种不同的情况。
// 
//
// 说明 : 
//
// 
// 数组的长度为 [1, 20,000]。 
// 数组中元素的范围是 [-1000, 1000] ，且整数 k 的范围是 [-1e7, 1e7]。 
// 
// Related Topics 数组 哈希表 前缀和 
// 👍 1033 👎 0

/*
 * 题解
本题同样是利用前缀和，不同的是这里我们使用一个哈希表 hashmap，其键是前缀和，而值是
该前缀和出现的次数。在我们遍历到位置 i 时，假设当前的前缀和是 psum，那么 hashmap[psum-k]
即为以当前位置结尾、满足条件的区间个数。
 */

#include<vector>
#include<unordered_map>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        int psum = 0;
        unordered_map<int, int> hashmap;
        hashmap[0] = 1;
        for(int i : nums){
            psum += i;
            count += hashmap[psum - k];
            ++hashmap[psum];
        }
        return count;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
