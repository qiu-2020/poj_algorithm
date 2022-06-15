#include <iostream>
#include <cstring>


int ans[110][2];
int h[110];


int max_len_r(int n){
    int max_l = 0;
    for(int i = 1;i < n;++i){
        for(int j = 0;j < i;++j){
            if(h[j] < h[i]){
                ans[i][0] = std::max(ans[i][0],ans[j][0] + 1);
                if(ans[i][0] > max_l)
                    max_l = ans[i][0];
            }
            else if(h[j] > h[i]){
                ans[i][1] = std::max(ans[i][1],ans[j][1] + 1);
                if(ans[i][1] > max_l)
                    max_l = ans[i][1];
            }
        }
    }
    return max_l;
}


int main(){
    int N,n;
    std::cin>>N;
    for(int i = 0;i < N;++i){
        std::cin>>n;
        for(int j = 0;j < n;++j){
            std::cin>>h[j];
        }
        for(int j = 0;j < n;++j){
            ans[j][0] = 1;
            ans[j][1] = 1;
        }

        std::cout<<max_len_r(n)<<std::endl;

    }
//维护二维数组ans[i][2] ans[i][0]:单调上升 ans[i][1]:单调下降
//     2 1 3 4 5 6 7 8 9 10
// up  1 1 2 3 4 5 6 7 8 9
//down 1 2 1 1 1 1 1 1 1 1

    return 0;
}