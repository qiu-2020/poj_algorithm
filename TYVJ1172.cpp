#include <iostream>
#include <cstring>

const int MAX = 4010;
int N;
int ans[MAX][MAX];

// ans[i][j] = ans[i - 1][j] + ans[i][j - i]

void count(void){
    for(int i = 1;i <= N;++i){
        for(int j = 0;j <= N;++j){
            if(j > i) ans[i][j] = (ans[i - 1][j] + ans[i][j - i]) % 2147483648;
            else if(j == i) ans[i][j] = (ans[i - 1][j] + 1) % 2147483648;
            else ans[i][j] = ans[i - 1][j];
        }
    }
}

int main(){
    std::cin>>N;
    count();
    std::cout<<ans[N][N]<<std::endl;
    return 0;
}