#include <iostream>
#include <cstring>

const int MAX = 1000;
int ans[MAX][MAX];
char str1[MAX],str2[MAX];

int main(){
//    int len1 = strlen(str1),len2 =strlen(str2);
    while(std::cin>>str1>>str2){
        for(int len1 = 0;len1 <= strlen(str1);len1++)
            ans[len1][0] = 0;
        for(int len2 = 0;len2 <= strlen(str2);len2++)
            ans[0][len2] = 0;

        for(int i = 1;i <= strlen(str1);i++){
            for(int j = 1;j <= strlen(str2);j++){
                if(str1[i - 1] == str2[j - 1])
                    ans[i][j] = 1 + ans[i - 1][j - 1];
                else
                    ans[i][j] = std::max(ans[i - 1][j],ans[i][j - 1]);    
            }
        }
        std::cout<<ans[strlen(str1)][strlen(str2)]<<std::endl;        
    }
    // std::cout<<'0'<<std::endl;


    return 0;
}