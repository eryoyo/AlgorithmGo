//假设有一个很长的花坛，一部分地块种植了花，另一部分却没有。可是，花不能种植在相邻的地块上，它们会争夺水源，两者都会死去。 
//
// 给你一个整数数组 flowerbed 表示花坛，由若干 0 和 1 组成，其中 0 表示没种植花，1 表示种植了花。另有一个数 n ，能否在不打破种植规则
//的情况下种入 n 朵花？能则返回 true ，不能则返回 false。 
//
// 
//
// 示例 1： 
//
// 
//输入：flowerbed = [1,0,0,0,1], n = 1
//输出：true
// 
//
// 示例 2： 
//
// 
//输入：flowerbed = [1,0,0,0,1], n = 2
//输出：false
// 
//
// 
//
// 提示： 
//
// 
// 1 <= flowerbed.length <= 2 * 104 
// flowerbed[i] 为 0 或 1 
// flowerbed 中不存在相邻的两朵花 
// 0 <= n <= flowerbed.length 
// 
// Related Topics 贪心 数组 
// 👍 369 👎 0

/*
 * 解答：
 * 首先将花坛首尾补齐，然后通过一个循环处理，每一个间隙可以种植(n-1)/2朵花
 */

#include<vector>
#include<iostream>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int size = flowerbed.size();
        if(size == 1){
            return n <= 1 - flowerbed[0];
        }
        int sum = 0;
        //补齐首尾
        if(flowerbed[1] != 1){
            sum += 1 - flowerbed[0];
            flowerbed[0] = 1;
        }
        if(flowerbed[size - 2] != 1){
            sum += 1 - flowerbed[size - 1];
            flowerbed[size - 1] = 1;
        }
        int temp = 0;
        for(int i = 1; i < size; i++){
            if(flowerbed[i] == 0){
                temp++;
            } else{
                sum += (temp - 1) / 2;
                temp = 0;
            }
        }
        return sum >= n;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
