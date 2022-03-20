#include <iostream>
#include <vector>
#include <cstring>

int K,N,R;
int ans;
int minL[110][10100];
bool visited[110];
class road{
public:    
    int _d,_L,_T;
    // road(int d,int L,int T):_d(d),_L(L),_T(T){}
};

std::vector<road> roadMap[110];

void DFS(int s,int cost,int length){
    if(s == N && cost <= K){
        if(length < ans){
            ans = length;
        }    
        return;     
    }
    if(cost > K) return;
    if(length >= ans) return;
    minL[s][cost] = std::min(minL[s][cost],length);
    if(s != N){
        for(std::vector<road>::iterator it = roadMap[s].begin();it != roadMap[s].end();++it){
            if(cost + it->_T > K) continue;
            if(length + it->_L > ans) continue; 
            if(minL[it->_d][cost + it->_T] <= length + it->_L)
                continue;
            minL[it->_d][cost + it->_T] = length + it->_L;   
            if(!visited[it->_d]){
                visited[it->_d] = true;
                DFS(it->_d,cost + it->_T,length + it->_L);
                visited[it->_d] = false;   
            }
        }
    }
}

int main(){
    std::cin>>K>>N>>R;
    // k元钱；N个城市；R条路
    int s,e,L,T;
    road tmp;
    for(int i = 1;i <= R;++i){
        std::cin>>s>>e>>L>>T;
        tmp._d = e,tmp._L = L,tmp._T = T;
        roadMap[s].push_back(tmp);
    }
    memset(minL,0x3f,sizeof(minL));
    ans = 0x3f3f3f3f;
    visited[1] = true;
    DFS(1,0,0);
    if(ans == 0x3f3f3f3f)
        std::cout<<"-1"<<std::endl;
    else std::cout<<ans<<std::endl;    



    return 0;
}