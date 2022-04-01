//
// Created by eryo on 2021/8/9.
//
#include<cstdio>

int main(){
    int n;
    scanf("%d", &n);
    int step = 0;
    while(n != 1){
        if(n % 2 == 0){
            n /= 2;
        }else{
            n = 3 * n + 1;
            n /= 2;
        }
        ++step;
    }
    printf("%d", step);
}