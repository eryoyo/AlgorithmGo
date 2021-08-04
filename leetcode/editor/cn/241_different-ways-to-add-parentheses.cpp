//给定一个含有数字和运算符的字符串，为表达式添加括号，改变其运算优先级以求出不同的结果。你需要给出所有可能的组合的结果。有效的运算符号包含 +, - 以及 *
// 。 
//
// 示例 1: 
//
// 输入: "2-1-1"
//输出: [0, 2]
//解释: 
//((2-1)-1) = 0 
//(2-(1-1)) = 2 
//
// 示例 2: 
//
// 输入: "2*3-4*5"
//输出: [-34, -14, -10, -10, 10]
//解释: 
//(2*(3-(4*5))) = -34 
//((2*3)-(4*5)) = -14 
//((2*(3-4))*5) = -10 
//(2*((3-4)*5)) = -10 
//(((2*3)-4)*5) = 10 
// Related Topics 递归 记忆化搜索 数学 字符串 动态规划 
// 👍 401 👎 0

/*
 * 题解
利用分治思想，我们可以把加括号转化为，对于每个运算符号，先执行处理两侧的数学表达
式，再处理此运算符号。注意边界情况，即字符串内无运算符号，只有数字。
 */

#include<vector>
#include<string>
#include <sstream>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        //分治方法
//        vector<int> ways;
//        for(int i = 0; i < expression.length(); ++i){
//            char c = expression[i];
//            if(c == '+' || c == '-' || c== '*'){
//                vector<int> left = diffWaysToCompute(expression.substr(0, i));
//                vector<int> right = diffWaysToCompute(expression.substr(i + 1));
//                for(const int &l : left){
//                    for(const int &r : right){
//                        switch (c) {
//                            case '+': ways.push_back(l + r); break;
//                            case '-': ways.push_back(l - r); break;
//                            case '*': ways.push_back(l * r); break;
//                        }
//                    }
//                }
//            }
//        }
//        if(ways.empty()) ways.push_back(stoi(expression));
//        return ways;

        //动态规划
        vector<int> data;
        vector<char> ops;
        int num = 0;
        char op = ' ';
        istringstream ss(expression + '+');
        while(ss >> num && ss >> op){
            data.push_back(num);
            ops.push_back(op);
        }
        int n = data.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>()));
        for(int i = 0; i < n; ++i){
            for(int j = i; j >= 0; --j){
                if(i == j){
                    dp[j][i].push_back(data[i]);
                } else{
                    for(int k = j; k < i; k += 1){
                        for(auto left : dp[j][k]){
                            for(auto right : dp[k + 1][i]){
                                int val = 0;
                                switch (ops[k]) {
                                    case '+': val = left + right; break;
                                    case '-': val = left - right; break;
                                    case '*': val = left * right; break;
                                }
                                dp[j][i].push_back(val);
                            }
                        }
                    }
                }
            }
        }
        return dp[0][n - 1];
    }
};
//leetcode submit region end(Prohibit modification and deletion)
