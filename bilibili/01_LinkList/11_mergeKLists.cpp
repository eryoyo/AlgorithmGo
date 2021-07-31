//
// Created by eryo on 2021/7/31.
//

#include <stdio.h>
#include <vector>
#include <algorithm>

/*
	有序链表数组的合并（多个有序链表的合并）-23

	方法1：
		进行k-1次两两合并，时间复杂度为O(k^2*n)

	方法2：
		将所有节点放入到一个vector中，然后排序，再将节点顺序相连即可
		时间复杂度：O(kn*logkn)

	方法3：
		 对k个链表进行分治，两两进行合并
		 第一轮：进行k/2次，每次2n，第二轮：进行k/4次，每次4n......
		 最后一次：进行k/(2^logk)，每次2^logk*n
		 时间复杂度：O(kn*logk)-------最佳
*/

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool cmp(const ListNode *a, const ListNode *b){
    return a->val < b->val; 	//从小到大的排序
}
//std::sort(迭代器， 迭代器， 比较函数）
//例如std::sort(node_vec.begin(), node_vec.end(), cmp)

class Solution {
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

    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        if(lists.size() == 0){
            return NULL;
        }
        if(lists.size() == 1){
            return lists[0];
        }
        if(lists.size() == 2){
            return mergeTwoLists(lists[0], lists[1]);
        }
        int mid = lists.size() / 2;

        std::vector<ListNode*> sub1_lists;
        std::vector<ListNode*> sub2_lists;
        for(int i = 0; i < mid; i++){
            sub1_lists.push_back(lists[i]);
        }
        for(int i = mid; i < lists.size(); i++){
            sub2_lists.push_back(lists[i]);
        }
        ListNode *l1 = mergeKLists(sub1_lists);
        ListNode *l2 = mergeKLists(sub2_lists);
        return mergeTwoLists(l1, l2);
    }
};

int main(){

}