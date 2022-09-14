#include <iostream>

int N,K;
int cost[110][110];
int ans[110][110];
// ans[i][j] 代表前i个房子花费的最小值，第i个房子用j颜色
const int max_val = 0x3f3f3f3f;

int min_ans(void){

    for(int i = 0;i < K;++i)
        ans[0][i] = cost[0][i];
        
    for(int i = 0;i < N;++i){
        for(int j = 0;j < K;++j){
            for(int k = 0;k < K;++k){
                if(j != k ) ans[i][j] = ans[i - 1][k] + cost[i][j];
                // else ans[i][j] = max_val;
            }
        }
    }
    int ans_f = ans[N - 1][0];
    for(int i = 1;i < K;++i)
        ans_f = std::min(ans_f,ans[N - 1][i]);
    return ans_f;    
}

int main(){
    std::cin>>N>>K;
    for(int i = 0;i < N;++i){
        for(int j = 0;j < K;++j)
            std::cin>>cost[i][j];
    }
    std::cout<<min_ans()<<std::endl;



    return 0;
}