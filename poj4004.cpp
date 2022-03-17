#include <iostream>

const int MAX = 25;
int n,t;
int a[MAX];
int ans[MAX][1010];

// ans[i][j] = ans[i - 1][j] + ans[i - 1][j - a[i]]

int count_num(void){
    // for(int j = 1;j <= t;++j)
    //     if(j == a[1]) ans[1][j] = 1;
    //     else ans[1][j] = 0;
    for(int i = 1;i <= n;++i){
        for(int j = 0;j <= t;++j){
            if(j == a[i])
                ans[i][j] = 1 + ans[i - 1][j];
            else if(j > a[i])
                ans[i][j] = ans[i - 1][j] + ans[i - 1][j - a[i]];
            else ans[i][j] = ans[i - 1][j];    
        }
    }
    return ans[n][t];
}

int main(){
    std::cin>>n>>t;
    for(int i = 1;i <= n;++i)
        std::cin>>a[i];
    std::cout<<count_num()<<std::endl;

    return 0;
}