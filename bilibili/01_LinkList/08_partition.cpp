//
// Created by eryo on 2021/7/31.
//

#include <stdio.h>

/*
	链表划分-86

	已知链表头指针head和数值x，将所有小于x的结点放在大于或等于x的结点前
	且保持这些结点的相对位置


*/

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution{
public:
    ListNode *partition(ListNode *head, int x){
        ListNode less_head(0);
        ListNode more_head(0);		//设置两个临时的头结点
        ListNode *less_ptr = &less_head;
        ListNode *more_ptr = &more_head;	//对应指针指向这两个头结点
        while(head){
            if(head->val < x){
                less_ptr->next = head;		//如果结点值小于x，将该节点插入到less_ptr之后
                less_ptr = less_ptr->next;	//移动less_ptr
            }else{
                more_ptr->next = head;
                more_ptr = more_ptr->next;
            }
            head = head->next;
        }
        less_ptr->next = more_head.next;
        more_ptr->next = nullptr;			//将链表尾结点next置空
        return less_head.next;
    }
};

int main(){

}