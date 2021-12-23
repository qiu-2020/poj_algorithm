#include <iostream>
#include <cstring>
#include <cmath>

const int MAX = 3010;
int arr1[MAX],arr2[MAX];
int ans[MAX][MAX];
int len;

void LCIS(void){
    for(int i = 0;i <= len;++i){
        int m_t = 0;int i_t = 0;
        for(int j = 0;j <= len;++j){
            if(i == 0 || j == 0) ans[i][j] = 0;
            else{
                if(arr2[j] == arr1[i]){
                    if(arr2[j] > arr2[i_t]){
                        m_t = std::max(ans[i][j],ans[i - 1][j] + 1);
                        i_t = j;
                    }
                }
                // if(arr1[i] == arr2[j]){
                //     for(int k = 0;k < j;++k){
                //         if(arr2[k] < arr2[j])
                //             ans[i][j] = std::max(ans[i][j],1 + ans[i - 1][k]);
                //     }
                // }
                // else ans[i][j] = ans[i - 1][j];
            }
        }
    }
}


int main(){
    std::cin>>len;
    memset(ans,0,sizeof(ans));
    for(int i = 1;i <= len;++i) std::cin>>arr1[i];
    for(int i = 1;i <= len;++i) std::cin>>arr2[i];
    LCIS();
    int t = 0;
    for(int i = 0;i <= len;++i)
        if(ans[len][i] >= t) t = ans[len][i];
    std::cout<<t<<std::endl;    


    return 0;
}