//
// Created by eryo on 2021/7/31.
//

#include <stdio.h>
#include <vector>

/*
	逆序数-315

	已知数组nums，求新数组count，count[i]表示在nums[i]右侧且比nums[i]
	小的元素个数

	方法：
		将原数组逆序后插入到二叉查找树中
*/

//二叉树的数据结构
struct BSTNode{
    int val;
    int count;		//二叉树中该节点左子树中结点个数
    BSTNode *left;
    BSTNode *right;
    BSTNode(int x) : val(x), count(0), left(nullptr), right(nullptr){}
};

//count_small二叉排序树中比insert_node值小的结点个数
void BST_insert(BSTNode* node, BSTNode* insert_node, int &count_small){
    if(insert_node->val <= node->val){		//!!!!!!!!!!
        node->count++;
        if(node->left){
            BST_insert(node->left, insert_node, count_small);
        }else{
            node->left = insert_node;
        }
    } else{
        count_small += node->count + 1;
        if(node->right){
            BST_insert(node->right, insert_node, count_small);
        }else{
            node->right = insert_node;
        }
    }
}

class Solution{
public:
    std::vector<int> countSmaller(std::vector<int>& nums){
        std::vector<int> result;	//最终逆序数数组
        std::vector<BSTNode*> node_vec;		//创建的二叉查找树结点池
        std::vector<int> count;
        for(int i = nums.size() - 1; i >= 0; i--){
            node_vec.push_back(new BSTNode(nums[i]));	//逆序插入
        }
        count.push_back(0);		//第一个结点的count_small = 0
        for(int i = 1; i < node_vec.size(); i++){
            int count_small = 0;
            BST_insert(node_vec[0], node_vec[i], count_small);
            count.push_back(count_small);
        }
        for(int i = node_vec.size() - 1; i >= 0; i--){
            delete node_vec[i];
            result.push_back(count[i]);	//将count数组逆序push到result里面
        }
        return result;
    }
};

int main(){
    int test[] = {5, -7, 9, 1, 3, 5, -2, 1};
    std::vector<int> nums;
    for(int i = 0; i < 8; i++){
        nums.push_back(test[i]);
    }
    Solution s;
    std::vector<int> result = s.countSmaller(nums);
    for(int i = 0; i < result.size(); i++){
        printf("[%d]", result[i]);
    }
    printf("\n");
    return 0;
}