#include <iostream>

int cost[110][3],N;
int ans[110][3];
int calculate(){
    for(int i = 0;i < N;++i){
        for(int j = 0;j < 3;++j){
            for(int k = 0;k < 3;++k){
                if(k != j){
                    ans[i][j] = ans[i - 1][k] + cost[i][j];
                } 
            }    
        }
    }
    int a = ans[N - 1][0];
    for(int i = 1;i < 3;++i)
        if(a > ans[N - 1][i]) a = ans[N - 1][i];
    return a;    
}

int main(){
    std::cin>>N;
    for(int i = 0;i < N;++i)
        for(int j = 0;j < 3;++j)
            std::cin>>cost[i][j];
    std::cout<<calculate()<<std::endl;
    return 0;
}