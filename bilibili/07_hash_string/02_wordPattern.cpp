//
// Created by eryo on 2021/7/31.
//

#include <stdio.h>
#include <string>
#include <map>

/*
	词语模式-290

	已知字符串pattern和字符串str，确认str是否与pattern匹配，
	str与pattern匹配代表str中的单词与pattern中的字符一一对应
	pattern中只包含小写字符
	str中的单词只包含小写字符，使用空格分隔
	例如：
		pattern = "abba" str = "dog cat cat dog"匹配

	方法：
		 1.设置单词（字符串）到pattern的映射（哈希），
		 使用used[128]来记录pattern字符是否使用
		 2.遍历str，拆分单词，同时对应的向前移动指向pattern字符的指针
		 每拆分出一个单词判断
		 	如果该单词从未出现在哈希表中：
			 	如果当前指向的pattern字符已经被使用，则返回false
				将单词与当前指向的pattern字符做映射
				标记当前指向的pattern字符已使用
			如果该单词已经出现过：
				如果当前单词在哈希表中的映射字符不是当前指向的字符，则返回false
		3.如果单词个数和pattern的字符数目不等，返回false

	07 88:32 2/6
*/

class Solution{
public:
    bool wordPattern(std::string pattern, std::string str){

        std::map<std::string, char> word_map;		//单词到pattern字符的映射
        char used[128] = {0};	//已被映射的pattern字符

        std::string word;		//临时保存拆分出来的单词
        int pos = 0;			//当前指向的pattern字符

        str.push_back(' ');		//使无需特殊处理最后一个单词
        for(int i = 0; i < str.length(); i++){
            if(str[i] == ' '){		//遇到空格即拆分出一个单词
                if(pos == pattern.length()){
                    return false;	//若已分隔出一个单词但是已无pattern字符对应
                }
                //如果单词没有出现在哈希映射中
                if(word_map.find(word) == word_map.end()){
                    if(used[pattern[pos]]){
                        return false;
                    }
                    used[pattern[pos]] = 1;
                    word_map[word] = pattern[pos];
                }else{
                    if(word_map[word] != pattern[pos]){
                        return false;
                    }
                }
                word = "";
                pos++;
            } else{
                word += str[i];
            }
        }
        if(pos != pattern.length()){
            return false;
        }
        return true;
    }
};

int main(){
    std::string pattern = "abba";
    std::string str = "dog cat cat dog";
    Solution s;
    printf("%d\n", s.wordPattern(pattern, str));
    return 0;
}