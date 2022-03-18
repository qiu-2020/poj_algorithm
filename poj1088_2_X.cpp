#include <iostream>
#include <algorithm>

const int MAX = 10010;

class point{
public:
    int r,c,h;
    bool operator<(const point& p){
        return h < p.h;
    }    
};
point p[MAX]; //object
int h[110][110];
int ans[MAX],len;

int max_length(void){
    std::sort(p + 1,p + len + 1);
    for(int i = 2;i <= len;++i){
        for(int j = i - 1;j >= 1;--j){
            if(p[i].h > p[j].h){

            }
        }
    }
    int tmp = ans[1];
    for(int i = 1;i <= len;++i)
        if(ans[i] > tmp)
            tmp = ans[i];
    return tmp;        
}

int main(){
    int row,col;
    std::cin>>row>>col;
    for(int i = 1;i <= row;++i){
        for(int j = 1;j <= col;++j){
            std::cin>>h[i][j];
            p[(i - 1) * row + j].r = i;
            p[(i - 1) * row + j].c = j;
            p[(i - 1) * row + j].h = h[i][j];
            ans[(i - 1) * row + j] = 1;
        }    
    }
    len = row * col;
    std::cout<<max_length()<<std::endl;

    return 0;
}