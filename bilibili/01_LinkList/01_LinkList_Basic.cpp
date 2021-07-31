//
// Created by eryo on 2021/7/31.
//

#include<iostream>
#include<vector>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
};

int main() {
    //创建5个结点
    ListNode a;
    ListNode b;
    ListNode c;
    ListNode d;
    ListNode e;

    a.val = 10;
    b.val = 20;
    c.val = 30;
    d.val = 40;
    e.val = 50;
    //将5个结点连接起来
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = NULL;

    ListNode *head = &a;
    while(head){
        printf("%d\n", head->val);
        head = head->next;
    }

    return 0;
}