#include <iostream>

const int MAX = 210;
int n,x;
int a[MAX];
int ans[MAX];
bool tmp[MAX];

void coin(int x,int i){
    if(x == 0 && i <= n){
        for(int i = 0;i < n;++i)
            if(tmp[i])
                ans[i]++;
    }             
    else if(x > 0 && i < n){
        tmp[i] = true;
        coin(x - a[i],i + 1);
        tmp[i] = false;
        coin(x,i + 1);    
    }
    else return;
}
// 

// void coin_dp(void){

// }

int main(){
    std::cin>>n>>x;
    for(int i = 0;i < n;++i)
        std::cin>>a[i];
    coin(x,0);
//    std::cout<<"1"<<std::endl;
    int t = ans[0];
    for(int i = 0;i < n;++i)
        if(ans[i] > t) 
            t = ans[i];
    int count = 0; 
    if(t == ans[0]){
        std::cout<<0<<std::endl;
        std::cout<<std::endl;
    }
    else{   
        for(int i = 0;i < n;++i)
            if(ans[i] == t) count++;
        std::cout<<count<<std::endl;
        for(int i = 0;i < n;++i)
            if(ans[i] == t)
                std::cout<<a[i]<<' ';    
        std::cout<<std::endl;
    }
    return 0;
}