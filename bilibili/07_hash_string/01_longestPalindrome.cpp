//
// Created by eryo on 2021/7/31.
//

#include <stdio.h>
#include <string>

/*
	最长回文串-409

	已知一个只包括大小写字符的字符串，求用该字符串中的字符可以生成的最长回文字符串长度

	方法：
		1.字符数量为偶数的字符，全部使用
		2.字符数量为奇数的字符，去掉一个字符变为偶数数量，全部使用
		3.剩下的为数量为1的字符，任选一个放在中间

	07 66.18 1/6
*/

class Solution{
public:
    int longestPalindrome(std::string s){
        int char_map[128] = {0};		//字符哈希
        int max_length = 0;				//回文字符串偶数部分的最大长度
        int flag = 0;	//是否有中心点
        for(int i = 0; i < s.length(); i++){
            char_map[s[i]]++;			//统计字符个数
        }
        for(int i = 0; i < 128; i++){
            if(char_map[i] % 2 == 0){
                max_length += char_map[i];
            }else{
                max_length += char_map[i] - 1;
                flag = 1;
            }
        }
        return max_length + flag;
    }
};

int main(){

}