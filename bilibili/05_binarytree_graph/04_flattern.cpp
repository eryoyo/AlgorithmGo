//
// Created by eryo on 2021/7/31.
//

#include <stdio.h>
#include <vector>

/*
	二叉树转链表-114

	给一个二叉树，将该二叉树转为单链表，单链表中结点顺序为二叉树前序遍历顺序

	方法I：
		前序遍历二叉树，将结点push到vector里面，然后依次衔接各个结点
*/

struct TreeNode{	//树结点的数据结构
    int val;		//单链表仍使用该数据结构，即left = NULL, right = next
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution{
public:
    void flatten(TreeNode *root){
        std::vector<TreeNode*> node_vec;
        preorder(root, node_vec);
        for(int i = 0; i < node_vec.size() - 1; i++){
            node_vec[i]->left = nullptr;
            node_vec[i]->right = node_vec[i + 1];
        }
    }

private:
    void preorder(TreeNode* node, std::vector<TreeNode*>& node_vec) {
        if(!node){
            return;
        }
        node_vec.push_back(node);
        preorder(node->left, node_vec);
        preorder(node->right, node_vec);
    }
};

int main(){

}