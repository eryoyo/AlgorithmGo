//
// Created by eryo on 2021/9/6.
//

//lowbit运算
/*
 lowbit(x) = x & (-x)

 整数在计算机中采用补码表示，求一个数的相反数的补码就是每位取反，末尾加1

 作用是取二进制数的最右边的1和其右边的0
 也可以理解为能整除x的最大的2的幂次
 */

//Binary Indexed Tree, BIT树状数组
/*
 sum数组：每一个元素储存着一个整数数组的前i个元素之和

 树状数组C：C[i]储存着该位及之前lowbit(i)个元素之和，树状数组的下标必须从1开始
 */

//应用-一个正整数序列中，求左边比他小的数的个数
/*
 变种：求左边比他大的数，求右边比他小/大的数
 */

#include<cstdio>
#include<cstring>

const int maxn = 100010;

#define lowbit(i) ((i) & (-i))

int c[maxn];    //树状数组

//update函数将第x个整数加上v
void update(int x, int v){
    for(int i = x; i < maxn; i += lowbit(i)){
        c[i] += v;
    }
}

//getSum函数返回前x个整数之和
int getSum(int x){
    int sum = 0;
    for(int i = x; i > 0; i -= lowbit(i)){
        sum += c[i];
    }
    return sum;
}

int main(){
    int n, x;
    scanf("%d", &n);
    memset(c, 0, sizeof(c));
    for(int i = 0; i < n; ++i){
        scanf("%d", &x);
        update(x, 1);
        printf("%d\n", getSum(x - 1));
    }
    return 0;
}