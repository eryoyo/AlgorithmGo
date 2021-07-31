//
// Created by eryo on 2021/7/31.
//

#include <stdio.h>
#include <stack>
#include <string>

/*
	简单计算器-224

	输入一个字符串存储的数学表达式，符号包括"("、")"、"+"、"-" 四种
	输入的字符中可能出现空格字符

	方法：状态机
		STATE_BEGIN->		"0"-"9"			->NUMBER_STATE
		STATE_BEGIN->		"("				->OPERATION_STATE
		NUMBER_STATE->		"0"-"9"			->NUMBER_STATE
		NUMBER_STATE->		"+""-"			->OPERATION_STATE
		OPERATION_STATE->	"0"-"9""("		->NUMBER_STATE
*/

class Solution{
public:
    void compute(std::stack<int> &number_stack, std::stack<char> &operation_stack){
        if(number_stack.size() < 2){
            return;
        }
        int num2 = number_stack.top();
        number_stack.pop();
        int num1 = number_stack.top();
        number_stack.pop();
        if(operation_stack.top() == '+'){
            number_stack.push(num1 + num2);
        }else if(operation_stack.top() == '-'){
            number_stack.push(num1 - num2);
        }
        operation_stack.pop();
    }

    int calculate(std::string s){
        static const int STATE_BEGIN = 0;
        static const int NUMBER_STATE = 1;
        static const int OPERATION_STATE = 2;
        std::stack<int> number_stack;			//数值栈
        std::stack<char> operation_stack;		//运算符栈
        int number = 0;
        int STATE = STATE_BEGIN;				//开始状态
        int compute_flag = 0;					//输入第一个运算数的时候为0，可以计算的时候为1
        for(int i = 0; i < s.length(); i++){
            if(s[i] == ' '){
                continue;		//忽略空格
            }
            switch(STATE){
                case STATE_BEGIN:
                    if(s[i] >= '0' && s[i] <= '9'){
                        STATE = NUMBER_STATE;
                    }else{
                        STATE = OPERATION_STATE;
                    }
                    i--;				//转换状态时要退格
                    break;
                case NUMBER_STATE:
                    if(s[i] >= '0' && s[i] <= '9'){
                        number = number * 10 + s[i] - '0';
                    }else{
                        number_stack.push(number);
                        if(compute_flag == 1){
                            compute(number_stack, operation_stack);
                        }
                        number = 0;
                        i--;			//转换状态时退格
                        STATE = OPERATION_STATE;
                    }
                    break;
                case OPERATION_STATE:
                    if(s[i] == '+' || s[i] == '-'){
                        operation_stack.push(s[i]);
                        compute_flag = 1;
                    }else if(s[i] == '('){
                        STATE = NUMBER_STATE;
                        compute_flag = 0;
                    }else if(s[i] >= '0' && s[i] <= '9'){
                        STATE = NUMBER_STATE;
                        i--;
                    }else if(s[i] == ')'){
                        compute(number_stack, operation_stack);
                    }
                    break;
            }
        }
        if(number != 0){
            number_stack.push(number);
            compute(number_stack, operation_stack);
        }
        if(number == 0 && number_stack.empty()){
            return 0;
        }
        return number_stack.top();
    }
};

int main(){

}