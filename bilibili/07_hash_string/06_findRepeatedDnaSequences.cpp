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

	方法1：枚举法
*/

class Solution{
public:
    std::vector<std::string> findRepeatedDnaSequences(std::string s){
        std::map<std::string, int> word_map;	//<单词，单词数量>
        std::vector<std::string> result;
        for(int i = 0; i < s.length(); i++){
            std::string word = s.substr(i, 10);
            if(word_map.find(word) != word_map.end()){
                word_map[word]++;
            }else{
                word_map[word] = 1;
            }
        }
        std::map<std::string, int> ::iterator it;
        for(it = word_map.begin(); it != word_map.end(); it++){
            if((*it).second > 1){
                result.push_back(it->first);
            }
        }
        return result;
    }
};