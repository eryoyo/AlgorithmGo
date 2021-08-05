//给出二叉树的根节点 root，树上每个节点都有一个不同的值。 
//
// 如果节点值在 to_delete 中出现，我们就把该节点从树上删去，最后得到一个森林（一些不相交的树构成的集合）。 
//
// 返回森林中的每棵树。你可以按任意顺序组织答案。 
//
// 
//
// 示例： 
//
// 
//
// 输入：root = [1,2,3,4,5,6,7], to_delete = [3,5]
//输出：[[1,2,null,4],[6],[7]]
// 
//
// 
//
// 提示： 
//
// 
// 树中的节点数最大为 1000。 
// 每个节点都有一个介于 1 到 1000 之间的值，且各不相同。 
// to_delete.length <= 1000 
// to_delete 包含一些从 1 到 1000、各不相同的值。 
// 
// Related Topics 树 深度优先搜索 二叉树 
// 👍 132 👎 0

/*
 * 题解
这道题最主要需要注意的细节是如果通过递归处理原树，以及需要在什么时候断开指针。同
时，为了便于寻找待删除节点，可以建立一个哈希表方便查找。笔者强烈建议读者在看完题解后，
自己写一遍本题，加深对于递归的理解和运用能力。
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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> forest;
        unordered_set<int> dict(to_delete.begin(), to_delete.end());
        root = helper(root, dict, forest);
        if (root) {
            forest.push_back(root);
        }
        return forest;
    }

    // 辅函数
    TreeNode* helper(TreeNode* root, unordered_set<int> & dict, vector<TreeNode*> &forest) {
        if (!root) {
            return root;
        }
        root->left = helper(root->left, dict, forest);
        root->right = helper(root->right, dict, forest);
        if (dict.count(root->val)) {
            if (root->left) {
                forest.push_back(root->left);
            }
            if (root->right) {
                forest.push_back(root->right);
            }
            root = NULL;
        }
        return root;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
