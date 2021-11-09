#include <iostream>

const int MAX = 101;
int max_row = 0;
int num[MAX][MAX] = {0};

int main(){
    std::cin>>max_row;
    for(int i = 0;i < max_row;++i){
        for(int j = 0;j <= i;++j){
            std::cin>>num[i][j];
        }
    }

    for(int i = max_row - 2;i >= 0;--i){
        for(int j = 0;j <= i;++j){
            num[i][j] += std::max(num[i+1][j],num[i + 1][j + 1]);
        }
    }
    std::cout<<num[0][0]<<std::endl;

    return 0;
}