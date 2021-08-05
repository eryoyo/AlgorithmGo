//给定两个字符串 s 和 t，判断它们是否是同构的。 
//
// 如果 s 中的字符可以按某种映射关系替换得到 t ，那么这两个字符串是同构的。 
//
// 每个出现的字符都应当映射到另一个字符，同时不改变字符的顺序。不同字符不能映射到同一个字符上，相同字符只能映射到同一个字符上，字符可以映射到自己本身。 
//
// 
//
// 示例 1: 
//
// 
//输入：s = "egg", t = "add"
//输出：true
// 
//
// 示例 2： 
//
// 
//输入：s = "foo", t = "bar"
//输出：false 
//
// 示例 3： 
//
// 
//输入：s = "paper", t = "title"
//输出：true 
//
// 
//
// 提示： 
//
// 
// 可以假设 s 和 t 长度相同。 
// 
// Related Topics 哈希表 字符串 
// 👍 374 👎 0

/*
 * 题解
我们可以将问题转化一下：记录两个字符串每个位置的字符第一次出现的位置，如果两个字
符串中相同位置的字符与它们第一次出现的位置一样，那么这两个字符串同构。举例来说，对于
“paper”和“title”，假设我们现在遍历到第三个字符“p”和“t”，发现它们第一次出现的位置都
在第一个字符，则说明目前位置满足同构。
 */

#include <string>
#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> s_first_index(256, 0);
        vector<int> t_first_index(256, 0);
        for(int i = 0; i < s.length(); ++i){
            if(s_first_index[s[i]] != t_first_index[t[i]]){
                return false;
            }
            s_first_index[s[i]] = t_first_index[t[i]] = i + 1;
        }
        return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
