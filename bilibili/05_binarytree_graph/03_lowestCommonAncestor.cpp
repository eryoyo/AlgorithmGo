//
// Created by eryo on 2021/7/31.
//

#include <stdio.h>
#include <vector>

/*
	最近的公共祖先-236

	已知二叉树，求二叉树中给定的两个结点的最近公共祖先

	方法：
		1.两个结点的公共祖先一定在从根节点到这两个结点的路径上
		2.即求两路径上最后一个相同的结点

	05 78:19 2/5
*/

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

//求根节点到某结点路径
void preorder(	TreeNode* node,		//正在遍历的结点
                  TreeNode* search,	//待搜索结点
                  std::vector<TreeNode*> &path,	//遍历时的结点路径栈
                  std::vector<TreeNode*> &result,	//最终的路径结果
                  int &finish){
    if(!node || finish){
        return;
    }
    path.push_back(node);
    if(node == search){
        finish = 0;
        result = path;
    }
    preorder(node->left, search, path, result, finish);	//深度遍历左子树
    preorder(node->right, search, path, result, finish);	//深度遍历右子树
    path.pop_back();
}

class Solution{
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
        std::vector<TreeNode*> path;	//声明遍历时用的临时栈
        std::vector<TreeNode*> node_p_path;	//存储p结点路径
        std::vector<TreeNode*> node_q_path;	//存储q结点路径
        int finish = 0;		 //记录是否完成搜索的变量
        preorder(root, p, path, node_p_path, finish);
        path.clear();
        finish = 0;
        preorder(root, q, path, node_p_path, finish);
        int path_len = 0;		//较短路径的长度
        if(node_p_path.size() > node_q_path.size()){
            path_len = node_q_path.size();
        }else{
            path_len = node_p_path.size();
        }
        TreeNode* result = 0;
        for(int i = 0; i < path_len; i++){
            if(node_p_path[i] == node_q_path[i]){
                result = node_p_path[i];
            }
        }
        return result;
    }
};

int main(){

}