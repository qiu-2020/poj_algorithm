#include <iostream>

int N,P[110],ans[110];

int main(){
    std::cin>>N;
    for(int i = 0;i < N;++i)
        std::cin>>P[i];
    ans[0] = 0;
    int tmp_min = P[0],tmp_ans = 0;
    for(int i = 0;i < N;++i){
        if(P[i] < tmp_min) tmp_min = P[i];
        ans[i] = P[i] - tmp_min > 0 ? P[i] - tmp_min : 0;
        // ...
    }    

    return 0;
}