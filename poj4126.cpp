#include <iostream>
#include <cstring>

const int MAX = 1010;
int T,N,V_num;
int graph[MAX][MAX];
int dis[MAX];

bool bellman_ford(int s){
    dis[s] = 0;
    for(int i = 0;i < V_num - 1;++i){
        for(int j = 1;j <= N;++j){
            if(dis[j] == 0x3f3f3f3f) continue;
            for(int k = 1;k <= N;++k){
                if(graph[j][k] == 0x3f3f3f3f) continue;
                else
                    if(dis[j] + graph[j][k] < dis[k])
                        dis[k] = dis[j] + graph[j][k];
            }
        }
    }
    for(int i = 1;i <= N;++i){
        for(int j = 1;j <= N;j++){
            if(i == j) continue;
            if(graph[i][j] != 0x3f3f3f3f && graph[i][j] + dis[i] < dis[j])
                return false;
        }
    }
    return true;
}

int main(){
    std::cin>>T>>N;
    int u,v,w;
    V_num = 0;
    memset(graph,0x3f,sizeof(graph));
    memset(dis,0x3f,sizeof(dis));
    for(int i = 0;i < T;++i){
        std::cin>>u>>v>>w;
        graph[u][v] = w;
        V_num++;
    }
    if(bellman_ford(1))
        std::cout<<dis[N]<<std::endl;
    else std::cout<<"-1"<<std::endl;    

    return 0;
}

// relax(u,v,w):
// if(dis.v > dis.u + w(u,v) )
//      dis.v = dis.u + w(u,v)     