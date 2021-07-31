//
// Created by eryo on 2021/7/31.
//

#include <stdio.h>
#include <vector>

#define TRIE_MAX_CHAR_NUM 26

/*
	预备知识-trie树

	字典树或前缀树，是一种有序的、用于统计排序和储存字符串的数据结构，
	它与二叉查找树不同，关键字不是直接保存在结点中，而是由结点在树中的
	位置决定
	一个结点的所有子孙都有相同的前缀，而根节点对应空字符串，一般情况下，
	不是所有的结点都有对应的值（不是所有的结点都是某一个储存字符串的最
	后一个字母），只有叶子结点和部分内部节点所对应的键才有相关的值
	trie树的最大优点就是利用字符串的公共前缀来减少存储空间与查询时间，从而
	最大限度的减少无谓的字符串比较，是非常高效的字符串查找数据结构
*/

struct TrieNode{
    TrieNode* child[TRIE_MAX_CHAR_NUM];
    bool is_end;	//标记是否有字符串以该节点为结尾
    TrieNode() : is_end(false){
        for(int i = 0; i < TRIE_MAX_CHAR_NUM; i++){
            child[i] = 0;
        }
    }
};

void preorder_trie(TrieNode* node, int layer){
    for(int i = 0; i < TRIE_MAX_CHAR_NUM; i++){
        if(node->child[i]){
            for(int j = 0; j < layer; j++){
                printf("---");
            }
            printf("%c", 'a' + i);
            if(node->child[i]->is_end){
                printf("(end)");
            }
            printf("\n");
            preorder_trie(node->child[i], layer + 1);
        }
    }
}

int main(){
    TrieNode root;
    TrieNode n1;
    TrieNode n2;
    TrieNode n3;
    root.child['a' - 'a'] = &n1;
    root.child['b' - 'a'] = &n2;
    root.child['c' - 'a'] = &n3;
    n2.is_end = true;

    TrieNode n4;
    TrieNode n5;
    TrieNode n6;
    n1.child['b' - 'a'] = &n4;
    n2.child['c' - 'a'] = &n5;
    n3.child['f' - 'a'] = &n6;

    TrieNode n7;
    TrieNode n8;
    TrieNode n9;
    TrieNode n10;
    n4.child['c' - 'a'] = &n7;
    n4.child['d' - 'a'] = &n8;
    n5.child['d' - 'a'] = &n9;
    n6.child['g' - 'a'] = &n10;
    n7.is_end = true;
    n8.is_end = true;
    n9.is_end = true;
    n10.is_end = true;

    TrieNode n11;
    n7.child['d' - 'a'] = &n11;
    n11.is_end = true;

    preorder_trie(&root, 0);

    return 0;
}