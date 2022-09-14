#include <iostream>
#include <string>

std::string s,p;
bool pattern(int s_i,int p_i){
    // if(s_i == s.length() - 1 || p_i == p.length() - 1){
    //     if(p[p_i] == s[s_i]) return true;
    //     else if(p[p_i] == '?' && s_i < s.length()) return true;
    //     else if(p[p_i] == '*')
    // }

    if(s_i == s.length() - 1 && p_i < p.length() - 1 || s_i < s.length() - 1 && p_i == p.length() - 1){
        if(p_i == p.length() - 1 && p[p_i] == '*') return true;
        else if(p_i == p.length() - 1 && p[p_i] == '?' && s.length() - 1 == s_i) return true;
        else return false; 
    }
    //长度不一致,至少有一个到了末尾
    else if(s_i == s.length() - 1 && p.length() - 1){
        //都到达了末尾
        if(p[p_i] == s[s_i]) return true;
        else if(p[p_i] == '?' || p[p_i] == '*') return true;
        else return false;
    }
    else{
        //均没有到最后一个字符，递归调用
        if(p[p_i] == '?')
            //匹配一个
            return pattern(s_i + 1,p_i + 1);
        else if(p[p_i] == '*'){
            //*可以选择不匹配、匹配一个或者匹配多个
            return pattern(s_i,p_i + 1) || pattern(s_i + 1,p_i + 1) || pattern(s_i + 1,p_i);
        } 
        else{
            if(p[p_i] == s[s_i]) return pattern(s_i + 1,p_i + 1);
            else return false;
        }
    }
}

int main(){
    int n;
    std::cin>>n;
    // std::string s,p;
    for(int i = 0;i < n;++i){
        std::cin>>s>>p;
        if(pattern(0,0)) std::cout<<"yes"<<std::endl;
        else std::cout<<"no"<<std::endl;
    }

    return 0;
}