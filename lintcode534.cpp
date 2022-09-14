#include <iostream>

int A[110],N;
int ans1[110],ans2[110];

int main(){
    std::cin>>N;
    for(int i = 0;i < N;++i)
        std::cin>>A[i];
    ans1[0] = A[0]; ans1[1] = std::max(A[1],A[0]);
    ans2[0] = A[1]; ans2[1] = std::max(A[1],A[2]);
    for(int i = 2;i < N - 1;++i)
        ans1[i] = std::max(ans1[i - 2] + A[i],ans1[i - 1]);
    for(int i = 3;i < N;++i)    
        ans2[i] = std::max(ans2[i - 2] + A[i],ans2[i - 1]);

    std::cout<<std::max(ans1[N - 2],ans2[N - 1])<<std::endl;
    return 0;
}