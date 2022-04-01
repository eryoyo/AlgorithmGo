//
// Created by eryo on 2021/9/6.
//

/*
 最长回文字符串

 首先求出字符串的H数组，然后对字符串进行翻转求出翻转后字符串的H
 分回文串的长度是奇数和偶数判断
 奇数：
    枚举回文中心点i,二分子串额半径k,找到最大的使子串[i-k,i+k]
    是回文串的k,判断[i-k,i+k]是回文串等价于判断str的两个子串
    [i-k,i][i,i+k]是否是相反的串，这等价与判断字符串的[i-k,i]子串
    和翻转字符串的[len-1-(i+k),len-1-i]子串是否相同

 偶数时类似
 */

#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

typedef long long LL;

const LL MOD = 1000000007;
const LL P = 10000019;
const LL MAXN = 200010;
//powP[i]存放P^i%MOD, H1和H2分别存放str1和str2的hash值
LL powP[MAXN], H1[MAXN] = {0}, H2[MAXN] = {0};
//init函数初始化powP函数
void init(){
    powP[0] = 1;
    for(int i = 1; i <= MAXN; ++i){
        powP[i] = (powP[i - 1] * P) % MOD;
    }
}
//calH函数计算字符串str的hash值
//H[i]表示前i位的hash值，最后一位的H表示整个字符串的hash值
void calH(LL H[], string &str){
    H[0] = str[0];
    for(int i = 1; i < str.length(); ++i){
        H[i] = (H[i - 1] * P + str[i]) % MOD;
    }
}
//calSingleSubH计算H[i...j]
int calSingleSubH(LL H[], int i, int j){
    if(i == 0){
        return H[j];
    }
    return ((H[j] - H[i - 1] * powP[j - i + 1]) % MOD + MOD) % MOD;
}
//对称点为i,字符串长len,在[l,r]里二分回文半径
//寻找最后一个满足条件hashL==hashR的回文半径
//等价于寻找第一个满足条件hashL != hashR的回文半径，然后减1
//isEven当求奇回文时为0，偶回文时为1
int binarySearch(int l, int r, int len, int i, int isEven){
    while(l < r){
        int mid = (l + r) / 2;
        //左半子串hash值H1[H1L...H1R],右半子串hash值H2[H2L...H2R]
        int H1L = i - mid + isEven;
        int H1R = i;
        int H2L = len - 1 - (i + mid);
        int H2R = len - 1 - (i + isEven);
        int hashL = calSingleSubH(H1, H1L, H1R);
        int hashR = calSingleSubH(H2, H2L, H2R);
        if(hashL != hashR){
            r = mid;
        }else{
            l = mid + 1;
        }
        return l - 1;
    }
}

int main(){
    init();
    string str;
    getline(cin, str);
    calH(H1, str);
    reverse(str.begin(), str.end());
    calH(H2, str);
    int ans = 0;
    //奇回文
    for(int i = 0; i < str.length(); ++i){
        int maxLen = min(i, (int)str.length() - 1 - i) + 1;
        int k = binarySearch(0, maxLen, str.length(), i, 0);
        ans = max(ans, k * 2 + 1);
    }
    //偶回文
    for(int i = 0; i < str.length(); ++i){
        int maxLen = min(i + 1, (int)str.length() - 1 - i) + 1;
        int k = binarySearch(0, maxLen, str.length(), i, 1);
        ans = max(ans, k * 2);
    }
    printf("%d\n", ans);
    return 0;
}