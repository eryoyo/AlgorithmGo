//
// Created by eryo on 2021/7/31.
//

#include <stdio.h>

/*
	二叉树结构
*/

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
};

//先序遍历
void preorder_print(TreeNode *node, int layer){
    if(!node){		//正在遍历的结点，当前结点的层数
        return;
    }
    for(int i = 0; i < layer; i++){
        printf("-----");		//根据层数，打印出相应数量的-
    }
    printf("[%d]\n", node->val);			//在此时访问结点称为前序遍历
    preorder_print(node->left, layer + 1);	//遍历左子树，层数加一
    //此时访问结点称为中序遍历
    preorder_print(node->right, layer + 1);	//遍历右子树 ，层数加一
    //此时访问结点称为后序遍历
}

int main(){

}