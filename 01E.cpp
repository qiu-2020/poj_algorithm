#include <iostream>

int common(int m,int n){
    if(m < n) return common(n,m);
    if(m % n == 0) return n;
    else return common(n,m % n);
}

int main(){
    int n,m;
    std::cin>>m>>n;
    std::cout<<common(m,n)<<std::endl;


    return 0;
}