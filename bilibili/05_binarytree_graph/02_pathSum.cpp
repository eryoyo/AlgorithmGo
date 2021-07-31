//
// Created by eryo on 2021/7/31.
//

#include <stdio.h>
#include <vector>

/*
	路径之和2-113

	给定一个二叉树与整数sum，找出所有从根节点到叶节点的路径，
	这些路径上的结点值累加和为sum

	方法：
		从根节点深度遍历二叉树，先序遍历是，将该节点值push到栈中（vector）实现
		使用path_value累加结点值，
		当遍历至叶节点时，检查path_value值是否为sum，若为sum，则将pathpush到result结果中
		在后续遍历时，将该节点从path栈中弹出，path_value减去结点值

	05 53.09 1/5
*/

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution{
public:
    std::vector<std::vector<int> > pathSum(TreeNode* root, int sum){
        std::vector<std::vector<int> > result;
        std::vector<int> path;		//路径栈
        int path_value = 0;			//路径值
        preorder(root, path_value, sum, path, result);
        return result;
    }

private:
    void preorder(TreeNode *node, int &path_value, int sum, std::vector<int> &path,
                  std::vector<std::vector<int> > result){
        if(!node){
            return;
        }
        path_value += node->val;
        path.push_back(node->val);

        if(!node->left && !node->right && path_value == sum){
            result.push_back(path);			//将path添加至结果数组
        }

        preorder(node->left, path_value, sum, path, result);
        preorder(node->right, path_value, sum, path, result);

        path_value -= node->val;
        path.pop_back();
    }

};

int main(){

}