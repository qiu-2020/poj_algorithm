#include <iostream>
#include <cstring>

const int MAX = 13010;
int M,N;
int T[3510][2];
int ans[MAX][MAX];
int ans[MAX];

// int max_price(void){
//     memset(ans,0,sizeof(ans));
//     for(int i = 1;i <= N;++i){
//         for(int j = M;j >= 0;--j){
//             if(j >= T[i][0])
//                 ans[i][j] = std::max(ans[i - 1][j],ans[i - 1][j - T[i][0]] + T[i][1]);
//             else
//                 ans[i][j] = ans[i - 1][j];    
//         }
//     } 
//     return ans[N][M];   
// }//  j    0  1  2  3
int max_price_2(void){
    // memset(ans,0,sizeof(ans));
    // for(int j = 0;j <= M;++j)
    //     if(j >= T[0][0]) ans[j] = T[0][1];
    //     else ans[j] = 0;
    for(int i = 1;i <= N;++i){   
        for(int j = M;j >= 0;--j){
            if(j >= T[i][0])
                ans[j] = std::max(ans[j],ans[j - T[i][0]] + T[i][1]);
            else
                continue;    
        }       
    }
    return ans[M];
}

// int max_price_3(void){
//     for(int i = )
// }

int main(){
    std::cin>>N>>M;
    for(int i = 1;i <= N;++i)
        std::cin>>T[i][0]>>T[i][1];
    std::cout<<max_price_2()<<std::endl;
    // std::cout<<ans[M][N - 1]<<std::endl;

    return 0;
}