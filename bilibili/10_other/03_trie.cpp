//
// Created by eryo on 2021/7/31.
//

#include <stdio.h>
#include <vector>

#define TRIE_MAX_CHAR_NUM 26

/*
	实现trie树-208-211
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

class TrieTree{
public:
    TrieTree(){		}

    ~TrieTree(){
        for(int i = 0; i < _node_vec.size(); i++){
            delete _node_vec[i];
        }
    }

    //将word插入至Trie
    void insert(const char* word){
        TrieNode *ptr = &_root;
        while(*word){
            int pos = *word - 'a';
            if(!ptr->child[pos]){
                ptr->child[pos] = new_node();
            }
            ptr = ptr->child[pos];
            word++;
        }
        ptr->is_end = true;
    }

    //搜索trie中是否存在word
    bool search(const char* word){
        TrieNode* ptr = &_root;
        while(*word){
            int pos = *word - 'a';
            if(!ptr->child[pos]){
                return false;
            }
            ptr = ptr->child[pos];
            word++;
        }
        return ptr->is_end;
    }

    //正则表达式模糊匹配搜索
    bool search_trie(TrieNode *node, const char *word){
        if(*word == '\0'){
            if(node->is_end = true){
                return true;
            }
            return false;
        }
        if(*word == '.'){
            for(int i = 0; i < 26; i++){
                if(node->child[i] && search_trie(node->child[i], word + 1)){
                    return true;
                }
            }
        }else{
            int pos = *word - 'a';
            if(node->child[pos] && search_trie(node->child[pos], word + 1)){
                return true;
            }
        }
        return false;
    }

    //确定trie中是否有前缀为prefix的单词
    bool startsWith(const char* prefix){
        TrieNode* ptr = &_root;
        while(*prefix){
            int pos = *prefix - 'a';
            if(!ptr->child[pos]){
                return false;
            }
            ptr = ptr->child[pos];
            prefix++;
        }
        return true;
    }

    TrieNode *root(){
        return &_root;
    }

private:
    TrieNode* new_node(){
        TrieNode *node = new TrieNode();
        _node_vec.push_back(node);
        return node;
    }
    std::vector<TrieNode*> _node_vec;
    TrieNode _root;
};