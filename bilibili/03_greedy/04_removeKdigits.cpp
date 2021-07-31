//
// Created by eryo on 2021/7/31.
//

#include <stdio.h>
#include <string>
#include <vector>

/*
	移除K个数字-402

	已知一个使用字符串表示的非负整数num，将num中的K个数字移除
	求移除K个数字后可以获得的最小的可能的新数字

	方法：
		使用栈存储最终结果或删除工作,从高位向低位遍历num,
		如果遍历的数字大于栈顶元素,则将该数字push入栈,
		如果小于栈顶元素则进行pop弹栈,
		直到栈为空或不能再删除数字(k=0)或栈顶小于当前元素为止。
	  需要注意：
	  	1.当所有数字都扫描完成以后，k仍然>0，
		2.当数字中有0出现
		3.最后结果如何储存为字符串返回
*/

class Solution{
public:
    std::string removeKdigits(std::string num, int k){
        std::vector<int> S;		//使用vector作为栈，因为栈可以遍历
        std::string result = "";//储存最终结果的字符串
        for(int i = 0; i < num.length(); i++){	//从最高位循环扫描数字
            int number = num[i] - '0';		//将字符型的数字转为整数使用
            while(S.size() != 0 && S.front() > number && k > 0){
                //当栈不空，栈顶元素大于数number，仍然可以删除数字时while循环继续
                S.pop_back();
                k--;
            }
            if(number != 0 || S.size() != 0 ){
                S.push_back(number);
            }
        }
        while(S.size() != 0 && k > 0){
            S.pop_back();
            k--;
        }
        for(int i = 0; i < S.size(); i++){
            result.append(1, '0' + S[i]);
        }
        if(result == ""){
            result = "0";
        }
        return result;
    }
};

int main(){

}