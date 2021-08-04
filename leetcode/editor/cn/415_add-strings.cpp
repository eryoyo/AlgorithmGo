//给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和。 
//
// 
//
// 提示： 
//
// 
// num1 和num2 的长度都小于 5100 
// num1 和num2 都只包含数字 0-9 
// num1 和num2 都不包含任何前导零 
// 你不能使用任何內建 BigInteger 库， 也不能直接将输入的字符串转换为整数形式 
// 
// Related Topics 数学 字符串 模拟 
// 👍 412 👎 0

/*
 * 题解
因为相加运算是从后往前进行的，所以可以先翻转字符串，再逐位计算。这种类型的题考察
的是细节，如进位、位数差等等。
 */

#include <string>
#include <algorithm>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string addStrings(string num1, string num2) {
        string output("");
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int onelen = num1.length();
        int twolen = num2.length();
        if(onelen <= twolen){
            swap(num1, num2);
            swap(onelen, twolen);
        }
        int addbit = 0;
        for(int i = 0; i < twolen; ++i){
            int cur_sum = (num1[i] - '0') + (num2[i] - '0') + addbit;
            output += to_string((cur_sum) % 10);
            addbit = cur_sum < 10 ? 0 : 1;
        }
        for(int i = twolen; i < onelen; ++i){
            int cur_sum = (num1[i] - '0') + addbit;
            output += to_string(cur_sum % 10);
            addbit = cur_sum < 10 ? 0 : 1;
        }
        if(addbit){
            output += "1";
        }
        reverse(output.begin(), output.end());
        return output;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
