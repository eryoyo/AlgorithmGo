//实现 strStr() 函数。 
//
// 给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串出现的第一个位置（下标从 0 开始）。如
//果不存在，则返回 -1 。 
//
// 
//
// 说明： 
//
// 当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。 
//
// 对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与 C 语言的 strstr() 以及 Java 的 indexOf() 定义相符。 
//
// 
//
// 示例 1： 
//
// 
//输入：haystack = "hello", needle = "ll"
//输出：2
// 
//
// 示例 2： 
//
// 
//输入：haystack = "aaaaa", needle = "bba"
//输出：-1
// 
//
// 示例 3： 
//
// 
//输入：haystack = "", needle = ""
//输出：0
// 
//
// 
//
// 提示： 
//
// 
// 0 <= haystack.length, needle.length <= 5 * 104 
// haystack 和 needle 仅由小写英文字符组成 
// 
// Related Topics 双指针 字符串 字符串匹配 
// 👍 980 👎 0

/*
 * 题解
使用著名的Knuth-Morris-Pratt（KMP）算法，可以在 O(m + n) 时间利用动态规划完成匹配。
 */

#include <string>
#include<vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int strStr(string haystack, string needle) {
        int k = -1;
        int n = haystack.length();
        int p = needle.length();
        if(p == 0){
            return 0;
        }
        vector<int> next(p, -1);//-1表示不存在相同的最大前缀和后缀
        calNext(needle, next);
        for(int i = 0; i < n; ++i){
            while(k > -1 && needle[k + 1] != haystack[i]){
                k = next[k];//有部分匹配，往前回溯
            }
            if(needle[k + 1] == haystack[i]){
                ++k;
            }
            if(k == p - 1){
                return i - p + 1;//说明k移动到needle的最末端，返回相应的位置
            }
        }
        return -1;
    }

    //辅函数-计算next数组
    void calNext(const string &needle, vector<int> &next){
        for(int j = 1, p = -1; j < needle.length(); ++j){
            while(p > -1 && needle[p + 1] != needle[j]){
                p = next[p];//如果下一位不同，往前回溯
            }
            if(needle[p + 1] == needle[j]){
                ++p;//如果下一位相同，更新相同的最大前缀和最大后缀长
            }
            next[j] = p;
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)
