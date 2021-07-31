//
// Created by eryo on 2021/7/31.
//

#include<stdio.h>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr){}
};

ListNode* reverseBetween(ListNode* head, int m, int n){
    int change_len = n - m + 1;		//计算需要逆置的结点的个数
    ListNode *pre_head = nullptr;		//逆置段头结点的前驱
    ListNode * result = head;		//最终转换后的链表头结点， 非特殊情况即为head
    //将head向前移动m-1个位置
    while(head && --m) {
        pre_head = head;
        head = head->next;
    }
    //将modify_list_tail指向当前的head，即逆置后的链表尾
    ListNode *modify_list_tail = head;
    ListNode *new_head = nullptr;
    while(head && change_len){
        ListNode *next = head->next;
        head->next = new_head;
        new_head = head;
        head = next;
        --change_len;
    }
    //将逆置段的逆置后的尾结点和逆置段尾结点的后驱结点相连
    modify_list_tail->next = head;
    if(pre_head){		//如果pre_head不空，说明不是从第一个结点开始逆置的
        pre_head->next = new_head;
    }else{
        result = new_head;
    }
    return result;
}

int main() {
    ListNode a(1);
    ListNode b(2);
    ListNode c(3);
    ListNode d(4);
    ListNode e(5);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    ListNode *head = &a;
    printf("before reverse:\n");
    while(head){
        printf("%d\n", head->val);
        head = head->next;
    }
    head = reverseBetween(&a, 2, 4);
    printf("after reverse:\n");
    while(head){
        printf("%d\n", head->val);
        head = head->next;
    }

    return 0;
}