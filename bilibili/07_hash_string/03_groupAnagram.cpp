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
		1.遍历单词数组，每次循环时对单词进行排序
		2.判断排序后的单词是否已经出现过，完成单词到单词数组的映射
*/

class Solution{
	public:
		std::vector<std::vector<std::string> > groupAnagram(
								std::vector<std::string>& strs){
			std::map<std::string, std::vector<std::string> > anagram;
			//内部进行排序的各个单词为key，以字符串为value，
			//存储各个字符数量相同的字符串
			std::vector<std::vector<std::string> > result;	//存储最终的结果
			for(int i = 0; i < strs.size(); i++){
				std::string str = strs[i];
				std::sort(str.begin(), str.end());	//对str内部进行排序
				if(anagram.find(str) == anagram.end()){
					std::vector<std::string> item;
					anagram[str] = item;
				}
				anagram[str].push_back(strs[i]);
			}
			std::map<std::string, std::vector<std::string> > ::iterator it;
			for(it = anagram.begin(); it != anagram.end(); it++){
				result.push_back((*it).second);
			}
			return result;
		}
};

int main(){

}