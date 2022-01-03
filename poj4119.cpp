#include <iostream>

int N,K;

const int MAX = 55;
int dp1[MAX][MAX],dp2[MAX][MAX],dp3[MAX][MAX];

int count1(int N,int K){
    if(N <= 0 || K <= 0) return 0;
    if(K > N) return 0;
    else if(K == N) return 1;
    else return count1(N - K,K) + count1(N - 1,K - 1);
}

void count1_dp(void){
    for(int i = 0;i <= N;++i){
        for(int j = 0;j <= N;++j){
            if(i == 0 || j == 0){
                dp1[i][j] = 0;
                continue;
            }
            if(j > i) dp1[i][j] = 0;
            else if(j == i) dp1[i][j] = 1;
            else dp1[i][j] = dp1[i - j][j] + dp1[i - 1][j - 1];     
        }
    }
}

int count2(int N,int M_n){
    if(N == 0) return 1;
    if(M_n == 0) return 0;
    else if(N < 0) return 0;
    else
        return count2(N - M_n,M_n - 1) + count2(N,M_n - 1);
}

void count2_dp(void){
    for(int i = 0;i <= N;++i){
        for(int j = 0;j <= i;++j){
            if(i == 0){
                dp2[i][j] = 1;
                continue;
            }
            if(j == 0){
                dp2[i][j] = 0;
                continue;
            }
            dp2[i][j] = dp2[i - j][j - 1] + dp2[i][j - 1];
        }
    }
}

int count3(int N,int M_n){
    if(M_n > N) return count3(N,N);
    if(M_n % 2 == 0) return count3(N,M_n - 1);
    else{
        if(M_n == 1) return 1;
        if(N == 0) return 1;
        else if(N < 0) return 0;
        else return count3(N - M_n,M_n) + count3(N,M_n - 2);//用M_n
    }
}

// 5; 3 + 1 + 1; 1 + ... + 1
// 5 ; 4 + 1; 3 + 2
// 4 + 1 3 + 2
// f(5,2) = f(4,1) + f(3,2) = 1 + f(2,1) + f(1,2) = 1 + 1 + 1

int main(){
    // std::cin>>N>>K;
    // while(std::cin>>N>>K){
    //     if(N == 0 && K == 0){
    //         std::cout<<1<<std::endl<<0<<std::endl<<0<<std::endl;
    //     }
    //     else{
    //         std::cout<<count1(N,K)<<std::endl;
    //         std::cout<<count2(N,N)<<std::endl;
    //         std::cout<<count3(N,N)<<std::endl;
    //     }
    // }

    // while(std::cin>>N>>K){
    //     std::cout<<count1(N,K)<<std::endl;
    //     std::cout<<count2(N,N)<<std::endl;
    //     std::cout<<count3(N,N)<<std::endl;
    // }
    std::cin>>N>>K;
    count2_dp();
    std::cout<<dp2[N][N]<<std::endl;


    return 0;
}