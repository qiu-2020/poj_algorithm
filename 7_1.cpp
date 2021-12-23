#include <iostream>

const int MAX = 55;

int ans[MAX][MAX] = {};


int count(int n,int m){
    if(m > n) return count(n,n);
    else{
        if(n == 0) return 0;
        else if(n == 1) return 1;
        else{
            int tmp = 0;
            if(m == n) tmp = 1;
            for(int i = m;i >= 1;--i){
                tmp += count(n - i,i);
            }
            return tmp;
        }
    }
}

void count_dp(void){
    for(int i = 0;i <= 50;++i){
        for(int j = 0;j <= i;++j){
            if(j == 0 || i == 0) ans[i][j] = 0;
            else if (i == 1) ans[i][j] = 1;
            else{
                for(int k = j;k >= 1;--k){
                    ans[i][j] += ans[i - k][i - k];
                }
                if(i == j) ans[i][j] += 1;
            }
        }
    }
}


//5: 5
//   4 + 1
//   3 + 2 3 + 1 + 1
//   2 + 2 + 1  2 + 1 + 1 + 1
//   1 + 1 + 1 + 1 + 1

// 3
// 2 + 1
// 1 + 1 + 1

int main(){
    int n;
    std::cin>>n;
    count_dp();
    std::cout<<ans[n][n]<<std::endl;
    // std::cout<<count(n,n)<<std::endl;

    return 0;
}