//给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。 
//
// 有效字符串需满足： 
//
// 
// 左括号必须用相同类型的右括号闭合。 
// 左括号必须以正确的顺序闭合。 
// 
//
// 
//
// 示例 1： 
//
// 
//输入：s = "()"
//输出：true
// 
//
// 示例 2： 
//
// 
//输入：s = "()[]{}"
//输出：true
// 
//
// 示例 3： 
//
// 
//输入：s = "(]"
//输出：false
// 
//
// 示例 4： 
//
// 
//输入：s = "([)]"
//输出：false
// 
//
// 示例 5： 
//
// 
//输入：s = "{[]}"
//输出：true 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 104 
// s 仅由括号 '()[]{}' 组成 
// 
// Related Topics 栈 字符串 
// 👍 2535 👎 0

/*
 * 题解
括号匹配是典型的使用栈来解决的问题。我们从左往右遍历，每当遇到左括号便放入栈内，
遇到右括号则判断其和栈顶的括号是否是统一类型，是则从栈内取出左括号，否则说明字符串不
合法。
 */

#include <string>
#include <stack>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isValid(string s) {
        stack<char> parsed;
        for(int i = 0; i < s.length(); ++i){
            if(s[i] == '{' || s[i] == '[' || s[i] == '('){
                parsed.push(s[i]);
            }else{
                if(parsed.empty()){
                    return false;
                }
                char c = parsed.top();
                if((s[i] == '}' && c == '{') ||
                        (s[i] == ']' && c == '[') ||
                        (s[i] == ')' && c == '(')){
                    parsed.pop();
                } else{
                    return false;
                }
            }
        }
        return parsed.empty();
    }
};
//leetcode submit region end(Prohibit modification and deletion)
