#include <iostream>
#include <cstring>

int N;
int a[21];
int ans[21][41] = {-1};
int pocket(int n,int v){ //前n(bu包括0)个物品的v
    if(v == 0) return 1;
    if(n == 0) return 0;
    return pocket(n-1,v - a[n]) + pocket(n - 1,v); 
}

void pocket_1(int n,int v){
    if(v == 0){
        ans[n][v] = 1;
        return;
    }   

    if(n == 0){
        ans[n][v] = 0;
        return;
    }
 
    if(ans[n - 1][v] == -1) pocket_1(n - 1,v);
    if(v - a[n] >= 0){
        if(ans[n - 1][v - a[n]] == -1) pocket_1(n - 1,v - a[n]);
        ans[n][v] = ans[n - 1][v] + ans[n - 1][v - a[n]];
    }
    else
        ans[n][v] = ans[n - 1][v];

}

void pocket_3(int n,int v){
    for(int i = 0;i <= N;++i){
        for(int j = 0;j <= 40;++j){
            if(i == 0){
                ans[i][j] = 0;
                continue;
            }
            if(j == 0){
                ans[i][j] = 1;
                continue;
            }
            if(i == 1 && a[i] == j){
                ans[i][j] = 1;
                continue;
            }  
            if(j - a[i] >= 0) ans[i][j] = ans[i - 1][j - a[i]] + ans[i - 1][j];
            else ans[i][j] = ans[i - 1][j];
        }
    }
}

int main(){
    std::cin>>N;
    for(int i = 1;i <= N;++i){
        std::cin>>a[i];
    }
    // memset(ans,-1,sizeof(ans));
    pocket_3(N,40);
    std::cout<<ans[N][40]<<std::endl;
    // std::cout<<pocket(N,40)<<std::endl;
    return 0;
}