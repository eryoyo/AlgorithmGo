//
// Created by eryo on 2021/7/31.
//

#include <stdio.h>
#include <queue>

/*
	使用队列实现栈-225

	设计一个栈，支持基本的栈操作，这个栈的内部存储结构为队列
	队列的方法只能包括push，front，pop，size，empty等标准方法

	方法：
		1.将新元素push到临时队列里面
		2.将原队列元素push到临时队列
		3.将临时队列元素push到原队列
*/

class MyStack{
	public:
		MyStack(){

		}

		void push(int x){
			std::queue<int> temp_queue;
			temp_queue.push(x);
			while(!_data.empty()){
				temp_queue.push(_data.front());
				_data.pop();
			}
			while(!temp_queue.empty()){
				_data.push(temp_queue.front());
				temp_queue.pop();
			}
		}

		int pop(){
			int x = _data.front();
			_data.pop();
			return x;
		}

		int top(){
			return _data.front();
		}

		bool empty(){
			return _data.empty();
		}

	private:
	std::queue<int> _data;
};

int main(){

}