//
// Created by eryo on 2021/8/13.
//

//全排列

#include <cstdio>

const int maxn = 11;
//p为当前排列，hashTable记录整数x是否已经在p中
int n, p[maxn], hashTable[maxn] = {false};
//当前处理排列的第index位
void generate(int index){
    if(index == n + 1){
        for(int i = 1; i <= n; ++i){
            printf("%d", p[i]);
        }
        printf("\n");
        return;
    }
    for(int x = 1; x <= n; ++x){    //枚举1~n，试图将x填入p[index]
        if(hashTable[x] == false){
            p[index] = x;
            hashTable[x] = true;    //将x记为已存在
            generate(index + 1);    //处理排列的第index+1位
            hashTable[x] = false;   //还原状态
        }
    }
}

int main(){
    n = 3;
    generate(1);
    return 0;
}