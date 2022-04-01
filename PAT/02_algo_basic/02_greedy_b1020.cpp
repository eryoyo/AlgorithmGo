//
// Created by eryo on 2021/8/13.
//

#include<cstdio>
#include<algorithm>

using namespace std;

struct mooncake{
    double store;
    double sell;
    double price;
}cake[1010];

bool cmp(mooncake a, mooncake b){
    return a.price > b.price;
}

int main(){
    int n;
    double d;
    scanf("%d%lf", &n, &d);
    for(int i = 0; i < n; ++i){
        scanf("%lf", &cake[i].store);
    }
    for(int i = 0; i < n; ++i){
        scanf("%lf", &cake[i].sell);
        cake[i].price = cake[i].sell / cake[i].store;
    }
    sort(cake, cake + n, cmp);
    double ans = 0;

    for(int i = 0; i < n; ++i){
        if(cake[i].store <= d){
            d -= cake[i].store;
            ans += cake[i].sell;
        }else{
            ans += cake[i].price * d;
            break;
        }
    }
    printf("%.2f\n", ans);
    return 0;
}