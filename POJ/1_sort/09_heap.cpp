//
// Created by eryo on 2021/8/5.
//

#include<vector>

using namespace std;

//0号位置空着
vector<int> heap(1);
//int N = 1;

//上浮
void swim(int pos){
    while(pos > 1 && heap[pos / 2] < heap[pos]){
        swap(heap[pos / 2], heap[pos]);
        pos /= 2;
    }
}

//下沉
void sink(int pos){
    int N = heap.size();
    while(2 * pos < N){
        int i = 2 * pos;
        if(i < N - 1 && heap[i] < heap[i + 1]){
            ++i;
        }
        if(heap[pos] >= heap[i]){
            break;
        }
        swap(heap[pos], heap[i]);
        pos = i;
    }
}

//获得最大值
int top(){
    return heap[1];
}

//插入任意值：将新的数字放在最后一位，然后上浮
void push(int k){
    heap.push_back(k);
    swim(heap.size() - 1);
}

//删除最大值：将最后一个数字挪到开头，然后下沉
void pop(){
    heap[1] = heap.back();
    heap.pop_back();
    sink(1);
}