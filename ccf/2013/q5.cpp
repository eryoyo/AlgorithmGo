//
// Created by eryo on 2021/9/23.
//

#include<bits/stdc++.h>

using namespace std;


int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    vector<vector<char>> g(n, vector<char>(m));
    vector<vector<bool>> mark(n, vector<bool>(m, false));
    char s[10];
    gets(s);
    pair<int, int> start;
    pair<int, int> end;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            char temp = ' ';
            scanf("%c", &temp);
            if(temp == 'S'){
                start = make_pair(i, j);
            }else if(temp == 'T'){
                end = make_pair(i, j);
            }
        }
    }

    queue<pair<int, int>> q;
    q.push(start);
    while(!q.empty()){
        pair<int, int> cur = q.front();
        q.pop();
        int x= cur.first;
        int y = cur.second;
    }
}