//
// Created by eryo on 2021/7/31.
//

#include <stdio.h>
#include <vector>

/*
	递归函数基础
*/

//链表数据结构
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

//递归的将链表中的数据push到vector中
void add_to_vector(ListNode *head, std::vector<int> &vec){
    if(!head){		//如果head为空则结束递归
        return;
    }
    vec.push_back(head->val);
    head = head->next;
}

int main() {

}