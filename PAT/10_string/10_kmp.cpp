//
// Created by eryo on 2021/9/6.
//

//KMP算法
/*
 解决字符串的匹配问题
 有一个文本串text，模式串pattern，判断pattern是不是text的子串

 O(n + m):两个字符串的长度
 */

// https://www.zhihu.com/question/21923021/answer/281346746

//next数组
/*
 假设有一个字符串，其中以i号为结尾的子串就是s[0...i]
 对该子串来说，其前缀为s[0...k],后缀s[i-k,i]

 next[i]表示使得前缀等于后缀的最大的k,其中前缀和后缀可以部分重合但不能全部重合
 */
/*
 求解的思路分析
 首先假如next[0]-next[i]都已经求出来了
 假如s[i+1]==s[next[i]+1]那么next[i+1]=next[i]+1
 假如s[i+1]！=s[next[i]+1]
 那么就要寻找j使得s[j+1]==s[i+1]
 且s[0...j]是s[0...next[i]]的后缀
 所以s[0...j]是s[0...next[i]]的前缀以及后缀
 */
#include <cstring>

/*
 算法：
 首先初始化next数组，令j=next[0]=-1
 然后进入循环，i从1~len-1，不断重复下面的步骤
 让j=next[j],直到j回退为-1，或是s[i]==s[j+1]
 如果s[i]==s[j+1]则next[i]=j+1,否则next[i]=j
 */

int next[1000];

//getNext求解长度为len的字符串s的next数组
//j为最新的匹配的位置
void getNext(char s[], int len){
    int j = -1;
    next[0] = -1;
    for(int i = 1; i < len; ++i){
        while(j != -1 && s[i] != s[j + 1]){
            j = next[j];
        }
        if(s[i] == s[j + 1]){
            ++j;
        }
        next[i] = j;
    }
}

//j指向pattern中已被匹配的最后位
//主要思想就是在某一次匹配失败的时候不是回到pattern串的最初而是回到中间的
//某一个位置，使得之前的匹配不被浪费
bool KMP(char text[], char pattern[]){
    int n = strlen(text);
    int m = strlen(pattern);
    getNext(pattern, m);
    int j = -1;
    for(int i = 0; i < n; ++i){
        while(j != -1 && text[i] != pattern[j + 1]){
            j = next[j];
        }
        if(text[i] == pattern[j + 1]){
            ++j;
        }
        if(j == m - 1){
            return true;
        }
    }
    return false;
}

//
int KMP_sta(char text[], char pattern[]){
    int n = strlen(text);
    int m = strlen(pattern);
    getNext(pattern, m);
    int j = -1;
    int ans = 0;
    for(int i = 0; i < n; ++i){
        while(j != -1 && text[i] != pattern[j + 1]){
            j = next[j];
        }
        if(text[i] == pattern[j + 1]){
            ++j;
        }
        if(j == m - 1){
            ans++;
            j = next[j];
        }
    }
    return ans;
}

//getNextval求解长度为len的字符串s的nextval数组
//nextval[i]的含义是当模式串pattern的i+1位失配时，i应当退回的最佳位置
void getNextval(char s[], int len){
    int j = -1;
    next[0] = -1;
    for(int i = 1; i < len; ++i){
        while(j != -1 && s[i] != s[j + 1]){
            j = next[j];
        }
        if(s[i] == s[j + 1]){
            ++j;
        }
        if(j == -1 || s[i + 1] != s[j + 1]){
            next[i] = j;
        }else{
            next[i] = next[j];
        }
    }
}