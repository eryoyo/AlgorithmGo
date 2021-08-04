//给定一个单链表，随机选择链表的一个节点，并返回相应的节点值。保证每个节点被选的概率一样。 
//
// 进阶: 
//如果链表十分大且长度未知，如何解决这个问题？你能否使用常数级空间复杂度实现？ 
//
// 示例: 
//
// 
//// 初始化一个单链表 [1,2,3].
//ListNode head = new ListNode(1);
//head.next = new ListNode(2);
//head.next.next = new ListNode(3);
//Solution solution = new Solution(head);
//
//// getRandom()方法应随机返回1,2,3中的一个，保证每个元素被返回的概率相等。
//solution.getRandom();
// 
// Related Topics 水塘抽样 链表 数学 随机化 
// 👍 144 👎 0

/*
 * 题解
不同于数组，在未遍历完链表前，我们无法知道链表的总长度。这里我们就可以使用水库采
样：遍历一次链表，在遍历到第 m 个节点时，有 1
m 的概率选择这个节点覆盖掉之前的节点选择。
我们提供一个简单的，对于水库算法随机性的证明。对于长度为 n 的链表的第 m 个节点，最
后被采样的充要条件是它被选择，且之后的节点都没有被选择。因此每个点都有均等的概率被选择。
 */

#include <cstdlib>

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
//    int val;
//    ListNode *next;
//    ListNode() : val(0), next(nullptr) {}
//    ListNode(int x) : val(x), next(nullptr) {}
//    ListNode(int x, ListNode *next) : val(x), next(next) {}
//};

class Solution {
    ListNode* head;
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) : head(head){

    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int ans = head->val;
        ListNode* node = head->next;
        int i = 2;
        while(node){
            if((rand() % i) == 0){
                ans = node->val;
            }
            ++i;
            node = node->next;
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
//leetcode submit region end(Prohibit modification and deletion)
