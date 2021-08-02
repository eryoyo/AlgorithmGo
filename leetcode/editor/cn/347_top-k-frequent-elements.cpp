//给你一个整数数组 nums 和一个整数 k ，请你返回其中出现频率前 k 高的元素。你可以按 任意顺序 返回答案。 
//
// 
//
// 示例 1: 
//
// 
//输入: nums = [1,1,1,2,2,3], k = 2
//输出: [1,2]
// 
//
// 示例 2: 
//
// 
//输入: nums = [1], k = 1
//输出: [1] 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 105 
// k 的取值范围是 [1, 数组中不相同的元素的个数] 
// 题目数据保证答案唯一，换句话说，数组中前 k 个高频元素的集合是唯一的 
// 
//
// 
//
// 进阶：你所设计算法的时间复杂度 必须 优于 O(n log n) ，其中 n 是数组大小。 
// Related Topics 数组 哈希表 分治 桶排序 计数 快速选择 排序 堆（优先队列） 
// 👍 814 👎 0

/*
 * 题解
顾名思义，桶排序的意思是为每个值设立一个桶，桶内记录这个值出现的次数（或其它属
性），然后对桶进行排序。针对样例来说，我们先通过桶排序得到三个桶 [1,2,3,4]，它们的值分别
为 [4,2,1,1]，表示每个数字出现的次数。
紧接着，我们对桶的频次进行排序，前 k 大个桶即是前 k 个频繁的数。这里我们可以使用各种
排序算法，甚至可以再进行一次桶排序，把每个旧桶根据频次放在不同的新桶内。针对样例来说，
因为目前最大的频次是 4，我们建立 [1,2,3,4] 四个新桶，它们分别放入的旧桶为 [[3,4],[2],[],[1]]，
表示不同数字出现的频率。最后，我们从后往前遍历，直到找到 k 个旧桶。
 */

#include<vector>
#include<iostream>
#include <unordered_map>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counts;
        int max_count = 0;

        //统计每个数字及其个数，并统计出最大的个数
        for(const int & num : nums){
            max_count = max(max_count, ++counts[num]);
        }

        //统计各个个数所对应的数字
        vector<vector<int> > buckets(max_count + 1);
        for(const auto &p : counts){
            buckets[p.second].push_back(p.first);
        }

        //结果
        vector<int> ans;

        for(int i = max_count; i >= 0 && ans.size() < k; --i){
            for(const int & num : buckets[i]){
                ans.push_back(num);
                if(ans.size() == k){
                    break;
                }
            }
        }

        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
