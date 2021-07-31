//
// Created by eryo on 2021/7/31.
//

#include <stdio.h>
#include <string>
#include <vector>

/*
	二叉查找树编码与解码-449

	给定一个二叉查找树，实现对改二叉查找树编码与解码功能，编码即将该
	二叉查找树转为字符串，解码即将字符串转为二叉查找树，不限制使用何种
	编码算法，只需保证当对二叉查找树调用编码功能后可再调用解码功能复原

	方法：
		前序遍历二叉树，将结点中的数据转为字符串，并用特殊符号分隔
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

//整型数字转字符串
void change_int_to_string(int val, std::string &str_val){
    std::string temp;
    while(val){
        temp += val % 10 + '0';		//最低位转换为字符添加到尾部
        val = val / 10;
    }
    for(int i = temp.length() - 1; i >= 0; i--){	//逆序
        str_val += temp[i];
    }
    str_val += '#';
}

void BST_preorder(TreeNode *node, std::string &data){
    if(!node){
        return;
    }
    std::string str_val;
    change_int_to_string(node->val, str_val);
    data += str_val;
    BST_preorder(node->left, data);
    BST_preorder(node->right, data);
}

class Codec{
public:
    std::string serialize(TreeNode* root){
        std::string data;
        BST_preorder(root, data);
        return data;
    }

    TreeNode* deserialize(std::string data){
        if(data.length() == 0){
            return NULL;
        }
        std::vector<TreeNode*> node_vec;
        int val = 0;
        for(int i = 0; i < data.length(); i++){
            if(data[i] == '#'){
                node_vec.push_back(new TreeNode(val));
                val = 0;
            }else{
                val = val * 10 + data[i] - '0';
            }
        }
        for(int i = 1; i < node_vec.size(); i++){
            BST_insert(node_vec[0], node_vec[i]);
        }
        return node_vec[0];
    }
};

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
    printf("编码前：\n");
    preorder_print(&root, 0);

    printf("编码后：\n");
    Codec s;
    std::string data = s.serialize(&root).c_str();
    printf("%s\n", data.c_str());

    printf("解码后：\n");
    TreeNode* node = s.deserialize(data);
    preorder_print(node, 0);

    for(int i = 0; i < node_vec.size(); i++){
        delete node_vec[i];
    }
    return 0;
}