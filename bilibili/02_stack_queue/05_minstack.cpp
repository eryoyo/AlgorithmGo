//
// Created by eryo on 2021/7/31.
//

#include <stdio.h>
#include <stack>

/*
	包含min函数的栈-155

	方法：
		用另一个栈储存所有状态下的最小值,一个数据栈和一个最小值栈
*/

class MinStack{
public:
    MinStack(){

    }

    void push(int x){
        _data.push(x);
        if(_min.empty()){
            _min.push(x);
        }else{
            if(x > _min.top()){
                x = _min.top();
            }
            _min.push(x);
        }
    }

    void pop(){
        _data.pop();
        _min.pop();
    }

    int top(){
        return _data.top();
    }

    int getMin(){
        return _min.top();
    }

private:
    std::stack<int> _data;	//数据栈
    std::stack<int> _min;	//最小值栈
};

int main(){

}