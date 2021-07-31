//
// Created by eryo on 2021/7/31.
//

#include <stdio.h>
#include <vector>
#include <queue>

/*
	侧面观察二叉树-199

	给定一个二叉树，假设从该二叉树的右侧观察他，
	将观察到的结点按照从上到下的顺序输出

	方法：
		将结点及其层数绑定为pair然后压入队列
*/

struct TreeNode{	//树结点的数据结构
    int val;		//单链表仍使用该数据结构，即left = NULL, right = next
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution{
public:
    std::vector<int> rightSideView(TreeNode* root){
        std::vector<int> view;	//按层遍历的最后一个结点
        std::queue<std::pair<TreeNode*, int> > Q;
        if(root){
            Q.push(std::make_pair(root, 0));
        }
        while(!Q.empty()){
            TreeNode* node = Q.front().first;
            int depth = Q.front().second;
            Q.pop();
            if(depth == view.size()){
                view.push_back(node->val);
            }else{
                view[depth] = node->val;
            }
            if(node->left){
                Q.push(std::make_pair(node->left, depth + 1));
            }
            if(node->right){
                Q.push(std::make_pair(node->right, depth + 1));
            }
        }
        return view;
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
    std::vector<int> result = s.rightSideView(&a);
    for(int i = 0; i < result.size(); i++){
        printf("[%d]\n", result[i]);
    }
    return 0;
}