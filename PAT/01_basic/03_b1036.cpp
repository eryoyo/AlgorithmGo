//
// Created by eryo on 2021/8/9.
//

#include<cstdio>

int main(){
    int n = 0;
    char c = ' ';
    scanf("%d %c", &n, &c);
    int row = n % 2 ? n / 2 + 1 : n / 2;
    for(int i = 0; i < row; ++i){
        for(int j = 0; j < n; ++j){
            if(i == 0 || i == row - 1){
                printf("%c", c);
            }else{
                if(j == 0 || j == n - 1){
                    printf("%c", c);
                }else{
                    printf("%c", ' ');
                }
            }
        }
        if(i != row - 1){
            printf("\n");
        }
    }
    return 0;
}