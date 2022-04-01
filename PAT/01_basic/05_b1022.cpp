//
// Created by eryo on 2021/8/9.
//

#include<cstdio>
#include<vector>

using namespace std;

int main(){
    int a, b, d;
    scanf("%d%d%d", &a, &b, &d);
    int sum = a + b;
    vector<int> result;
    do{
        result.push_back(sum % d);
        sum /= d;
    }while(sum);
    for(int i = result.size() - 1; i >= 0; --i){
        printf("%d", result[i]);
    }
}