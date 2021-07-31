//
// Created by eryo on 2021/7/31.
//
#include <stdio.h>
#include <set>

/*
	链表求环 - 142

	已知链表中可能存在环，若有环返回环起始结点，否则返回null

	方法2：使用快慢指针
		  1.快指针每次走两步，慢指针每次走一步，
		  2.假如有环就会相遇
		  3.一个从相遇点出发 ，另一个从起点出发，再次相遇点就是环的起点 v
*/

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution{
public:
    ListNode *detectCycle(ListNode *head){
        ListNode *fast = head;			//设置快慢指针
        ListNode *slow = head;
        ListNode *meet = nullptr;
        while(fast) {
            slow = slow->next;			//先各自走一步
            fast = fast->next;
            if(!fast){
                return nullptr;
            }
            fast = fast->next;
            if(fast == slow){
                meet = fast;
                break;
            }
        }
        if(meet == nullptr){
            return nullptr;
        }
        while(head && meet){
            if(head == meet){
                return head;
            }
            head = head->next;
            meet = meet->next;
        }
        return nullptr;
    }
};

int main(){

}