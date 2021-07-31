//
// Created by eryo on 2021/7/31.
//

#include <stdio.h>
#include <vector>

/*
	预备知识-并查集-森林实现

	并查集(Union Find)，又称不相交集合(Disjoint Set)，他应用于N个元素的集合求
	并与查询问题，在该应用场景中，我们通常是开始时让每个元素构成一个单元素的
	集合，然后按一定顺序将属于同一组的元素所在的集合合并，其间要反复查找一个
	元素在哪个集合中。虽然该问题并不复杂，但面对极大的数据量时，普通的数据结
	构往往无法解决，而并查集可以解决。

	使用森林存储集合之间的关系，属于同一集合的不同元素，都有一个相同的根节点，
	代表着这个集合。
	当进行查找某元素属于哪个集合时，即遍历该元素到根节点，返回根节点所代表的
	集合；在遍历过程中使用路径压缩的优化算法，使整体树的形状更加扁平，从而优化
	查询的时间复杂度。
	当进行合并时，即将两颗子树合为一棵树，将一颗子树的根节点指向1另一颗子树的
	根节点；在合并的时候可按子树的大小，将规模较小的子树合并到规模较大的子树上
	从而是规模更加平衡，从而优化未来查询的时间复杂度

	复杂度-O(n)
*/

class DisjointSet{
public:
    DisjointSet(int n){
        for(int i = 0; i < n; i++){
            _id.push_back(i);
            _size.push_back(1);
        }
        _count = n;
    }
    int find(int p){
        while(_id[p] != p){
            _id[p] = _id[_id[p]];	//路径压缩算法
            p = _id[p];
        }
        return p;
    }
    //将小树加到大树，使树更平衡
    void union_(int p, int q){
        int i = find(p);
        int j = find(q);
        if(i == j){
            return;
        }
        if(_size[i] < _size[j]){
            _id[i] = j;
            _size[j] += _size[i];
        }else{
            _id[j] = i;
            _size[i] += _size[j];
        }
        _count--;
    }
private:
    std::vector<int> _id;
    std::vector<int> _size;		//子树的规模
    int _count;		//朋友圈的数量
};