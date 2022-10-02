#include <iostream>
#include <string>

int main(){
    std::string str;
    int k;
    int maxlen_k = 0;
    std::cin>>str>>k;
    int len_l = str.length();
    int tmp = k;
    while(tmp != 0){
        tmp /= 10;
        maxlen_k++;
    }
    int ans = 0;
    for(int i = 0;i < maxlen_k - 1;++i){
        ans += len_l - i;
    }
    // char substr;
    for(int i = 0;i <= len_l - maxlen_k;++i){
        // strcpy()
        if(std::stoi(str.substr(i, maxlen_k)) < k){
            ans++;
        }
    }
    std::cout<<ans<<std::endl;



    return 0;
}