#include <iostream>
#include <cmath>

char ans[1050][1050];
int total_deep;

std::string get_blank(int n){
    std::string str = "";
    for(int i = 0;i < n;++i)
        str += ' ';
    return str;    
}

void get_triangle(int x,int y,int level){
    int len = 1 << (level - 1);
    for(int i = 0;i < )
}

int main(){
    for(int i = 0;i < 3;++i)
        get_triangle();
    return 0;
}