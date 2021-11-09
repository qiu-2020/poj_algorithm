#include <iostream>

int set_divided(int n,int m){
    if(n == 1) return 1;
    else if(m == 1) return 1;
    else if(m == n) return 1;
    else{
        return set_divided(n - 1,m) * m + set_divided(n - 1,m - 1);
    }
}

int main(){
    int count = 0,n;
    std::cin>>n;
    for(int m = 1;m <= n;++m){
        count += set_divided(n,m);
    }
    std::cout<<count<<std::endl;

    return 0;
}