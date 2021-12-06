#include <iostream>

int ans[1000010]={0};
int main(){
    ans[1] = 1; ans[2] = 1;
    int n,ni;
    std::cin>>n;
    for(int i = 3;i <= 1000000;i++)
        ans[i] = (ans[i - 1] + ans[i - 2])%1000;

    for(int i = 0;i < n;++i){
        std::cin>>ni;
        std::cout<<ans[ni]<<std::endl;
    }    


    return 0;
}