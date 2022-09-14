#include <iostream>
#include <cstring>

int len;
char str[110];
char ans[110];

int mark(int left,int i){
    if(i >= len) return i;
    if(str[i] == '('){
        int r = mark(i,i + 1);
        if(r >= len)
            ans[i] = '$';
        return mark(left,r + 1);
    }
    else if(str[i] == ')'){
        if(left == -1){
            ans[i] = '?';
            return mark(left,i + 1);
        }
        else return i;
    }
    else return mark(left,i + 1);
}

int main(){
    while(std::cin>>str){
        memset(ans,' ',sizeof(ans));
        len = strlen(str);
        mark(-1,0);
        // for(int i = 0;i < len;++i)
        //     std::cout<<str[i];
        ans[len] = 0;
        std::cout<<str<<std::endl;
        // for(int i = 0;i < len;++i)
        //     if(ans[i] == '$' || ans[i] == '?')
        //         std::cout<<ans[i];
        //     else 
        std::cout<<ans<<std::endl;
        // std::cout<<std::endl;                
    }
    return 0;
}