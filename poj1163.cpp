#include <iostream>

int a[110][110];
int ans[110];

int main(){
    int n;
    std::cin>>n;
    for(int i = 0;i < n;++i)
        for(int j = 0;j <= i;++j)
            std::cin>>a[i][j];
    for(int i = 0;i < n;++i)
        ans[i] = a[n - 1][i];        
    for(int i = n - 2;i >= 0;--i){
        for(int j = 0;j <= i;++j){
            ans[j] = std::max(ans[j],ans[j + 1]) + a[i][j];
        }
    }
    std::cout<<ans[0]<<std::endl;
    return 0;
}