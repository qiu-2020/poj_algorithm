#include <iostream>
#include <stack>
#include <cstring>
char ans[110];

int main(){
    std::string str;
    while(std::cin>>str){
        std::stack<char> s;  
        memset(ans,' ',sizeof(ans));
        for(int i = 0;i < str.length();++i){
            if(str[i] == '('){
                s.push(i);
            }
            else if(str[i] == ')'){
                if(s.empty()) ans[i] = '?';
                else s.pop();
            }
            else continue;
        }
        while(!s.empty()){
            ans[s.top()] = '$';
            s.pop();
        }    
        ans[str.length()] = '\0';
        std::cout<<str<<std::endl;
        std::cout<<ans<<std::endl;        
    }



    return 0;
}