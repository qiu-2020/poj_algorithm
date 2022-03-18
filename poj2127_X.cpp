#include <iostream>

const int MAX = 510;
int A[MAX],B[MAX];
int ans[MAX][MAX];
int len1,len2;

int main(){
    std::cin>>len1;
    for(int i = 0;i < len1;++i)
        std::cin>>A[i];
    // std::cin>>len2;
    len2 = len1;
    for(int i = 0;i < len2;++i)
        std::cin>>B[i]; 

    for(int i = 0;i < len2;++i){
        if(A[0] == B[i]) ans[0][i] = 1;
        else 
            if(i != 0)
                ans[0][i] = ans[0][i - 1];
            else 
                ans[0][i] = 0;      
    }

    for(int i = 0;i < len1;++i){
        if(B[0] == A[i]) ans[i][0] = 1;
        else 
            if(i != 0)
                ans[i][0] = ans[i - 1][0];
            else 
                ans[i][0] = 0;      
    }
// ans[i][j] = std::max(ans[i][j - 1],ans[][])


    for(int i = 1;i < len1;++i){ // A
        for(int j = 1;j < len2;++j){ // B
            if(A[i] == B[j]){
                ans[i][j] = ans[i][j - 1];
                for(int k = j - 1;k >= 0;--k){
                    if(B[k] < B[j])
                        ans[i][j] = std::max(ans[i][j],ans[i][k] + 1);
                }
            }
            else ans[i][j] = std::max(ans[i][j - 1],ans[i - 1][j]);
        }
    }
    std::cout<<ans[len1 - 1][len2 - 1]<<std::endl;

    return 0;
}