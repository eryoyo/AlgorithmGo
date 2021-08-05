//给你二叉搜索树的根节点 root ，该树中的两个节点被错误地交换。请在不改变其结构的情况下，恢复这棵树。 
//
// 进阶：使用 O(n) 空间复杂度的解法很容易实现。你能想出一个只使用常数空间的解决方案吗？ 
//
// 
//
// 示例 1： 
//
// 
//输入：root = [1,3,null,null,2]
//输出：[3,1,null,null,2]
//解释：3 不能是 1 左孩子，因为 3 > 1 。交换 1 和 3 使二叉搜索树有效。
// 
//
// 示例 2： 
//
// 
//输入：root = [3,1,4,null,null,2]
//输出：[2,1,4,null,null,3]
//解释：2 不能在 3 的右子树中，因为 2 < 3 。交换 2 和 3 使二叉搜索树有效。 
//
// 
//
// 提示： 
//
// 
// 树上节点的数目在范围 [2, 1000] 内 
// -231 <= Node.val <= 231 - 1 
// 
// Related Topics 树 深度优先搜索 二叉搜索树 二叉树 
// 👍 522 👎 0

/*
 * 题解
我们可以使用中序遍历这个二叉查找树，同时设置一个 prev 指针，记录当前节点中序遍历
时的前节点。如果当前节点大于 prev 节点的值，说明需要调整次序。有一个技巧是如果遍历整个
序列过程中只出现了一次次序错误，说明就是这两个相邻节点需要被交换；如果出现了两次次序
错误，那就需要交换这两个节点。
 */

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode *mistake1 = nullptr, *mistake2 = nullptr, *prev = nullptr;
        inorder(root, mistake1, mistake2, prev);
        if (mistake1 && mistake2) {
            int temp = mistake1->val;
            mistake1->val = mistake2->val;
            mistake2->val = temp;
        }
    }

    // 辅函数
    void inorder(TreeNode* root, TreeNode*& mistake1, TreeNode*& mistake2, TreeNode
    *& prev) {
        if (!root) {
            return;
        }
        if (root->left) {
            inorder(root->left, mistake1, mistake2, prev);
        }
        if (prev && root->val < prev->val) {
            if (!mistake1) {
                mistake1 = prev;
                mistake2 = root;
            } else {
                mistake2 = root;
            }
            cout << mistake1->val;
            cout << mistake2->val;
        }
        prev = root;
        if (root->right) {
            inorder(root->right, mistake1, mistake2, prev);
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)
