//
// Created by eryo on 2021/8/13.
//

#include <cstdio>
#include <cmath>

int count = 0;
const int maxn = 11;
//p为当前排列，hashTable记录整数x是否已经在p中
int n, p[maxn], hashTable[maxn] = {false};
//当前处理排列的第index位
void generate(int index){
    if(index == n + 1){
        ++count;
        return;
    }
    for(int x = 1; x <= n; ++x){
        if(hashTable[x] == false){
            bool flag = true;
            for(int pre = 1; pre < index; ++pre){
                if(abs(index - pre) == abs(x - p[pre])){
                    flag = false;
                    break;
                }
            }
            if(flag){
                p[index] = x;
                hashTable[x] = true;
                generate(index + 1);
                hashTable[x] = false;
            }
        }
    }
}

int main(){
    n = 8;
    generate(1);
    printf("%d", count);
    return 0;
}