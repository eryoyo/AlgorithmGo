//
// Created by eryo on 2021/8/13.
//

#include<cstdio>

int main(){
    int rec[11];
    bool flag = true;
    for(int i = 0; i < 10; ++i){
        scanf("%d", rec + i);
        if(flag == true && i > 0 && rec[i] > 0){
            flag = false;
            --rec[i];
            printf("%d", i);
        }
    }
    for(int i = 0; i < 10; ++i){
        for(int j = 0; j < rec[i]; ++j){
            printf("%d", i);
        }
    }
    return 0;
}