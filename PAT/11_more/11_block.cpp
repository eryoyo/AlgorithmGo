//
// Created by eryo on 2021/9/6.
//

//求解一个非整数序列中的第k大的数
/*
 假如在查询的过程中还在不断的对序列中的元素进行增删改，称为在线查询
 假如为在线查询，使用暴力法解决，那么在每次增加或者删除元素的时候将有O(n)的复杂度
 */

//分块思想
/*
 设置一个数组table[100001],其中的table[x]表示整数x的数目
 将这些数分为sqrt(100001)取上界块，每块有sqrt(100001)取下界个元素
 设置一个block数组，大小为块数，每个元素代表该块有的元素个数
 增加/删除元素x：先找到该元素的块号，然后将block数组和table数组的相应位置加减1
 查找第k个元素：先找到对应的快好，然后找到对应的元素，复杂度变为O(sqrt(n))
 */