//给你一个链表数组，每个链表都已经按升序排列。 
//
// 请你将所有链表合并到一个升序链表中，返回合并后的链表。 
//
// 
//
// 示例 1： 
//
// 输入：lists = [[1,4,5],[1,3,4],[2,6]]
//输出：[1,1,2,3,4,4,5,6]
//解释：链表数组如下：
//[
//  1->4->5,
//  1->3->4,
//  2->6
//]
//将它们合并到一个有序链表中得到。
//1->1->2->3->4->4->5->6
// 
//
// 示例 2： 
//
// 输入：lists = []
//输出：[]
// 
//
// 示例 3： 
//
// 输入：lists = [[]]
//输出：[]
// 
//
// 
//
// 提示： 
//
// 
// k == lists.length 
// 0 <= k <= 10^4 
// 0 <= lists[i].length <= 500 
// -10^4 <= lists[i][j] <= 10^4 
// lists[i] 按 升序 排列 
// lists[i].length 的总和不超过 10^4 
// 
// Related Topics 链表 分治 堆（优先队列） 归并排序 
// 👍 1432 👎 0

/*
 *题解
本题可以有很多中解法，比如类似于归并排序进行两两合并。我们这里展示一个速度比较快
的方法，即把所有的链表存储在一个优先队列中，每次提取所有链表头部节点值最小的那个节
点，直到所有链表都被提取完为止。注意因为 Comp 函数默认是对最大堆进行比较并维持递增关
系，如果我们想要获取最小的节点值，则我们需要实现一个最小堆，因此比较函数应该维持递减
关系，所以 operator() 中返回时用大于号而不是等增关系时的小于号进行比较。
 */

#include<vector>
#include<queue>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

//struct ListNode {
//int val;
//    ListNode *next;
//    ListNode() : val(0), next(nullptr) {}
//    ListNode(int x) : val(x), next(nullptr) {}
//    ListNode(int x, ListNode *next) : val(x), next(next) {}
//};

struct Comp{
    bool operator()(ListNode* l1, ListNode* l2){
        return l1->val > l2->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()){
            return nullptr;
        }
        priority_queue<ListNode*, vector<ListNode*>, Comp> q;
        for(ListNode* list : lists){
            if(list){
                q.push(list);
            }
        }
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;
        while(!q.empty()){
            cur->next = q.top();
            q.pop();
            cur = cur->next;
            if(cur->next){
                q.push(cur->next);
            }
        }
        return dummy->next;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
