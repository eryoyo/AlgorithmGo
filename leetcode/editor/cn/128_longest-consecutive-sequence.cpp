//给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。 
//
// 请你设计并实现时间复杂度为 O(n) 的算法解决此问题。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [100,4,200,1,3,2]
//输出：4
//解释：最长数字连续序列是 [1, 2, 3, 4]。它的长度为 4。 
//
// 示例 2： 
//
// 
//输入：nums = [0,3,7,2,5,8,4,6,0,1]
//输出：9
// 
//
// 
//
// 提示： 
//
// 
// 0 <= nums.length <= 105 
// -109 <= nums[i] <= 109 
// 
// Related Topics 并查集 数组 哈希表 
// 👍 856 👎 0

/*
 * 题解
我们可以把所有数字放到一个哈希表，然后不断地从哈希表中任意取一个值，并删除掉其之
前之后的所有连续数字，然后更新目前的最长连续序列长度。重复这一过程，我们就可以找到所
有的连续数字序列。
 */

#include<vector>
#include<unordered_set>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hash;
        for(const int &num : nums){
            hash.insert(num);
        }
        int ans = 0;
        while(!hash.empty()){
            int cur = *(hash.begin());
            hash.erase(cur);
            int next = cur + 1;
            int prev = cur - 1;
            while(hash.count(next)){
                hash.erase(next++);
            }
            while(hash.count(prev)){
                hash.erase(prev--);
            }
            ans = max(ans, next - prev - 1);
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
