#include <iostream>
#include <cstring>

const int MAX = 55;
int N,K;

int ans1[MAX][MAX]; 
int ans2[MAX];

void split1(void){
    for(int i = 1;i <= N;++i){
        for(int j = 1;j <= N;++j){
            if(j > i){
                ans1[i][j] = 0;
                continue;
            }
            if(j == i || j == 1){
                ans1[i][j] = 1;
                continue;
            }
            ans1[i][j] = ans1[i - 1][j - 1] + ans1[i - j][j];
        }
    }
}
 
// int split(int N,int K){
//     if(N == )
// }
//f(3,2) = f(1,1) + f(3,1)
//f(5,2) = f(3,2) + f(5,1)
void split2(void){
    for(int j = 0;j <= N;++j){
        for(int i = N;i >= 0;--i){
            if(i == 0 && j == 0) ans2[i] = 1;
            else if(i == 0) ans2[i] = 1;
            else if(j == 0) ans2[i] = 0;
            else{
                if(i >= j) ans2[i] = ans2[i - j] + ans2[i];
                else continue;
            }
        }
    }
}

//7 6 + 1 5 + 2 4 + 3 1 + 1 + ... + 1 
//7 5 + 1 + 1 3 + 1 + 1 + 1 + 1 1 + 1 + ... + 1


int ans3[MAX]; 

void split3(void){
    for(int j = 1;j <= N;++j){
        for(int i = 0;i <= N;++i){
            if(j == 1){
                ans3[i] = 1;
                continue;
            }    
            if(j % 2 == 0) continue;
            if(j > i){
                continue;
            }    
            else 
                ans3[i] = ans3[i] + ans3[i - j];
        } 
    }
}


// void split2(void){
//     for(int i = 0;i <= N;++i){ // 分解i
//         for(int j = 0;j <= i;++j){
//             if(i == 0 && j == 0) ans2[i][j] = 1;
//             else if(i == 0 && j != 0) ans2[i][j] = 1;
//             else if(j == 0 && j != 0) ans2[i][j] = 0;
//             else{
//                 ans2[i][j] = ans2[i - j][j - 1] + ans2[i][j - 1];
//             }
//         }  // 最大的因子
//     }
// }

int main(){
    while(std::cin>>N>>K){
        memset(ans1,0,sizeof(ans1));
        split1();
        memset(ans2,0,sizeof(ans2));
        split2();
        memset(ans3,0,sizeof(ans3));
        split3();
        std::cout<<ans1[N][K]<<std::endl;
        std::cout<<ans2[N]<<std::endl;
        std::cout<<ans3[N]<<std::endl;
    }
    return 0;
}