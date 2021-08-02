//实现 int sqrt(int x) 函数。 
//
// 计算并返回 x 的平方根，其中 x 是非负整数。 
//
// 由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。 
//
// 示例 1: 
//
// 输入: 4
//输出: 2
// 
//
// 示例 2: 
//
// 输入: 8
//输出: 2
//说明: 8 的平方根是 2.82842..., 
//     由于返回类型是整数，小数部分将被舍去。
// 
// Related Topics 数学 二分查找 
// 👍 738 👎 0


using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int mySqrt(int x) {
        long a = x;
        while(a * a > x){
            a = (a + x / a) / 2;
        }
        return a;
//        if(x == 0){
//            return x;
//        }
//        int left = 1;
//        int right = x;
//        int mid;
//        int sqrt;
//        while(left <= right){
//            mid = left + (right - left) / 2;
//            sqrt = x / mid;
//            if(sqrt == mid){
//                return mid;
//            }else if(mid > sqrt){
//                right = mid - 1;
//            }else{
//                left = mid + 1;
//            }
//        }
//        return right;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
