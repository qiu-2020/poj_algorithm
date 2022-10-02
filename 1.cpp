#include <iostream>
#include <cstdlib>
#include <cmath>

int main(){
    int m;
    double n,ans = 0,root = 0;
    while(std::cin>>n>>m){
        ans = n;
        root = n;
        for(int i = 1;i < m;++i){
            root = sqrt(root);
            ans += root;
        }
        printf("%.2f",ans);
    }

    return 0;
}
