#include <iostream>

int stair(int n){
    if(n == 1) return 1;
    else if(n == 0) return 0;
    else if(n == 2) return 2;
    else if(n == 3) return 4;
    else{
        return stair(n - 1) + stair(n - 2) + stair(n - 3);
    }
}

int ans[110];
void stair_dp(void){
    for(int i = 4;i <= 100;++i){
        ans[i] = ans[i - 1] + ans[i - 2] + ans[i - 3];
    }
}


int main(){
    int n;
    ans[0] = 0; ans[1] = 1;ans[2] = 2;ans[3] = 4;
    stair_dp();
    while(std::cin>>n && n != 0){
        std::cout<<ans[n]<<std::endl;
    }


    return 0;
}