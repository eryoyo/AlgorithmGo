//
// Created by eryo on 2021/7/31.
//

#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

/*
	同字符词语分组-49

	已知一组字符串，将所有anagram（由颠倒字母顺序而构成的字）放到一起输出

	方法：
		使用一个大小为26的数组为key，储存着各个字母的数量，
		value还是应该字符串数组
		1.遍历单词数组，每次循环时生成每个单词的数组
		2.判断该vector是否已经出现过，完成单词到单词数组的映射

	07 121:46 3/6
*/

void change_to_vector(std::string &str, std::vector<int> &vec){
    for(int i = 0; i < 26; i++){
        vec.push_back(0);
    }
    for(int i = 0; i < str.length(); i++){
        vec[str[i] - 'a']++;
    }
}

class Solution{
public:
    std::vector<std::vector<std::string> > groupAnagram(
            std::vector<std::string>& strs){
        std::map<std::vector<int>, std::vector<std::string> > anagram;	//!!!
        //内部进行排序的各个单词为key，以字符串为value，
        //存储各个字符数量相同的字符串
        std::vector<std::vector<std::string> > result;	//存储最终的结果
        for(int i = 0; i < strs.size(); i++){
            std::vector<int> vec;
            change_to_vector(strs[i], vec);
            if(anagram.find(vec) == anagram.end()){
                std::vector<std::string> item;
                anagram[vec] = item;
            }
            anagram[vec].push_back(strs[i]);
        }
        std::map<std::vector<int>, std::vector<std::string> > ::iterator it;
        for(it = anagram.begin(); it != anagram.end(); it++){
            result.push_back((*it).second);
        }
        return result;
    }
};

int main(){

}