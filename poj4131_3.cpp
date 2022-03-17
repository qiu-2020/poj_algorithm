#include <iostream>

const int MAX_N = 3500;
const int MAX_M = 12890;
int ans[MAX_N][MAX_M];
int T[MAX_N][2],N,M;

int max_price(void){
    for(int i = 1;i <= N;++i){
        for(int j = 0;j <= M;++j){
            if(j >= T[i][0])
                ans[i][j] = std::max(ans[i - 1][j],ans[i - 1][j - T[i][0]] + T[i][1]);
            else ans[i][j] = ans[i - 1][j];    
        }
    }
    return ans[N][M];
}

int main(){
    std::cin>>N>>M;
    for(int i = 1;i <= N;++i)
        std::cin>>T[i][0]>>T[i][1];
    std::cout<<max_price()<<std::endl;
    return 0;
}