//给你一个字符串表达式 s ，请你实现一个基本计算器来计算并返回它的值。 
//
// 整数除法仅保留整数部分。 
//
// 
// 
// 
//
// 示例 1： 
//
// 
//输入：s = "3+2*2"
//输出：7
// 
//
// 示例 2： 
//
// 
//输入：s = " 3/2 "
//输出：1
// 
//
// 示例 3： 
//
// 
//输入：s = " 3+5 / 2 "
//输出：5
// 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 3 * 105 
// s 由整数和算符 ('+', '-', '*', '/') 组成，中间由一些空格隔开 
// s 表示一个 有效表达式 
// 表达式中的所有整数都是非负整数，且在范围 [0, 231 - 1] 内 
// 题目数据保证答案是一个 32-bit 整数 
// 
// 
// 
// Related Topics 栈 数学 字符串 
// 👍 438 👎 0

/*
 * 题解
如果我们在字符串左边加上一个加号，可以证明其并不改变运算结果，且字符串可以分割成
多个 < 一个运算符，一个数字 > 对子的形式；这样一来我们就可以从左往右处理了。由于乘除的
优先级高于加减，因此我们需要使用一个中间变量来存储高优先度的运算结果。
此类型题也考察很多细节处理，如无运算符的情况，和多个空格的情况等等。
 */

#include <string>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int calculate(string s) {
        int i = 0;
        return parseExpress(s, i);
    }

    //辅函数-递归parse从位置i开始的剩余字符串
    int parseExpress(const string &s, int &i){
        char op = '+';
        long left = 0;
        long right = 0;
        while(i < s.length()){
            if(s[i] != ' '){
                long n = parseNum(s, i);
                switch (op) {
                    case '+': left += right; right = n; break;
                    case '-': left += right; right = -n; break;
                    case '*': right *= n; break;
                    case '/': right /= n; break;
                }
                if(i < s.length()){
                    op = s[i];
                }
            }
            ++i;
        }
        return left + right;
    }

    //辅函数-parse从位置i开始的第一个数字
    long parseNum(const string& s, int & i){
        long n = 0;
        while(i < s.length() && isdigit(s[i])){
            n = 10 * n + (s[i++] - '0');
        }
        return n;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
