//
// Created by eryo on 2021/7/31.
//

#include <stdio.h>
#include <queue>

/*
	预备知识-二叉树层次遍历，宽度优先遍历

	方法：
		使用队列对二叉树结点进行储存，先进入队列的结点先扩展其左右结点
*/

struct TreeNode{	//树结点的数据结构
    int val;		//单链表仍使用该数据结构，即left = NULL, right = next
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution{
public:
    void BFS_print(TreeNode* root){
        std::queue<TreeNode*> Q;
        Q.push(root);
        while(!Q.empty()){
            TreeNode *node = Q.front();
            Q.pop();
            printf("[%d]\n", node->val);
            if(node->left){
                Q.push(node->left);
            }
            if(node->right){
                Q.push(node->right);
            }
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
    s.BFS_print(&a);
    return 0;
}