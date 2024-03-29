//给定一个字符串 s，计算具有相同数量 0 和 1 的非空（连续）子字符串的数量，并且这些子字符串中的所有 0 和所有 1 都是连续的。 
//
// 重复出现的子串要计算它们出现的次数。 
//
// 
//
// 示例 1 : 
//
// 
//输入: "00110011"
//输出: 6
//解释: 有6个子串具有相同数量的连续1和0：“0011”，“01”，“1100”，“10”，“0011” 和 “01”。
//
//请注意，一些重复出现的子串要计算它们出现的次数。
//
//另外，“00110011”不是有效的子串，因为所有的0（和1）没有组合在一起。
// 
//
// 示例 2 : 
//
// 
//输入: "10101"
//输出: 4
//解释: 有4个子串：“10”，“01”，“10”，“01”，它们具有相同数量的连续1和0。
// 
//
// 
//
// 提示： 
//
// 
// s.length 在1到50,000之间。 
// s 只包含“0”或“1”字符。 
// 
// Related Topics 双指针 字符串 
// 👍 385 👎 0

/*
 * 题解
从左往右遍历数组，记录和当前位置数字相同且连续的长度，以及其之前连续的不同数字的
长度。举例来说，对于 00110 的最后一位，我们记录的相同数字长度是 1，因为只有一个连续 0；
我们记录的不同数字长度是 2，因为在 0 之前有两个连续的 1。若不同数字的连续长度大于等于
当前数字的连续长度，则说明存在一个且只存在一个以当前数字结尾的满足条件的子字符串。
 */

#include <string>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int countBinarySubstrings(string s) {
        int pre = 0;
        int cur = 1;
        int count = 0;
        for(int i = 1; i < s.length(); ++i){
            if(s[i] == s[i - 1]){
                ++cur;
            }else{
                pre = cur;
                cur = 1;
            }
            if(pre >= cur){
                ++count;
            }
        }
        return count;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
