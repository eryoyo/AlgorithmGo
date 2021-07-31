//
// Created by eryo on 2021/7/31.
//

#include <stdio.h>

/*
	相交链表-第三种方法

	第二种方法：
		1.计算headA链表的长度和链表headB的长度，计算出长度差
		2.将较长链表的指针移动到和较短链表指针对齐的位置
		3.headA和headB同时移动，当两个指针指向同一个结点的时候就找到的交点

	要求满足时间复杂度O(n), 空间复杂度O(1) ，此时满足要求
*/

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//获取链表长度
int get_list_length(ListNode *head){
    int len = 0;
    while(head){
        ++len;
        head = head->next;
    }
    return len;
}

//将长链表向后移动
ListNode *forward_long_list(int long_len, int short_len, ListNode *head){
    int delta = long_len - short_len;
    while(head && delta){
        head = head->next;
        --delta;
    }
    return head;
}

class Solution{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB){
        int list_A_len = get_list_length(headA);
        int list_B_len = get_list_length(headB);
        if(list_A_len > list_B_len){
            forward_long_list(list_A_len, list_B_len, headA);
        }else if(list_A_len < list_B_len){
            forward_long_list(list_B_len, list_A_len, headB);
        }
        while(headA && headB){
            if(headA == headB){
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
        }
        return nullptr;
    }
};
