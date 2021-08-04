//给定一个字符串数组 words，找到 length(word[i]) * length(word[j]) 的最大值，并且这两个单词不含有公共字母。你可以认为
//每个单词只包含小写字母。如果不存在这样的两个单词，返回 0。 
//
// 
//
// 示例 1: 
//
// 
//输入: ["abcw","baz","foo","bar","xtfn","abcdef"]
//输出: 16 
//解释: 这两个单词为 "abcw", "xtfn"。 
//
// 示例 2: 
//
// 
//输入: ["a","ab","abc","d","cd","bcd","abcd"]
//输出: 4 
//解释: 这两个单词为 "ab", "cd"。 
//
// 示例 3: 
//
// 
//输入: ["a","aa","aaa","aaaa"]
//输出: 0 
//解释: 不存在这样的两个单词。
// 
//
// 
//
// 提示： 
//
// 
// 2 <= words.length <= 1000 
// 1 <= words[i].length <= 1000 
// words[i] 仅包含小写字母 
// 
// Related Topics 位运算 数组 字符串 
// 👍 180 👎 0

/*
 * 题解
怎样快速判断两个字母串是否含有重复数字呢？可以为每个字母串建立一个长度为 26 的二
进制数字，每个位置表示是否存在该字母。如果两个字母串含有重复数字，那它们的二进制表示
的按位与不为 0。同时，我们可以建立一个哈希表来存储字母串（在数组的位置）到二进制数字
的映射关系，方便查找调用。
 */

#include<vector>
#include <string>
#include <unordered_map>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maxProduct(vector<string>& words) {
        unordered_map<int, int> hash;
        int ans = 0;
        for(const string &word : words){
            int mask = 0;
            int size = word.size();
            for(const char& c : word){
                mask |= 1 << (c - 'a');
            }
            hash[mask] = max(hash[mask], size);
            for(const auto& [h_mask, h_len] : hash){
                if(!(mask & h_mask)){
                    ans = max(ans, size * h_len);
                }
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
