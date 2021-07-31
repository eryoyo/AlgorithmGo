//
// Created by eryo on 2021/7/31.
//

#include <stdio.h>
#include <queue>

/*
	寻找中位数-295

	设计一个数据结构，该数据结构动态的维护一组数据，且支持如下操作：
	1.添加元素：void addNum(int num)，将整型num添加到数据结构中
	2.返回数据的中位数：double findMedian(),

	方法：
		动态的维护一个最大堆和一个最小堆，最大堆存储一半数据，
		最小堆存储一半数据 ，维持最大堆的堆顶比最小堆的堆顶小
		1.当最大堆元素数量和最小堆相同时，
			如果新值大于最大堆堆顶则插入到最小堆
			如果新值小于最大堆堆顶则插入到最大堆
		2.当最大堆比最小堆多一个元素
			如果新值小于最大堆堆顶则将最大堆堆顶插入最小堆，将新元素加入最大堆
			如果新值大于最大堆堆顶则将新值插入最小堆
		3.当最小堆比最大值堆多一个元素
			如果新值小于最小堆堆顶，直接将新值插入到最大堆
			如果新值大于最小堆堆顶，将最小堆堆顶插入到最大堆，将新元素插入最小堆


*/

class MedianFinder{
	public:
		MedianFinder(){

		}

		void addNum(int num){
			if(big_queue.empty()){
				big_queue.push(num);
				return;
			}
			if(big_queue.size() == small_queue.size()){
				if(num > big_queue.top()){
					small_queue.push(num);
				}else{
					big_queue.push(num);
				}
			}else if(big_queue.size() > small_queue.size()){
				if(num > big_queue.top()){
					small_queue.push(num);
				}else{
					small_queue.push(big_queue.top());
					big_queue.pop();
					big_queue.push(num);
				}
			}else if(big_queue.size() < small_queue.size()){
				if(num < small_queue.top()){
					big_queue.push(num);
				}else{
					big_queue.push(small_queue.top());
					small_queue.pop();
					small_queue.push(num);
				}
			}
		}

		double findMedian(){
			if(big_queue.size() == small_queue.size()){
				return (big_queue.top() + small_queue.top()) / 2.0;
			}else if(big_queue.size() > small_queue.size()){
				return big_queue.top();
			}
			return small_queue.top();
		}

	private:
		std::priority_queue<int, std::vector<int>, std::greater<int> > small_queue;
		std::priority_queue<int, std::vector<int>, std::less<int> > big_queue;
};

int main(){

}