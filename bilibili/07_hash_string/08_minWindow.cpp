//
// Created by eryo on 2021/7/31.
//

#include <stdio.h>
#include <string>
#include <vector>

/*
	最小窗口子串-76

	已知字符串S与字符串T，求在S中的最小窗口（区间），使得这个区间中包含了
	字符串T中的所有字符

	方法：
		1.设置两个字符哈希数组，map_s和map_t，其中储存着各个字符数量
		2.设置两个指针i和begin，指向字符串中的第一个字符
		3.i逐渐向前移动扫描字符，在这个过程中循环检查begin指针是否可以向前移动
			如果begin指向的字符T中没有出现直接前移
			如果begin指向的字符T中出现了，但是当前窗口中的该字符数量足够，向前移动begin，更新map_s
			否则不能移动begin
		4.每次移动检查一下是否可以更新最终结果
*/

bool is_window_ok(int map_s[], int map_t[], std::vector<int> &vec_t){
    for(int i = 0; i < vec_t.size(); i++){
        if(map_s[vec_t[i]] < map_t[vec_t[i]]){
            return false;
        }
    }
    return true;
}

class Solution{
public:
    std::string minWindow(std::string s, std::string t){
        const int MAX_ARRAY_LEN = 128;
        int map_t[MAX_ARRAY_LEN] = {0};
        int map_s[MAX_ARRAY_LEN] = {0};
        std::vector<int> vec_t;		//记录t中有哪些字符
        for(int i = 0; i < t.length(); i++){
            map_t[t[i]]++;
        }
        for(int i = 0; i < MAX_ARRAY_LEN; i++){
            if(map_t[i] > 0){
                vec_t.push_back(i);
            }
        }

        int window_begin = 0;	//最小窗口起始指针
        std::string result = "";		//最小窗口对应的字符串
        for(int i = 0; i < s.length(); i++){
            map_s[s[i]]++;
            while(window_begin < i){
                char begin_ch = s[window_begin];
                if(map_t[begin_ch] == 0){	//begin指向的字符没有在T中出现
                    window_begin++;
                }else if(map_s[begin_ch] > map_t[begin_ch]){
                    window_begin++;
                    map_s[begin_ch]--;
                } else{
                    break;
                }
            }
            if(is_window_ok(map_s, map_t, vec_t)){
                int new_window_len = i - window_begin + 1;
                if(result == "" || result.length() > new_window_len){
                    result = s.substr(window_begin, new_window_len);
                }
            }
        }

        return result;
    }
};

int main(){
    Solution s;
    std::string result = s.minWindow("ADOBECODEBANC", "ABC");
    printf("%s\n", result.c_str());
    result = s.minWindow("MADOBCCABEC", "ABCC");
    printf("%s\n", result.c_str());
    result = s.minWindow("aa", "aa");
    printf("%s\n", result.c_str());

    return 0;
}