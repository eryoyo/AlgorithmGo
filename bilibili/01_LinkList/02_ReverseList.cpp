//
// Created by eryo on 2021/7/31.
//

#include<iostream>
#include<vector>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){}
};

ListNode* reverseList(ListNode* head){
    ListNode* new_head = nullptr;
    while(head){
        ListNode* next = head->next;
        head->next = new_head;
        new_head = head;
        head = next;
    }
    return new_head;
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
    head = reverseList(&a);
    printf("after reverse:\n");
    while(head){
        printf("%d\n", head->val);
        head = head->next;
    }

    return 0;
}