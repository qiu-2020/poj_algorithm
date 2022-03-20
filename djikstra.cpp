#include <iostream>
#include <cstring>
#include <vector>

const int MAX = 1010;
int N,G[MAX][MAX];
int distance[MAX];
bool visited[MAX] = {false};

void dijkstra(int s){
    memset(distance,0xcf,sizeof(distance));
    distance[s] = 0;
    for(int i = 0;i < N;++i){
        int MIN = 1 << 29,u = -1;
        for(int j = 0;j < N;++j){
            if(!visited[j] && distance[j] < MIN){
                MIN = distance[j];
                u = j;
            }
        }
        if(u == -1) return;
        visited[u] = true;
        for(int j = 0;j < N;++j){
            if(!visited[j] && G[u][j] + distance[u] < distance[j] && G[u][j] != 1 << 29)
                distance[j] = G[u][j] + distance[u];
        }
    }
}

class Node{
public:    
    int _v_target,_dis;
};

std::vector<Node> adj[MAX];

void dijkstra(int s){
    memset(distance,0xcf,sizeof(distance));
    distance[s] = 0;
    for(int i = 0;i < N;++i){
        int MIN = 0xcfcfcfcf,u = -1;
        for(int j = 0;j < N;++j){
            if(!visited[j] && distance[j] < MIN){
                MIN = distance[j];
                u = j;
            }
        }
        if(u == -1) return;
        visited[u] = true;
        for(int j = 0;j < N;++j){
            for(std::vector<Node>::iterator it = adj[u].begin();it != adj[u].end();++it){
                if(!visited[j] && it->_dis + distance[u] < distance[it->_v_target])
                    distance[it->_v_target] = it->_dis + distance[u];
            }
        }
    }
}

int main(){



    return 0;
}