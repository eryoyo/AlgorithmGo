//
// Created by eryo on 2021/7/31.
//

#include <stdio.h>

/*
	排序链表的合并-21

	已知两个已排序的链表头结点指针l1和l2，将这两个链表合并，合并后仍为有序的，返回合并后的头结点

	方法：
		1.设一个临时头结点
		2.比较l1和l2结点的大小，将较小的结点插入到pre指针的next，移动pre，并向后移动l1,l2里面较小的
*/

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution{
public:
    ListNode* mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode temp_head(0);			//设置临时头结点temp_head
        ListNode *pre = &temp_head;		//使用pre指针指向temp_head
        while(l1 && l2){
            if(l1->val < l2->val){		//l1，l2同时不为空的时候对其值进行比较
                pre->next = l1;
                l1 = l1->next;
            }else{
                pre->next = l2;
                l2 = l2->next;
            }
            pre = pre->next;
        }
        if(l1){
            pre->next = l1;
        }
        if(l2){
            pre->next = l2;
        }
        return temp_head.next;
    }

};

int main(){

}



