#include <iostream>

const int MAX = 210;
int x,n;
int a[MAX];
bool ans[MAX];
bool ans_dp[MAX][MAX][10010];


void coin(int index){
    
}

// bool coin(int index,int i,int x){ //去掉index能否组成x
//     if(index == i){
//         return coin(index,i + 1,x);
//     }
//     if(i <= n && x == 0){
//         if(!ans_dp[index][i][x])
//             ans_dp[index][i][x] = true;
//         return true;    
//     }
//     else if(i < n && x > 0){
//         // if(ans_dp[index][i][x] == -1 )
//         //     ans_dp[index][i][x] = coin(index,i + 1,x) || coin(index,i + 1,x - a[i]);
//         // // bool tmp1,tmp2;       
//         if(ans_dp[index][i][x] == -1){
//             if(ans_dp[index][i + 1][x] == -1)
//                 coin(index,i + 1,x);
//             if(ans_dp[index][i + 1][x - a[i]] == -1)
//                 coin(index,i + 1,x - a[i]);
//             ans_dp[index][i][x] = ans_dp[index][i + 1][x] || ans_dp[index][i + 1][x - a[i]];        
//         }        
//         return ans_dp[index][i][x];
//     }
//     else
//         if(ans_dp[index][i][x] == -1) 
//             ans_dp[index][i][x] = false;
//         return false;    
// }

// // void coin_dp(void){
// //     for(int index = 0;index < n;++index){
    
// //     }
// // }

// //

int main(){
    std::cin>>n>>x;
    for(int i = 0;i < n;++i)
        std::cin>>a[i];
    int count = 0;

    // for(int i = 0;i < n;++i)
    //     coin(i,0,x);
    // // for(int i = 0;i < n;++i)
    // //     if(coin(i,0,x)) ans[i] = false;
    // //    else ans[i] = true;
    // for(int i = 0;i < n;++i)
    //     if(ans_dp[i][0][x]) ans[i] = false;
    //     else ans[i] = true;
    // for(int i = 0;i < n;++i)
    //     if(ans[i]) count++;
    // if(count == 0)
    //     std::cout<<0<<std::endl<<std::endl;        
    // else{
    //     std::cout<<count<<std::endl;
    //     for(int i = 0;i < n;++i)
    //         if(ans[i])
    //             std::cout<<a[i]<<' ';
    //     std::cout<<std::endl;         
    // }        

    return 0;
}