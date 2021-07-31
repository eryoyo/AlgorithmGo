//
// Created by eryo on 2021/7/31.
//

#include<set>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB){
        set<ListNode*> node_set;		//设置查找集合node_set
        while(headA){
            node_set.insert(headA);			//将链表A中的结点插入到node_set
            headA = headA->next;
        }
        while(headB){
            if(node_set.find(headB) != node_set.end()){
                return headB;
            }
            headB = headB->next;
        }
        return nullptr;
    }
};

int main() {
    return 0;
}