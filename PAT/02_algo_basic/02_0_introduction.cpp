//
// Created by eryo on 2021/8/13.
//

//递归，就是自己不断调用自己，每层需要使用下一层返回的结果
//递归边界：返回最简单底层的结果
//递归式：减少数据规模并向下一层递归

//hash
//key是整数-直接定址法、平方取中法、除留余数法
//除留余数法会产生冲突，所以为了避免冲突，有以下方法
//线性探查法：加入对应的位置已经有值了，就加1，如果已经到了尾端就到表首继续
//平方探查法：+-1的平方，+-2的平方。。。
//链地址法：同一hash值串在链表后面

//字符串哈希,将字符串转换成int值即将一个26进制数转换成10进制数
//如果加上小写字母就是将52进制数转换成10进制数，如果再加上数字就是62进制数
#include<cstdio>

const int maxn = 100;
char S[maxn][5], temp[5];
int hashTable[26 * 26 * 26 + 10];
int hashFunc(char S[], int len){
    int id = 0;
    for(int i = 0; i < len; ++i){
        id = id * 26 + (S[i] - 'A');
    }
    return id;
}
int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; ++i){
        scanf("%s", S[i]);
        int id = hashFunc(S[i], 3);
        hashTable[id]++;
    }
    for(int i = 0; i < m; ++i){
        scanf("%s", temp);
        int id = hashFunc(temp, 3);
        printf("%d\n", hashTable);
    }
    return 0;
}

