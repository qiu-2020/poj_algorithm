#include <iostream>

const int MAX = 55;

int N,K;
int dp1[MAX][MAX],dp2[MAX][MAX],dp3[MAX][MAX];

int complex_1(int N,int K){//将N分K分
    if(K == 0 && N == 0) return 1; 
    if(K == 0) return 0;
    if(N < K) return 0;
    else if(N == K) return 1;
    else{
        return complex_1(N - K,K) + complex_1(N - 1,K - 1);
    }
}

void dp_1(void){
    for(int i = 0;i <= N;++i){
        for(int j = 0;j <= N;++j){
            if(j == 0){
                dp1[i][j] = 0;
                continue;
            }    
            if(i == j) dp1[i][j] = 1;
            else dp1[i][j] = dp1[i - j][j] + dp1[i - 1][j - 1];
        }
    }
}

int complex_2(int N,int M){ //选择M,M是最大因子
    if(N < 0 && M <= 0) return 0;
    // if(M <= 0) return 0;
    if(N == 0 && M == 0) return 0;
    if(N == 0 && M >= 1) return 1;
    else if(N == 1 && M >= 1) return 1;
    else if(N == 2 && M >= 2) return 1;
    else if(N == 2 && M <= 1) return 0;
    else{
        return complex_2(N - M,M - 1) + complex_2(N,M - 1);
    }
}

void dp_2(void){
    for(int i = 0;i <= N;++i){
        for(int j = 0;j <= N;++j){
            if(i == 0 && j == 0){
                dp2[i][j] = 0;
                continue;
            }
            if(i == 0) dp2[i][j] = 1;
            else if(i == 1 && j >= 1) dp2[i][j] = 1;
            else if(i == 2 && j == 1) dp2[i][j] = 0;
            else if(i == 2 && j >= 2) dp2[i][j] = 1;
            else dp2[i][j] = dp2[i - j][j - 1] + dp2[i][j - 1];
        }
    }
}

int complex_3(int N,int M){ // M指组成N的最大奇数
    if(M % 2 == 0) return complex_3(N,M - 1);
    if(N < 0 || M <= 0) return 0;
    else if(N > 0 && M == 1) return 1;
    else if(N == 0 && M >= 1) return 1;
    else if(N == 1 && M >= 1) return 1;
    else if(N == 1 && M < 1) return 0;
    else return complex_3(N - M,M) + complex_3(N,M - 2);
}

void dp_3(void){
    for(int i = 0;i <= N;++i){
        for(int j = 0;j <= N;++j){
            if(j % 2 == 0){
                dp3[i][j] = dp3[i][j - 1];
                continue;
            }
            if(j == 0) dp3[i][j] = 0;
            else if(i > 0 && j == 1) dp3[i][j] = 1;
            else if(i == 0 && j >= 1) dp3[i][j] = 1;
            else if(i == 1 && j >= 1) dp3[i][j] = 1;
            else if(i == 1 && j == 0) dp3[i][j] = 0;
            else dp3[i][j] = dp3[i - j][j] + dp3[i][j - 2];    
        }
    }
}

// 1 + 3 + 1  1 + 1 + 1 + 1 + 1 5 
// f(0,1) = 1 f(0,0) = 0
// f(1,0) = 0 f(1,1) = 1
// f(2,2) = 1


int main(){
    std::cin>>N>>K;
    // dp_1();
    // dp_2();
    // dp_3();
    std::cout<<complex_1(N,K)<<std::endl;
    std::cout<<complex_2(N,N)<<std::endl;
    std::cout<<complex_3(N,N)<<std::endl;

    return 0;
}

// 2 + 2 + 2 + 2;5 + 1 + 1 + 1;4 + 2 + 1 + 1;3 + 3 + 1 + 1;3 + 2 + 2 + 1
// 8 ; 7 + 1; 6 + 2;5 + 2 + 1;4 + 3 + 1;
//7 + 1;5 + 3;5 + 1 + 1 + 1;3 + 3 + 1 + 1,3 + 1 + ... + 1;1 + ... +1