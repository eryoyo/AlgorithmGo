//
// Created by eryo on 2021/9/5.
//

//解决全源最短路径问题

const int INF = 0x3fffffff;
const int MAXV = 200;
int n;      //点数
int m;      //边数
int dis[MAXV][MAXV];

void Floyd(){
    //k必须在最外层
    for(int k = 0; k < n; ++k){
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(dis[i][k] != INF && dis[k][j] != INF
                && dis[i][k] + dis[k][j] < dis[i][j]){
                    dis[i][j] = dis[i][k] + dis[k][j];
                }
            }
        }
    }
}