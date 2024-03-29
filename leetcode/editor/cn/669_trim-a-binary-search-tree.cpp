//给你二叉搜索树的根节点 root ，同时给定最小边界low 和最大边界 high。通过修剪二叉搜索树，使得所有节点的值在[low, high]中。修剪树不应
//该改变保留在树中的元素的相对结构（即，如果没有被移除，原有的父代子代关系都应当保留）。 可以证明，存在唯一的答案。 
//
// 所以结果应当返回修剪好的二叉搜索树的新的根节点。注意，根节点可能会根据给定的边界发生改变。 
//
// 
//
// 示例 1： 
//
// 
//输入：root = [1,0,2], low = 1, high = 2
//输出：[1,null,2]
// 
//
// 示例 2： 
//
// 
//输入：root = [3,0,4,null,2,null,null,1], low = 1, high = 3
//输出：[3,2,null,1]
// 
//
// 示例 3： 
//
// 
//输入：root = [1], low = 1, high = 2
//输出：[1]
// 
//
// 示例 4： 
//
// 
//输入：root = [1,null,2], low = 1, high = 3
//输出：[1,null,2]
// 
//
// 示例 5： 
//
// 
//输入：root = [1,null,2], low = 2, high = 4
//输出：[2]
// 
//
// 
//
// 提示： 
//
// 
// 树中节点数在范围 [1, 104] 内 
// 0 <= Node.val <= 104 
// 树中每个节点的值都是唯一的 
// 题目数据保证输入是一棵有效的二叉搜索树 
// 0 <= low <= high <= 104 
// 
// Related Topics 树 深度优先搜索 二叉搜索树 二叉树 
// 👍 408 👎 0

/*
 * 题解
利用二叉查找树的大小关系，我们可以很容易地利用递归进行树的处理。
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
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if (!root) {
            return root;
        }
        if (root->val > R) {
            return trimBST(root->left, L, R);
        }
        if (root->val < L) {
            return trimBST(root->right, L, R);
        }
        root->left = trimBST(root->left, L, R);
        root->right = trimBST(root->right, L, R);
        return root;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
