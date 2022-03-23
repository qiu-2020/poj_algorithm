#include <iostream>
#include <cstring>
#include <vector>

const int MAX_N = 1010;
const int MAX_T = 2010;
int T,N,V_num;
int g[MAX_T][3];
int dis[MAX_N];

void bellman_ford(int s){
    dis[s] = 0;
    for(int i = 0;i < T;++i){
        for(int j = 0;j < T;++j){
            if(dis[g[j][0]] <= 0x3f3f3f3f && dis[g[j][0]] + g[j][2] < dis[g[j][1]])
                dis[g[j][1]] = dis[g[j][0]] + g[j][2];
            if(dis[g[j][1]] <= 0x3f3f3f3f && dis[g[j][0]] > dis[g[j][1]] + g[j][2])
                dis[g[j][0]] = dis[g[j][1]] + g[j][2];    
        }
    }
}

int main(){
    std::cin>>T>>N;
    for(int i = 0;i < T;++i)
        for(int j = 0;j < 3;++j)
            std::cin>>g[i][j];
    memset(dis,0x3f,sizeof(dis));
    bellman_ford(1);
    std::cout<<dis[N]<<std::endl;
        
    return 0;
}

// relax(u,v,w):
// if(dis.v > dis.u + w(u,v) )
//      dis.v = dis.u + w(u,v)     