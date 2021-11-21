#include <iostream>

int N,M;
int charm[3500][2];
int ans[12880] = {0};

void bracklet(void){
    for(int i = 0;i <= M;i++)
        if(charm[0][0] <= i)
            ans[i] = charm[0][1];
    for(int i = 1;i < N;i++){
        for(int j = M;j >= charm[i][0];j--){
            ans[j] = std::max(ans[j],ans[j - charm[i][0]] + charm[i][1]);
        }
    }
}

int main(){
    std::cin>>N>>M;
    for(int i = 0;i < N;i++)
        std::cin>>charm[i][0]>>charm[i][1];
    bracklet();
    std::cout<<ans[M]<<std::endl;


    return 0;
}