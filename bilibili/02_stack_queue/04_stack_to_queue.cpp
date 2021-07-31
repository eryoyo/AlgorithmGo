//
// Created by eryo on 2021/7/31.
//

#include <stdio.h>
#include <stack>

/*
	使用栈实现队列-232

	方法：
		1.将原数据栈的元素push到临时栈中
		2.将新元素push到原数据栈
		3.将临时数据栈里面的数据push到原数据栈
*/

class MyQueue{
public:
    MyQueue(){

    }

    void push(int x){
        std::stack<int> temp_stack;
        while(!_data.empty()){
            temp_stack.push(_data.top());
            _data.pop();
        }
        _data.push(x);
        while(!temp_stack.empty()){
            _data.push(temp_stack.top());
            temp_stack.pop();
        }
    }

    int pop(){
        int x = _data.top();
        _data.pop();
        return x;
    }

    int front(){
        return _data.top();
    }

    bool empty(){
        return _data.empty();
    }

private:
    std::stack<int> _data;
};

int main(){

}