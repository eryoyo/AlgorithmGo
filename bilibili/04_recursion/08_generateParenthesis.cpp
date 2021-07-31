//
// Created by eryo on 2021/7/31.
//

#include <stdio.h>
#include <vector>
#include <string>

/*
	生成括号-22

	已知n组括号，开发一个程序，生成这n组括号所有的合法的组合可能

	方法：
		1.左括号和右括号的数量必须都为n
		2.只有左括号比右括号多的时候才能添加右括号
*/

class Solution{
public:
    std::vector<std::string> generateParenthesis(int n){
        std::vector<std::string> result;
        generate("", n, n, result);
        return result;
    }

public:		//left为还可以放置的左括号的个数，right为剩余右括号的个数
    void generate(std::string item, //item为用来生成的括号字符串
                  int left, int right,
                  std::vector<std::string> &result){
        //result为最终结果
        if(left == 0 && right == 0){
            result.push_back(item);
            return;
        }
        if(left > 0){
            generate(item + '(', left - 1, right, result);
        }
        if(right > left){
            generate(item + ')', left, right - 1, result);
        }
    }
};

int main(){
    std::vector<std::string> result;
    Solution s;
    result = s.generateParenthesis(2);
    for(int i = 0; i < result.size(); i++){
        printf("'%s'\n", result[i].c_str());
    }
    return 0;
}