//给定一棵树的前序遍历 preorder 与中序遍历 inorder。请构造二叉树并返回其根节点。 
//
// 
//
// 示例 1: 
//
// 
//Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
//Output: [3,9,20,null,null,15,7]
// 
//
// 示例 2: 
//
// 
//Input: preorder = [-1], inorder = [-1]
//Output: [-1]
// 
//
// 
//
// 提示: 
//
// 
// 1 <= preorder.length <= 3000 
// inorder.length == preorder.length 
// -3000 <= preorder[i], inorder[i] <= 3000 
// preorder 和 inorder 均无重复元素 
// inorder 均出现在 preorder 
// preorder 保证为二叉树的前序遍历序列 
// inorder 保证为二叉树的中序遍历序列 
// 
// Related Topics 树 数组 哈希表 分治 二叉树 
// 👍 1146 👎 0

/*
 * 题解
我们通过本题的样例讲解一下本题的思路。前序遍历的第一个节点是 4，意味着 4 是根节点。
我们在中序遍历结果里找到 4 这个节点，根据中序遍历的性质可以得出，4 在中序遍历数组位置
的左子数组为左子树，节点数为 1，对应的是前序排列数组里 4 之后的 1 个数字（9）；4 在中序
遍历数组位置的右子数组为右子树，节点数为 3，对应的是前序排列数组里最后的 3 个数字。有
了这些信息，我们就可以对左子树和右子树进行递归复原了。为了方便查找数字的位置，我们可
以用哈希表预处理中序遍历的结果。
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty()) {
            return nullptr;
        }
        unordered_map<int, int> hash;
        for (int i = 0; i < preorder.size(); ++i) {
            hash[inorder[i]] = i;
        }
        return buildTreeHelper(hash, preorder, 0, preorder.size() - 1, 0);
    }

    // 辅函数
    TreeNode* buildTreeHelper(unordered_map<int, int> & hash, vector<int>& preorder
            , int s0, int e0, int s1) {
        if (s0 > e0) {
            return nullptr;
        }
        int mid = preorder[s1], index = hash[mid], leftLen = index - s0;
        TreeNode* node = new TreeNode(mid);
        node->left = buildTreeHelper(hash, preorder, s0, index - 1, s1 + 1);
        node->right = buildTreeHelper(hash, preorder, index + 1, e0, s1 + 1 +
                                                                     leftLen);
        return node;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
