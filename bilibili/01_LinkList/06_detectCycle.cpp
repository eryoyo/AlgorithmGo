//
// Created by eryo on 2021/7/31.
//

#include <stdio.h>
#include <set>

/*
	链表求环 - 142

	已知链表中可能存在环，若有环返回环起始结点，否则返回null

	方法1：使用set
		 1.遍历链表，将链表中结点对应的指针插入set
		 2.在遍历是插入结点前，需要在set中查找，第一个在set中发现的结点地址即是链表环的起点
*/

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution{
public:
    ListNode *detectCycle(ListNode *head){
        std::set<ListNode*> node_set;
        while(head){
            if(node_set.find(head) != node_set.end()){
                return head;
            }
            node_set.insert(head);
            head = head->next;
        }
        return nullptr;
    }
};

int main(){

}