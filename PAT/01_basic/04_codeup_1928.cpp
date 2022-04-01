//
// Created by eryo on 2021/8/9.
//

#include<cstdio>

int month[13][2] = {
        {0, 0}, {31, 31}, {28, 29}, {31, 31}, {30, 30},
        {31, 31}, {30, 30}, {31, 31}, {31, 31}, {30, 30},
        {31, 31}, {30, 30}, {31, 31}
};

bool is_leap_year(int year){
    return (year % 4 == 0 && year % 100 != 0) ||
            (year % 400 == 0);
}

int main(){
    int t1, y1, m1, d1;
    int t2, y2, m2, d2;
    while(scanf("%d%d", &t1, &t2) != EOF){
        if(t1 > t2){
            int temp = t1;
            t1 = t2;
            t2 = temp;
        }
        y1 = t1 / 10000, m1 = t1 % 10000 / 100, d1 = t1 % 100;
        y2 = t2 / 10000, m2 = t2 % 10000 / 100, d2 = t2 % 100;
        int ans = 1;
        while(y1 < y2 || m1 < m2 || d1 < d2){
            ++d1;
            if(d1 == month[m1][is_leap_year(y1)] + 1){
                ++m1;
                d1 = 1;
            }
            if(m1 == 13){
                ++y1;
                m1 = 1;
            }
            ++ans;
        }
        printf("%d\n", ans);
    }
    return 0;
}