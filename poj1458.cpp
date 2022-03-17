#include <iostream>
#include <cstring>

char a[1010],b[1010],m,n;
int ans[1010][1010];


int count_max_common(){
    for(int i = 0;i < m;++i){
        for(int j = 0;j < n;++j){
            if(i == 0 && j == 0){
                if(a[i] == b[j]) ans[i][j] = 1;
                else ans[i][j] = 0; 
                continue;  
            }
            if(i == 0){
                if(b[j] == a[i]) ans[i][j] = 1;
                else ans[i][j] = ans[i][j - 1];
                continue;
            }
            if(j == 0){
                if(b[j] == a[i]) ans[i][j] = 1;
                else ans[i][j] = ans[i - 1][j];
                continue;
            }
            // int tmp = std::max(ans[i - 1][j],ans[i][j - 1]);
            if(a[i] == b[j])
                ans[i][j] = ans[i - 1][j - 1] + 1;
            else ans[i][j] = std::max(ans[i - 1][j],ans[i][j - 1]);    
        }
    }
    return ans[m - 1][n - 1];
}




int main(){
    while(std::cin>>a>>b){
        memset(ans,0,sizeof(ans));
        m = strlen(a),n = strlen(b);
        std::cout<<count_max_common()<<std::endl;
    }
    return 0;
}