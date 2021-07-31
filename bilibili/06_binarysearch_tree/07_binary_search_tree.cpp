//
// Created by eryo on 2021/7/31.
//

#include <stdio.h>
#include <vector>

/*
	预备知识-二叉查找树查找数值

	由于二叉排序树按照中序遍历是从大到小的故又名二叉排序树
	根节点的左子树所有结点的值均小于或等于根节点的值
	根节点的右子树所有结点的值均大于或等于根节点的值
	左右自述也均为二叉排序树
	等于的情况只能出现在左子树右子树中的某一侧

	查找数值value是否在二叉查找树中出现
*/

//二叉树的数据结构
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
};

//向二叉排序树中插入结点
void BST_insert(TreeNode* node, TreeNode* insert_node){
    if(insert_node->val < node->val){
        if(node->left){
            BST_insert(node->left, insert_node);
        }else{
            node->left = insert_node;
        }
    }else{
        if(node->right){
            BST_insert(node->right, insert_node);
        }else{
            node->right = insert_node;
        }
    }
}

//在二叉查找树中搜索
bool BST_search(TreeNode *node, int value){
    if(value == node->val){		//找到了
        return true;
    }else if(value < node->val){	//在左子树中找
        if(node->left){
            return BST_search(node->left, value);
        }else{
            return false;
        }
    }else if(value > node->val){	//在右子树中找
        if(node->right){
            return BST_search(node->right, value);
        }else{
            return false;
        }
    }
}

//前序遍历
void preorder_print(TreeNode* node, int layer){
    if(!node){
        return;
    }
    for(int i = 0; i < layer; i++){
        printf("-----");
    }
    printf("[%d]\n", node->val);
    preorder_print(node->left, layer + 1);
    preorder_print(node->right, layer + 1);
}

//中序遍历
void inorder_print(TreeNode* node, int layer){
    if(!node){
        return;
    }
    inorder_print(node->left, layer + 1);
    for(int i = 0; i < layer; i++){
        printf("-----");
    }
    printf("[%d]\n", node->val);
    inorder_print(node->right, layer + 1);
}

int main(){
    TreeNode root(8);	//以8为根的二叉树
    std::vector<TreeNode*> node_vec;
    int test[] = {3, 10, 1, 6, 15};
    for(int i = 0; i < 5; i++){
        node_vec.push_back(new TreeNode(test[i]));
    }
    for(int i = 0; i < node_vec.size(); i++){
        BST_insert(&root, node_vec[i]);
    }

    for(int i = 0; i < 20; i++){
        if(BST_search(&root, i)){
            printf("%d is in the BST.\n", i);
        }else{
            printf("%d is not in the BST.\n", i);
        }
    }

    for(int i = 0; i < node_vec.size(); i++){
        delete node_vec[i];
    }
    return 0;
}