#include <iostream>

int ans[110],N;
std::string str("");

int count(void){
    ans[0] = 1;
    if(str[0] == '1' || str[0] == '2' && (str[1] >= '0' && str[1] <= '6'))
        ans[1] = 2;
    else ans[1] = 1;    
    for(int i = 2;i < N;++i){
        if(str[i - 2] == '1' || str[i - 2] == '2' && (str[i - 1] >= '0' && str[i - 1] <= '6'))
        //可以两个一起编码
            ans[i] = ans[i - 1] + ans[i - 2];
        else ans[i] = ans[i - 1];    
    }
    return ans[N - 1];
}

int main(){
    std::cin>>str;
    N = str.length();
    std::cout<<count()<<std::endl;

    return 0;
}