#include <iostream>

int N,h[1010];
int ans_up[1010],ans_down[1010];

int main(){
    std::cin>>N;
    for(int i = 0;i < N;++i){
        std::cin>>h[i];
        ans_up[i] = 1;
        ans_down[i] = 1;
    }
    int max_len = 1;
    for(int i = 1;i < N;++i){
        for(int j = i - 1;j >= 0;--j){
            if(h[i] > h[j])
                ans_up[i] = std::max(ans_up[i],ans_up[j] + 1);
        }
    }
    for(int i = N - 2;i >= 0;--i){
        for(int j = i + 1;j < N;++j){
            if(h[i] > h[j])
                ans_down[i] = std::max(ans_down[i],ans_down[j] + 1);
        }
    }
    int ans = 1;
    for(int i = 0;i < N;++i){
        if(ans_up[i] + ans_down[i] > ans)
            ans = ans_up[i] + ans_down[i];
    }

    std::cout<<ans - 1<<std::endl;


    return 0;
}