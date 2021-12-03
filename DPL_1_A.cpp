#include <iostream>

const int MAX = 20;


int c[MAX];
int n,m;
int ans[20][10010];

int count_num(int n){
    if(n == 1) return 1;
    else if(n == 0) return 0;
    else{
        int tmp = 15000;
        for(int i = m - 1;i >= 0;--i){
            if(c[i] <= n)
                if(tmp >= 1 + count_num(n - c[i]))
                    tmp = 1 + count_num(n - c[i]);
        }
        return tmp;
    }    
}

void count_num_dp(void){
    for(int i = 0;i < m;i++){
        for(int j = 0;j <= n;j++){
            if(i == 0) ans[i][j] = 0;
            else if(j == 0) ans[i][j] = 0;
            else{
                
            }
        }
    }
}


int main(){
    std::cin>>n>>m;
    for(int i = 0;i < m;++i)
        std::cin>>c[i];
    std::cout<<count_num(n)<<std::endl;



    return 0;
}
