//
// Created by eryo on 2021/8/13.
//

//给出一些开区间，求这些区间中互不相交的区间子集且子集内区间个数最多

//解法：
//假如一个区间包含在大一点的区间里面，那么保留较小的区间，首先将这些区间
//按照左端点由大到小排序，左端点相同的按照右端点由小到大排序
//排序之后这些区间中第一个区间总有一段和任何区间都不相交，
//剩余部分是下一区间的子区间，则取该区间

#include<cstdio>
#include<algorithm>

using namespace std;

const int maxn = 110;
struct Interval{
    int x, y; //开区间左右端点
}I[maxn];

bool cmp(Interval a, Interval b){
    if(a.x != b.x){
        return a.x > b.x;
    }else{
        return a.y < b.y;
    }
}

int main(){
    int n;
    while(scanf("%d", &n), n != 0){
        for(int i = 0; i < n; ++i){
            scanf("%d%d", &I[i].x, &I[i].y);
        }
        sort(I, I + n, cmp);
        int ans = 1, lastX = I[0].x;
        for(int i = 1; i < n; ++i){
            if(I[i].y <= lastX){
                lastX = I[i].x;
                ++ans;
            }
        }
        printf("%d", ans);
    }
    return 0;
}