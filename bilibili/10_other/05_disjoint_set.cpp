//
// Created by eryo on 2021/7/31.
//

#include <stdio.h>
#include <vector>

/*
	预备知识-并查集-数组实现

	并查集(Union Find)，又称不相交集合(Disjoint Set)，他应用于N个元素的集合求
	并与查询问题，在该应用场景中，我们通常是开始时让每个元素构成一个单元素的
	集合，然后按一定顺序将属于同一组的元素所在的集合合并，其间要反复查找一个
	元素在哪个集合中。虽然该问题并不复杂，但面对极大的数据量时，普通的数据结
	构往往无法解决，而并查集可以解决。

	复杂度-O(n)
*/

class DisjointSet{
public:
    DisjointSet(int n){
        for(int i = 0; i < n; i++){
            _id.push_back(i);
        }
    }
    int find(int p){
        return _id[p];
    }
    void union_(int p, int q){
        int pid = find(p);
        int qid = find(q);
        if(pid == qid){
            return;
        }
        for(int i = 0; i < _id.size(); i++){
            if(_id[i] == pid){
                _id[i] = qid;
            }
        }
    }
private:
    std::vector<int> _id;
};