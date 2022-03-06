#include <iostream>

const int MAX = 1010;
int N;
int a[MAX],ans[MAX];

void max_increase_seq(void){
    for(int i = 1;i < N;++i){
        for(int j = i - 1;j >= 0;--j){
            if(a[i] > a[j])//可以形成递增
                ans[i] = std::max(ans[j] + 1,ans[i]);    
            else continue;
        }
    }
}

int main(){ 
    std::cin>>N;
    for(int i = 0;i < N;++i){
        std::cin>>a[i];
        ans[i] = 1;
        //以i号结尾的子序列长度初始值为1
    }  
    max_increase_seq();
    int tmp = ans[0];
    for(int i = 1;i < N;++i)
        if(tmp < ans[i])
            tmp = ans[i];
    std::cout<<tmp<<std::endl;        
    return 0;
}