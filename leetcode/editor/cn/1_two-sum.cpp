//给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target 的那 两个 整数，
//并返回它们的数组下标。
//
// 你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。 
//
// 你可以按任意顺序返回答案。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [2,7,11,15], target = 9
//输出：[0,1]
//解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。
// 
//
// 示例 2： 
//
// 
//输入：nums = [3,2,4], target = 6
//输出：[1,2]
// 
//
// 示例 3： 
//
// 
//输入：nums = [3,3], target = 6
//输出：[0,1]
// 
//
// 
//
// 提示： 
//
// 
// 2 <= nums.length <= 104 
// -109 <= nums[i] <= 109 
// -109 <= target <= 109 
// 只会存在一个有效答案 
// 
//
// 进阶：你可以想出一个时间复杂度小于 O(n2) 的算法吗？ 
// Related Topics 数组 哈希表 
// 👍 11668 👎 0

#include<vector>
#include<map>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        map<int, vector<int>> log;
        int len = nums.size();
        for(int i = 0; i < len; i++){
            if(log.find(nums[i]) == log.end()){
                log[nums[i]] = vector<int>{i};
            } else{
                log[nums[i]].push_back(i);
            }
        }
        for(int i = 0; i < len; i++){
            int now_num = nums[i];
            int other_num = target - now_num;
            if(now_num == other_num && log.find(now_num) != log.end() && log[now_num].size() >= 2){
                result.push_back(log[now_num][0]);
                result.push_back(log[now_num][1]);
                break;
            } else if(now_num != other_num
                && log.find(now_num) != log.end()
                && log.find(other_num) != log.end()
                && log[now_num].size() >= 1
                && log[other_num].size() >= 1){
                result.push_back(log[now_num][0]);
                result.push_back(log[other_num][0]);
                break;
            }
        }
        return result;
    }
};

//class Solution {
//public:
//    vector<int> twoSum(vector<int>& nums, int target) {
//        unordered_map<int, int> hashtable;
//        for (int i = 0; i < nums.size(); ++i) {
//            auto it = hashtable.find(target - nums[i]);
//            if (it != hashtable.end()) {
//                return {it->second, i};
//            }
//            hashtable[nums[i]] = i;
//        }
//        return {};
//    }
//};
//leetcode submit region end(Prohibit modification and deletion)
