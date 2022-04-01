//
// Created by eryo on 2021/8/10.
//

#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

struct stu{
    char reg[15];
    int score;
    int room;
    int rank;
    int local_rank;
    friend bool operator < (stu a, stu b){
        if(a.score != b.score){
            return a.score > b.score;
        }else{
            return strcmp(a.reg, b.reg) < 0;
        }
    }
}ranklist[60000];

int main(){
    int n, k, index = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        scanf("%d", &k);
        if(k == 0){
            continue;
        }
        for(int j = 0; j < k; ++j){
            ranklist[index].room = i + 1;
            scanf("%s %d", ranklist[index].reg, &(ranklist[index].score));
            ++index;
        }
        sort(ranklist + index - k, ranklist + index);
        ranklist[index - k].local_rank = 1;
        for(int m = index - k + 1; m < index; ++m){
            if(ranklist[m].score == ranklist[m - 1].score){
                ranklist[m].local_rank = ranklist[m - 1].local_rank;
            }else{
                ranklist[m].local_rank = m - index + k + 1;
            }
        }
    }
    sort(ranklist, ranklist + index);
    ranklist[0].rank = 1;
    for(int i = 1; i < index; ++i){
        if(ranklist[i].score == ranklist[i - 1].score){
            ranklist[i].rank = ranklist[i - 1].rank;
        }else{
            ranklist[i].rank = i + 1;
        }
    }
    printf("%d\n", index);
    for(int i = 0; i < index; ++i){
        printf("%s %d %d %d", ranklist[i].reg,
               ranklist[i].rank,
               ranklist[i].room,
               ranklist[i].local_rank);
        if(i != index - 1){
            printf("\n");
        }
    }
    return 0;
}