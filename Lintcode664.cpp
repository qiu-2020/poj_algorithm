#include <iostream>

int ans[110];

int main(){
    int N;
    ans[0] = 0;
    std::cin>>N;
    for(int i = 1;i <= N;++i)
        ans[i] = ans[i >> 1] + (i % 2);
    for(int j = 0;j <= N;++j)
        std::cout<<ans[j]<<' ';
    std::cout<<std::endl;    


    return 0;
}