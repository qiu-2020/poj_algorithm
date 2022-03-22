#include <iostream>
#include <cstring>

int N;
int cost[20][20],ans,this_ans;
int minC[20];
bool visited[20];


void count(int num,int i){
    if(i == N - 1 && num == 0){
        if(this_ans < ans)
            ans = this_ans;
        return;     
    }
//     if(minC[num] < this_ans) return;
// //剩下num个地点未访问时最小    
//     else minC[num] = this_ans;

    if(i == N - 1 && num != 0) return;
    if(this_ans > ans) return;
    for(int j = 0;j < N;++j){
        if(visited[j]) continue;
        visited[j] = true;
        this_ans += cost[i][j];
        count(num - 1,j);
        visited[j] = false;
        this_ans -= cost[i][j];
    }
}

int main(){
    std::cin>>N;
    for(int i = 0;i < N;++i){
        for(int j = 0;j < N;++j){
            std::cin>>cost[i][j];
        }
    }
    ans = 1 << 30; this_ans = 0;
    memset(visited,0,sizeof(visited));
    memset(minC,0x3f,sizeof(minC));
    visited[0] = true;
    count(N - 1,0);
    std::cout<<ans<<std::endl;


    return 0;
}