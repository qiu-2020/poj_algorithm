#include <iostream>

int house[110],N;
int ans[110];

int main(){
    std::cin>>N;
    for(int i = 0;i < N;++i)
        std::cin>>house[i];
    ans[0] = house[0];
    ans[1] = std::max(house[1],ans[0]);
    for(int i = 2;i < N;++i)
        ans[i] = std::max(ans[i - 1],ans[i - 2] + house[i]);
    
    std::cout<<ans[N - 1]<<std::endl;

    return 0;
}