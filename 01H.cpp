#include <iostream>

std::string s1,s2;

int distance(std::string s1,std::string s2){
    if(s1.length() == 0 || s2.length() == 0){
        if(s1.length() == 0 && s2.length() == 0)
            return 0;
        else if(s1.length() == 0) return s2.length();
        else return s1.length();
    }
    else{
        if(s1[0] == s2[0]) return distance(s1.substr(1),s2.substr(1));
        // else return std::min(distance(s1.substr(1),s2) + 1,distance(s1,s2.substr(1)) + 1);
        else{
            int d_f = std::min(distance(s1.substr(1),s2) + 1,distance(s1,s2.substr(1)) + 1);
            return std::min(d_f,distance(s1.substr(1),s2.substr(1)) + 1);
        }    
    }
}

int ans[1010][1010];
int len1,len2;

void distance_dp(void){
    ans[len2][len1] = 0;
    for(int i = 0;i < len2;++i)
        ans[i][len1] = len2 - i;
    for(int i = 0;i < len1;++i)
        ans[len2][i] = len1 - i;
    for(int i = len2 - 1;i >= 0;--i){// row
        for(int j = len1 - 1;j >= 0;--j){
            if(s2[i] == s1[j])
                ans[i][j] = ans[i + 1][j + 1];
            else{    
                int min_tmp = std::min(ans[i + 1][j] + 1,ans[i][j + 1] + 1);
                ans[i][j] = std::min(min_tmp,ans[i + 1][j + 1] + 1);
            }
        }
    }
}

int main(){
    int n;
    std::cin>>n;
    // distance_dp();
    for(int i = 0;i < n;++i){
        std::cin>>s1>>s2;
        len1 = s1.length(); len2 = s2.length();
        distance_dp();
        std::cout<<ans[0][0]<<std::endl;
        // std::cout<<distance(s1,s2)<<std::endl;
    }


    return 0;
}