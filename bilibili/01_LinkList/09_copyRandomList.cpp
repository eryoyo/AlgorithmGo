//
// Created by eryo on 2021/7/31.
//

#include <stdio.h>
#include <map>
#include <vector>

/*
	复制带随机指针的链表-138

	给你一个长度为 n 的链表，每个节点包含一个额外增加的随机指针 random ，
	该指针可以指向链表中的任何节点或空节点。

	构造这个链表的深拷贝。拷贝应该正好由 n个全新节点组成，
	其中每个新节点的值都设为其对应的原节点的值。
	新节点的 next 指针和 random 指针也都应指向复制链表中的新节点，
	并使原链表和复制链表中的这些指针能够表示相同的链表状态。
	复制链表中的指针都不应指向原链表中的节点 。

	深度拷贝：构造一个完全新的链表，即使将原链表毁坏，新链表可独立使用

	方法：
		用两个map
		一个map是原链表 结点指针 到 结点位置 的映射
		另一个是新链表  结点位置 到 结点指针 的映射

*/


struct RandomListNode{
    int label;			//带有随机指针的链表结点
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL){}
};

class Solution{
public:
    RandomListNode *copyRandomList(RandomListNode *head){
        std::map<RandomListNode*, int> node_map;		//地址到结点位置的map
        std::vector<RandomListNode*> node_vec;			//使用vector根据结点位置访问结点地址
        RandomListNode *ptr = head;
        int i = 0;
        while(ptr){
            node_vec.push_back(new RandomListNode(ptr->label));	//将新链表结点压入node_vec，生成新链表结点位置到地址的map
            node_map[ptr] = i;			//原链表 结点指针 到 结点位置 的映射
            ptr = ptr->next;
            ++i;
        }
        node_vec.push_back(0);

        ptr = head;
        i = 0;
        while(ptr){
            node_vec[i]->next = node_vec[i+1];		//连接新链表的next指针
            if(ptr->random){						//连接新链表的random指针
                int id = node_map[ptr->random];
                node_vec[i]->random = node_vec[id];
            }
            ptr = ptr->next;
            i++;
        }
        return node_vec[0];
    }
};

int main(){
    std::map<RandomListNode*, int> node_map;
    RandomListNode a(5);
    RandomListNode b(3);
    RandomListNode c(6);
    a.next = &b;
    b.next = &c;
    a.random = &c;
    b.random = &a;
    c.random = &c;
    node_map[&a] = 1;
    node_map[&b] = 2;
    node_map[&c] = 3;
    printf("a.random id = %d\n", node_map[a.random]);
    printf("b.random id = %d\n", node_map[b.random]);
    printf("c.random id = %d\n", node_map[c.random]);
    return 0;
}