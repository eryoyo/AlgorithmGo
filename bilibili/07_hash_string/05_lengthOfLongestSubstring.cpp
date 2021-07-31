//
// Created by eryo on 2021/7/31.
//

#include <stdio.h>
#include <string>

/*
	无重复字符的最长子串-3

	已知一个字符串，求该字符串的无重复字符的最长子串的长度
	注意：s = "pwwkew"->"wke","pwke"是子序列而非子串

	方法：
		1.设置一个记录字符数量的字符哈希，char_map
		2.设置一个记录当前满足条件的最长子串变量word
		3.设置两个指针（记作指针i和指针begin）指向字符串的第一个字符
		4.设置最长满足条件的子串的长度result；
		5.i指针向后逐个扫描字符串中的字符，在这个过程中，使用char_map
		记录字符数量
		如果word中没有出现该字符，对word尾部添加字符并检查result是否需要更新
		否则：begin指针向前移动，更新char_map中的字符数量，直到字符s[i]
		      的数量为1，更新1word，将word复制为begin与i之间的子串
		在整个过程中，使用begin与i维护一个窗口，该窗口中的子串满足题目条件
		（无重复的字符），窗口线性向前滑动，整体时间复杂度为O(n).
*/

class Solution{
public:
    int lengthOfLongestSubstring(std::string s){
        int begin = 0;
        int result = 0;
        std::string word = "";
        int char_map[128] = {0};
        for(int i = 0; i < s.length(); i++){
            char_map[s[i]]++;
            if(char_map[s[i]] == 1){
                word += s[i];
                if(result < word.length()){
                    result = word.length();
                }
            }else{
                while(char_map[s[i]] > 1){
                    char_map[s[begin]]--;
                    begin++;
                }
                word = "";
                for(int j = begin; j <= i; j++){
                    word += s[j];
                }
            }
        }
        return result;
    }
};

int main(){
    std::string s = "abcbadab";
    Solution solve;
    printf("%d\n", solve.lengthOfLongestSubstring(s));
    return 0;
}