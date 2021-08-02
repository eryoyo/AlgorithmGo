//给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。 
//
// 
//
// 注意： 
//
// 
// 对于 t 中重复字符，我们寻找的子字符串中该字符数量必须不少于 t 中该字符数量。 
// 如果 s 中存在这样的子串，我们保证它是唯一的答案。 
// 
//
// 
//
// 示例 1： 
//
// 
//输入：s = "ADOBECODEBANC", t = "ABC"
//输出："BANC"
// 
//
// 示例 2： 
//
// 
//输入：s = "a", t = "a"
//输出："a"
// 
//
// 示例 3: 
//
// 
//输入: s = "a", t = "aa"
//输出: ""
//解释: t 中两个字符 'a' 均应包含在 s 的子串中，
//因此没有符合条件的子字符串，返回空字符串。 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length, t.length <= 105 
// s 和 t 由英文字母组成 
// 
//
// 
//进阶：你能设计一个在 o(n) 时间内解决此问题的算法吗？ Related Topics 哈希表 字符串 滑动窗口 
// 👍 1271 👎 0

/*
 * 题解
本题使用滑动窗口求解，即两个指针 l 和 r 都是从最左端向最右端移动，且 l 的位置一定在
r 的左边或重合。注意本题虽然在 for 循环里出现了一个 while 循环，但是因为 while 循环负责移
动 l 指针，且 l 只会从左到右移动一次，因此总时间复杂度仍然是 O(n)。本题使用了长度为 128
的数组来映射字符，也可以用哈希表替代；其中 chars 表示目前每个字符缺少的数量，flag 表示
每个字符是否在 T 中存在。
 */

#include<string>
#include<vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> chars(128, 0);
        vector<bool> flag(128, false);
        for(int i = 0; i < t.size(); i++){
            flag[t[i]] = true;
            ++chars[t[i]];
        }
        int cnt = 0;
        int left = 0;
        int min_l = 0;
        int min_size = s.size() + 1;
        for(int right = 0; right < s.size(); ++right){
            if(flag[s[right]]){
                if(--chars[s[right]] >= 0){
                    cnt++;
                }
                while(cnt == t.size()){
                    if(right - left + 1 < min_size){
                        min_l = left;
                        min_size = right - left + 1;
                    }
                    if(flag[s[left]] && ++chars[s[left]] > 0){
                        --cnt;
                    }
                    ++left;
                }
            }
        }
        return min_size > s.size() ? "" : s.substr(min_l, min_size);
    }
};
//leetcode submit region end(Prohibit modification and deletion)
