//统计所有小于非负整数 n 的质数的数量。 
//
// 
//
// 示例 1： 
//
// 输入：n = 10
//输出：4
//解释：小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。
// 
//
// 示例 2： 
//
// 输入：n = 0
//输出：0
// 
//
// 示例 3： 
//
// 输入：n = 1
//输出：0
// 
//
// 
//
// 提示： 
//
// 
// 0 <= n <= 5 * 106 
// 
// Related Topics 数组 数学 枚举 数论 
// 👍 721 👎 0

/*
 * 质数又称素数，指的是指在大于 1 的自然数中，除了 1 和它本身以外不再有其他因数的自然
数。值得注意的是，每一个数都可以分解成质数的乘积。

 题解
埃拉托斯特尼筛法（Sieve of Eratosthenes，简称埃氏筛法）是非常常用的，判断一个整数是
否是质数的方法。并且它可以在判断一个整数 n 时，同时判断所小于 n 的整数，因此非常适合这
道题。其原理也十分易懂：从 1 到 n 遍历，假设当前遍历到 m，则把所有小于 n 的、且是 m 的倍
数的整数标为和数；遍历完成后，没有被标为和数的数字即为质数。
 */

#include <vector>
#include<cmath>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int countPrimes(int n) {
//        if(n <= 2){
//            return 0;
//        }
//        vector<bool> prime(n, true);
//        int count = n - 2;//去掉不是质数的1
//        for(int i = 2; i < n; ++i){
//            if(prime[i]){
//                for(int j = 2 * i; j < n; j += i){
//                    if(prime[j]){
//                        prime[j] = false;
//                        --count;
//                    }
//                }
//            }
//        }
//        return count;

        //利用质数的一些性质，我们可以进一步优化该算法。
        if(n <= 2){
            return 0;
        }
        vector<bool> prime(n, true);
        int i = 3;
        int sqrtn = sqrt(n);
        int count = n / 2;//偶数一定不是质数
        while(i <= sqrtn){//最小质因子一定小于等于开方数
            for(int j = i * i; j < n; j += 2 * i){// 避免偶数和重复遍历
                if(prime[j]){
                    --count;
                    prime[j] = false;
                }
            }
            do{
                i += 2;
            }while(i <= sqrtn && !prime[i]);// 避免偶数和重复遍历
        }
        return count;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
