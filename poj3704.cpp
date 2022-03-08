#include <iostream>
#include <cstring>

const int MAX = 110;
char str[MAX];
bool flag[MAX];
int len = 0;

int mark_bracket(int last,int i){
    if(i >= len){
        return len;
    }
    if(str[i] == '('){
        int r = mark_bracket(i,i + 1);
        return mark_bracket(last,r);
    }
    else if(str[i] == ')'){
        if(last == -1) return mark_bracket(last,i + 1);
        else{
            flag[last] = true;
            flag[i] = true;
            return i + 1;
        }
    }
    else return mark_bracket(last,i + 1);
}

int main(){ 
    while(std::cin>>str){
        memset(flag,0,sizeof(flag));
        len = strlen(str);
        mark_bracket(-1,0);
        std::cout<<str<<std::endl;
        for(int i = 0;i < len;++i)
            if(str[i] == '(' && !flag[i])
                std::cout<<'$';
            else if(str[i] == ')' && !flag[i])
                std::cout<<'?';
            else std::cout<<' ';
        std::cout<<std::endl;         
    }
    return 0;
}