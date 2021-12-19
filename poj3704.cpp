#include <iostream>
#include <cstring>

const int MAX = 110;

char str[MAX];
char str_bracket[MAX];
char ans[MAX];
bool flag[MAX];
int len;

int label_s(int last_l,int i){//标注能配对的
    if(i >= len) return len;//没找到与上个'('配对的
    else{
        if(str_bracket[i] == '(' && last_l == -1){
            int next = label_s(i,i + 1);
            if(next >= len) return len;
            else return label_s(last_l,next);
        }
        else if(str_bracket[i] == ')' && last_l != -1){
            flag[i] = true; flag[last_l] = true;
            return i + 1;
        }
        else if(str_bracket[i] == '(' && last_l != -1){
            int next = label_s(i,i+1);
            if(next >= len) return len;
            else return label_s(last_l,next);
        }
        else{
            return label_s(last_l,i + 1);
        }
    }
}

int main(){ 

    while(std::cin>>str_bracket){
        len = strlen(str_bracket);
        memset(flag,0,sizeof(flag));
        memset(ans,0,sizeof(ans));
        label_s(-1,0);
        for(int i = 0;i < len;++i){
            if(str_bracket[i] == '(' && flag[i] == false) ans[i] = '$';
            else if(str_bracket[i] == ')' && flag[i] == false) ans[i] = '?';
            else ans[i] = ' ';
        }
        ans[strlen(ans)] = 0;
        std::cout<<str_bracket<<std::endl;
        std::cout<<ans<<std::endl;
        // for(int i = 0;i < strlen(str);++i)
        //     if(str[i] == '(' || str[i] == ')')
        //         str_bracket[j++] = str[i];
        // str_bracket[j] = '0';
        // len = strlen(str_bracket);        
        // label_s(-1,0); j = 0;
        // for(int i = 0;i < strlen(str);++i){
        //     std::cout<<str[i];
        //     ans[i] = ' ';
        //     if(str[i] == '(' && !flag[j++]){
        //         ans[i] = '$';
        //     }
        //     else if(str[i] == ')' && !flag[j++]){
        //         ans[i] = '?';
        //     }
        // }
    }

    return 0;
}