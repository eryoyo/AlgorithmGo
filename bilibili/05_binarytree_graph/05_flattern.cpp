//
// Created by eryo on 2021/7/31.
//

#include <stdio.h>
#include <vector>

/*
	二叉树转链表-114

	给一个二叉树，将该二叉树转为单链表，单链表中结点顺序为二叉树前序遍历顺序

	方法II：


	05 126:36 3/5
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
        TreeNode *last = NULL;
        preorder(root, last);
    }

private:
    void preorder(TreeNode* node, TreeNode* &last) {
        if(!node){
            return;
        }
        if(!node->left && !node->right){		//叶节点的处理
            last = node;
            return;
        }
        TreeNode *left = node->left;	//备份左右指针
        TreeNode *right = node->right;
        TreeNode *left_last = NULL;		//左右子树最后一个结点
        TreeNode *right_last = NULL;
        if(left){						//如果有左子树，递归的将左子树转换为单链表
            preorder(left, left_last);
            node->left = NULL;
            node->right = left;
            last = left_last;
        }
        if(right){						//若有右子树，递归的将右子树转换为链表
            preorder(right, right_last);
            if(left_last){				//如果有左子树
                left_last->right = right;
            }
            last = right_last;
        }
    }
};

int main(){
    TreeNode a(1);
    TreeNode b(2);
    TreeNode c(5);
    TreeNode d(3);
    TreeNode e(4);
    TreeNode f(6);
    a.left = &b;
    a.right = &c;
    b.left = &d;
    b.right = &e;
    c.right = &f;
    Solution s;
    s.flatten(&a);
    TreeNode *head = &a;
    while(head){
        if(head->left){
            printf("ERROR\n");
        }
        printf("[%d]", head->val);
        head = head->right;
    }
    return 0;
}