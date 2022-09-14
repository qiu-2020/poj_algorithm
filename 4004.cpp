#include <iostream>

int a[25],n;

int count(int i,int t){
    if(t == 0) return 1;
    if(i == n && t != 0) return 0;

    return count(i + 1,t - a[i]) + count(i + 1,t);


}

int main(){
    int t;
    std::cin>>n>>t;
    for(int i = 0;i < n;++i)
        std::cin>>a[i];
    std::cout<<count(0,t)<<std::endl;

    return 0;
}