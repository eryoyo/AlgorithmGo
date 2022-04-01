//
// Created by eryo on 2021/8/9.
//

#include<cstdio>
#include <climits>

int record[100000] = {0};

int main(){
    int max_num = 0;
    int max_score = INT_MIN;
    int n = 0;
    scanf("%d", &n);
    while(n){
        --n;
        int num = 0;
        int score = 0;
        scanf("%d%d", &num, &score);
        record[num] += score;
        if(max_score < record[num]){
            max_score = record[num];
            max_num = num;
        }
    }
    printf("%d %d", max_num, max_score);
    return 0;
}