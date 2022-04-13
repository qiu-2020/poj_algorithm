#include <iostream>
#include <cstring>

const int MAX = 210;
char a[MAX],b[MAX];
int ans[MAX][MAX];

int main(){
    while(std::cin>>a>>b){
        int len1 = strlen(a),len2 = strlen(b);
        memset(ans,0,sizeof(ans));
        if(a[0] == b[0]) ans[0][0] = 1;
        for(int i = 1;i < len1;++i){
            if(a[i] == b[0]) ans[0][i] = 1;
            else ans[0][i] = ans[0][i - 1];
        }
        for(int i = 1;i < len2;++i){
            if(b[i] == a[0]) ans[i][0] = 1;
            else ans[i][0] = ans[i - 1][0];
        }      
        for(int i = 1;i < len2;++i){
            for(int j = 1;j < len1;++j){
                if(a[j] == b[i]) ans[i][j] = std::max(ans[i - 1][j - 1] + 1,ans[i - 1][j]);
                else ans[i][j] = std::max(ans[i - 1][j],ans[i][j - 1]);
            }
        }
        std::cout<<ans[len2 - 1][len1 - 1]<<std::endl;
    }


    return 0;
}