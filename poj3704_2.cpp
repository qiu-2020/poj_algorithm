#include <iostream>
#include <cstring>

char str[110];
bool ans[110];
int length;
// ((()
int mark_bracket(int last_left,int this_index){
    if(this_index == length) return length;
    if(str[this_index] == '('){
        int r = mark_bracket(this_index,this_index + 1);
        if(r != length)
            return mark_bracket(last_left,r);
    }
    else if(str[this_index] == ')'){
        if(last_left != -1){
            ans[last_left] = true;
            ans[this_index] = true;
            return this_index + 1;
        }
        else
            return mark_bracket(last_left,this_index + 1);
    }
    else return mark_bracket(last_left,this_index + 1);
}


int main(){
    while(std::cin>>str){
        memset(ans,0,sizeof(ans));
        length = strlen(str);
        mark_bracket(-1,0);
        for(int i = 0;i < length;++i){
            if(!ans[i] && str[i] == '(')
                std::cout<<'$';
            else if(!ans[i] && str[i] == ')')
                std::cout<<'?';
            else if(str[i] != '(' && str[i] != ')' || ans[i])
                std::cout<<' ';
        }
        std::cout<<std::endl;
    }
    return 0;
}