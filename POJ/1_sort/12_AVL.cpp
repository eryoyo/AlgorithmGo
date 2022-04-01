//
// Created by eryo on 2021/9/4.
//

//page338-pat

#include<algorithm>

using namespace std;

struct node{
    int v;          //结点权值
    int height;     //当前子树的高度
    node* lchild;
    node* rchild;
};

//生成一个新结点，v为结点权值
node* newNode(int v){
    node* Node = new node;
    Node->v = v;
    Node->height = 1;
    Node->lchild = nullptr;
    Node->rchild = nullptr;
    return Node;
}

//获取以root为根节点的子树的当前height
int getHeight(node* root){
    if(root == nullptr){
        return 0;
    }
    return root->height;
}

//计算结点root的平衡因子
int getBalanceFactor(node* root){
    return getHeight(root->lchild) - getHeight(root->rchild);
}

//更新结点root的height
void updateHeight(node* root){
    root->height = max(getHeight(root->lchild), getHeight(root->rchild)) + 1;
}

//查找书中数据域为x的结点
void search(node* root, int x){
    if(root == nullptr){
        printf("search failed\n");
        return;
    }
    if(x == root->v){
        printf("%d\n", root->v);
    }else if(x < root->v){
        search(root->lchild, x);
    }else{
        search(root->rchild, x);
    }
}

//左旋-逆时针
void L(node* &root){
    node* temp = root->rchild;
    root->rchild = temp->lchild;
    temp->lchild = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}

//右旋-顺时针
void R(node* &root){
    node* temp = root->lchild;
    root->lchild = temp->rchild;
    temp->rchild = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}

//插入新的结点
void insert(node* &root, int v){
    if(root == nullptr){
        root = newNode(v);
        return;
    }
    if(v < root->v){
        insert(root->lchild, v);
        updateHeight(root);
        if(getBalanceFactor(root) == 2){
            if(getBalanceFactor(root->lchild) == 1){
                //LL
                R(root);
            }else if(getBalanceFactor(root->lchild) == -1){
                //LR
                L(root->lchild);
                R(root);
            }
        }
    }else{
        insert(root->rchild, v);
        updateHeight(root);
        if(getBalanceFactor(root) == -2){
            if(getBalanceFactor(root->rchild) == -1){
                //RR
                L(root);
            }else if(getBalanceFactor(root->rchild) == 1){
                //RL
                R(root->rchild);
                L(root);
            }
        }
    }
}

node* Create(int data[], int n){
    node* root = nullptr;
    for(int i = 0; i < n; i++){
        insert(root, data[i]);
    }
    return root;
}