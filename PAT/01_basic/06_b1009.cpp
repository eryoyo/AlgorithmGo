//
// Created by eryo on 2021/8/9.110
//

#include<cstdio>

int main(){
    char record[81][81];
    int n = 0;
    while(scanf("%s", record[n]) != EOF){
        ++n;
    }
    for(int i = n - 1; i >= 0; --i){
        printf("%s", record[i]);
        if(i > 0){
            printf(" ");
        }
    }
    return 0;
}