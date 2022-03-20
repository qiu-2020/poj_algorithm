#include <iostream>

const int MAX = 3010;
int A[MAX],B[MAX];
int ans[MAX][MAX];
// int status_exchange[MAX][MAX];
int len1,len2;

int main(){
    std::cin>>len1;
    for(int i = 0;i < len1;++i)
        std::cin>>A[i];
    // std::cin>>len2;
    len2 = len1;
    for(int i = 0;i < len2;++i)
        std::cin>>B[i]; 
    for(int i = 0;i < len1;++i)
        if(A[i] == B[0]) ans[i][0] = 1;
        else ans[i][0] = 0;    
    for(int i = 0;i < len2;++i)
        if(A[0] == B[i]) ans[0][i] = 1;
        else ans[0][i] = 0;
    for(int i = 1;i < len1;++i){
        for(int j = 1;j < len2;++j){
            if(A[i] == B[j]){
                ans[i][j] = ans[i - 1][j];
                for(int k = 0;k < j;++k){
                    if(B[k] < B[j])
                        ans[i][j] = std::max(ans[i][j],ans[i - 1][k] + 1);
                }
            }
            else ans[i][j] = std::max(ans[i - 1][j],ans[i][j - 1]);
        }
    }    
    int tmp = ans[len1 - 1][0];
    for(int i = 1;i < len2;++i)
        if(ans[len1 - 1][i] > tmp)
            tmp = ans[len1 - 1][i];
    std::cout<<tmp<<std::endl;


    return 0;
}