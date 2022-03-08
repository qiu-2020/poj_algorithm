#include <iostream>

int a[1010],N,ans[1010];

int main(){
    std::cin>>N;
    for(int i = 0;i < N;++i){
        std::cin>>a[i];
        ans[i] = 1;
    }    
    for(int i = 1;i < N;++i){
        for(int j = i - 1;j >= 0;--j){
            if(a[i] > a[j])
                ans[i] = std::max(ans[i],1 + ans[j]);
        }
    }
    int tmp = ans[0];
    for(int i = 1;i < N;++i)
        if(ans[i] > tmp)
            tmp = ans[i];
    std::cout<<tmp<<std::endl;        

    return 0;
}