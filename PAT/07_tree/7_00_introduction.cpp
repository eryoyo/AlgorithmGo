//
// Created by eryo on 2021/9/4.
//
#include<bits/stdc++.h>
//树的一些概念
/*
 结点的度：结点的子树数目
 树的度：树中结点的度中最大的，也称为树的宽度
 结点的深度：根节点算作第一层
 结点的高度：最底层叶子结点算作第一层
 */

//二叉树的一些概念
/*
 满二叉树：每一层的结点数目都是该层所能包含的最大个数
 完全二叉树：出最底层以外，每一层的结点数目都是该层所能包含的最多的
 */
/*
 在插入结点的时候需要在传入参数根节点加上引用，因为新的结点可能会改变
 */

//二叉树的恢复
/*
 边界条件是当前序遍历序列的长度小于等于0的时候直接返回空节点
 根据先序遍历和中序遍历恢复
 根据后序遍历和中序遍历恢复
 根据层次遍历和中序遍历恢复
 其中后序遍历，先序遍历，层次遍历的作用都是提供根节点
 */

//二叉树的静态表示
/*
 代表二叉树结点的结构体中，代表左右子树不是指针而是int，代表结点在数组中的下标
 */

//树的静态表示
/*
 子节点个数不限且子节点之间没有先后顺序的树

 指针域是一个int型的数组，储存着子节点在数组中的下标，一般使用vector
 静态表示中需要特别注意newNode函数中的分配含义

 树的先根遍历：先遍历根节点再遍历子树
 树的层序遍历
 */

//二叉查找树-325-BST
/*
 删除结点：先找到结点的前驱或者后继，然后用前驱或者后继代替该节点
 最后删除前驱或者后继，
 前驱：比该节点小的最大结点-左孩子的不断找右孩子
 后继：比该节点大的最小结点-右孩子的不断找左孩子
 */

//镜像树-交换所有结点的左右子树
/*
 二叉查找树及其镜像树的前序遍历所得到的序列依次插入形成的二叉查找树是相同的

 镜像树和原树的遍历时的区别是左右子树的先后不同
 */

//平衡二叉树-高度保持logn级别-AVL树以提出者命名
/*
 平衡因子：对任意结点来说，其左右子树的高度之差绝对值不超过1
 */
/*
 结点的结构体中需要添加一个新的属性height，表示当前子树的高度
 一个新创建的结点的高度初始化为1
 */
/*
 左旋：逆时针转动，假设现在A的右子树的根节点为B，想要使得A变为B的右子树，
 那么需要将B的左子树变为A的右子树

 右旋：和左旋是逆过程
 */
/*
 插入操作：
    假如插入结点之后树失衡，只有在从根节点到该插入结点的路径上
    的结点才可能发生平衡因子变化，所以只要把最靠近插入结点的
    失衡结点调整到正常，路径上的所有结点都会平衡

 假设A结点是最靠近的失衡结点，那么该节点的平衡因子只有可能是2或-2
 此时的树形只有可能是LL(当A的左节点平衡因子为1)或LR(当A的左节点平衡因子为-1)型

 LL型：右旋
 LR型：先左旋转为LL型再右旋
 RR型：左旋
 RL型：先右旋转为RR型再左旋
 */

//哈夫曼树
/*
 叶子结点的带权路径长度：结点权值乘以路径长度
 树的带权路径长度：所有叶子结点的带权路径长度之和weighted path length of tree WPL

 */