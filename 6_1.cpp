#include <iostream>

const int MAX = 9999;

int num[MAX][MAX] = {0};
int max_rol = 0;

int max_sum(int r,int c){
    if(r == max_rol) return num[r][c];
    else{
        return num[r][c] + std::max(max_sum(r + 1,c),max_sum(r + 1,c + 1));
    }
}

int main(){
    int n;
    std::cin>>n;
    max_rol = n;
    for(int i = 0;i < n;i++){
        for(int j = 0;j <= i;j++){
            std::cin>>num[i][j];
        }
    }
    std::cout<<max_sum(0,0)<<std::endl;

    return 0;
}