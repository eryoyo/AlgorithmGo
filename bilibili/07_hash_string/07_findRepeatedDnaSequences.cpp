//
// Created by eryo on 2021/7/31.
//

#include <stdio.h>
#include <string>
#include <vector>
#include <map>

/*
	重复的DNA序列-187

	将DNA序列看做是只包含['A', 'C', 'G', 'T']四个字符的字符串
	给一个DNA字符串，找到所有长度为10的且出现超过1次的子串

	方法2：
		['A', 'C', 'G', 'T']进行整数编码[00, 01, 10, 11]
		1.设置全局整数哈希int g_hash_map[1048576]; 1048576 = 2^20
		2.将DNA字符串的前10个字符使用左移位运算转换为key，g_hash_map[key]++
		3.后续的移动：
			1) key = key >> 2	//后面的是高位
			2) key = key | ((新位) << 18)
*/

int g_hash_map[1048576] = {0};

std::string change_int_to_DNA(int DNA){
    static const char DNA_CHAR[] = {'A', 'C', 'G', 'T'};
    std::string str;
    for(int i = 0; i < 10; i++){
        str += DNA_CHAR[DNA & 3];
        DNA = DNA >> 2;
    }
    return str;
}

class Solution{
public:
    std::vector<std::string> findRepeatedDnaSequences(std::string s){
        std::vector<std::string> result;
        if(s.length() < 10){
            return result;
        }
        for(int i = 0; i < 1048576; i++){
            g_hash_map[i] = 0;
        }
        int char_map[128] = {0};
        char_map['A'] = 0;
        char_map['C'] = 1;
        char_map['G'] = 2;
        char_map['T'] = 3;

        int key = 0;
        for(int i = 9; i >= 0; i--){
            key = (key << 2) + char_map[s[i]];
        }
        g_hash_map[key] = 1;
        for(int i = 10; i < s.length(); i++){
            key = key >> 2;
            key = key | (char_map[s[i]] << 18);
            g_hash_map[key]++;
        }
        for(int i = 0; i < 1048576; i++){
            if(g_hash_map[i] > 1){
                result.push_back(change_int_to_DNA(i));
            }
        }
        return result;
    }
};

int main(){
    std::string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    Solution solve;
    std::vector<std::string> result = solve.findRepeatedDnaSequences(s);
    for(int i = 0; i < result.size(); i++){
        printf("%s\n", result[i].c_str());
    }
}