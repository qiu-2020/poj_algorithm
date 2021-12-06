#include <iostream>

int ans[1000010]  = {0};

int main(){
    int n,ni;
    std::cin>>n;
    ans[1] = 1; ans[2] = 2;
    for(int i = 3;i <=1000000;++i){
        ans[i] = (ans[i - 1] * 2 + ans[i - 2]) % 32767;
    }
    for(int i = 0;i < n;++i){
        std::cin>>ni;
        std::cout<<ans[ni]<<std::endl;
    }



    return 0;
}