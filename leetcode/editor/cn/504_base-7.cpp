//给定一个整数，将其转化为7进制，并以字符串形式输出。 
//
// 示例 1: 
//
// 
//输入: 100
//输出: "202"
// 
//
// 示例 2: 
//
// 
//输入: -7
//输出: "-10"
// 
//
// 注意: 输入范围是 [-1e7, 1e7] 。 
// Related Topics 数学 
// 👍 92 👎 0

/*
 * 题解
进制转换类型的题，通常是利用除法和取模（mod）来进行计算，同时也要注意一些细节，如
负数和零。如果输出是数字类型而非字符串，则也需要考虑是否会超出整数上下界。
 */

#include<vector>
#include<string>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string convertToBase7(int num) {
        if(num == 0){
            return "0";
        }
        bool is_negative = num < 0;
        if(is_negative){
            num = -num;
        }
        string ans;
        while(num){
            int a = num / 7;
            int b = num % 7;
            ans = to_string(b) + ans;
            num = a;
        }
        return is_negative ? "-" + ans : ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
