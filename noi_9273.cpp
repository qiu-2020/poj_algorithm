#include <iostream>
#include <vector>

std::vector<std::vector<int>> ans;

int count(int n){
    if(n == 1) return 1;
    else if(n == 2) return 3;
    else return count(n - 1) + 2 * count(n - 2);
}

void count_dp(void){
    ans[0] = 
    for(int i = 1;i <= n;++i)
}

int main(){
    int n;
    while(std::cin>>n){
        std::cout<<count(n)<<std::endl;
    }


    return 0;
}