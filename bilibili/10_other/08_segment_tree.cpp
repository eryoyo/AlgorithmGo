//
// Created by eryo on 2021/7/31.
//

#include <stdio.h>
#include <vector>

/*
	预备知识-线段树

	线段树是一种平衡二叉搜索树（完全二叉树，除最后一行以外都是满的），它将
	一个线段区间划分为一些单元区间。对于线段树中的每一个非叶子结点[a,b],它
	的左儿子表示的区间为[a, (a+b)/2],右儿子表示的区间为[(a+b)/2+1,b] ,最后
	的叶子结点数目为N，与数组下标对应。线段树的一半包括建立、查询、插入、更
	新操作，建立规模为N的时间复杂度是O(NlohN),其他操作时间复杂度为O(logN)。
*/

//value是一个数组，储存着结点所代表区间的数字的和，
//例如根节点就是整个数组的和,也就是value[0]
//编号按照第一行0，第二行1，2，第三行3，4，5，6，以此类推，当结点为空时
//也要对该空结点进行编号，
void build_segment_tree(std::vector<int>& value, //和的数组
                        std::vector<int> &nums,	//原始数组
                        int pos, int left, int right){
    if(left == right){
        value[pos] = nums[left];
        return;
    }
    int mid = (left + right) / 2;
    build_segment_tree(value, nums, 2 * pos + 1, left, mid);
    build_segment_tree(value, nums, 2 * pos + 2, mid + 1, right);
    value[pos] = value[2 * pos + 1] + value[2 * pos + 2];
}

void print_segment_tree(std::vector<int> &value, int pos, int left, int right, int layer){
    for(int i = 0; i < layer; i++){
        printf("---");
    }
    printf("[%d %d][%d] : %d\n", left, right, pos, value[pos]);
    if(left == right){
        return;
    }
    int mid = (left + right) / 2;
    print_segment_tree(value, pos * 2 + 1, left, mid, layer + 1);
    print_segment_tree(value, pos * 2 + 2, mid + 1, right, layer + 1);
}

//线段树的求和
//如果区间[left, right]与[qleft, qright]无交集，返回0
//如果区间[left, right]被[qleft, qright]覆盖，返回该区间的值
//返回左子树的访问值+右子树的访问值
int sum_range_segment_tree(std::vector<int>& value,
                           int pos, int left, int right, int qleft, int qright){
    if(left > qright || right < qleft){
        return 0;
    }
    if(left >= qleft && right <= qright){
        return value[pos];
    }
    int mid = (left + right) / 2;
    return sum_range_segment_tree(value, pos * 2 + 1, left, mid, qleft, qright)
           + sum_range_segment_tree(value, pos * 2 + 2, mid + 1, right, qleft, qright);
}

//线段树的更新
//如果更新的是叶节点，且为待更新数组的下标index，更新该结点值
//计算中心点mid
//比较mid和index，递归左子树或右子树
void update_segment_tree(std::vector<int> &value,
                         int pos, int left, int right, int index, int new_value){
    if(left == right && index == left){
        value[pos] = new_value;
        return;
    }
    int mid = (left + right) / 2;
    if(index <= mid){
        update_segment_tree(value, pos * 2 + 1, left, mid, index, new_value);
    }else{
        update_segment_tree(value, pos * 2 + 2, mid + 1, right, index, new_value);
    }
    value[pos] = value[pos * 2 + 1] + value[pos * 2 + 2];
}

int main(){
    std::vector<int> value(15, 0);
    std::vector<int> nums;
    for(int i = 0; i < 6; i++){
        nums.push_back(i);
    }
    build_segment_tree(value, nums, 0, 0, 5);
    print_segment_tree(value, 0, 0, 5, 0);
    printf("[2, 5] : %d\n", sum_range_segment_tree(value, 0, 0, 5, 2, 5));
    return 0;
}