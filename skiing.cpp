#include <iostream>
#include <algorithm>


int field[110][110];

class point{
public:
    int r,c;
    int h;  
    friend bool operator<(const point& a,const point& b){
        return a.h < b.h;
    }  
};
point p[110 * 110];

int ans[110 * 110];

bool is_adj(point p1,point p2){
    return (p1.r == p2.r + 1)&&(p1.c == p2.c) || (p1.r == p2.r - 1)&&(p1.c == p2.c) || (p1.r == p2.r)&&(p1.c == p2.c + 1) || (p1.r == p2.r) && (p1.c == p2.c - 1);
}

int main(){
    int r,c,count = 0;
    std::cin>>r>>c;
    for(int i = 0;i < r;++i)
        for(int j = 0;j < c;++j){
            std::cin>>field[i][j];
            p[count].r = i;
            p[count].c = j;
            p[count++].h = field[i][j];
        }    
    ans[0] = 1;
    std::sort(p,p + r * c);
    for(int i = 1;i < r * c;++i){
        ans[i] = 1;
        for(int j = 0;j < i;++j){
            if(p[i].h > p[j].h && is_adj(p[i],p[j])){
                ans[i] = std::max(ans[i],ans[j] + 1);
            }
        }
    }
    int m = ans[0];
    for(int i = 0;i < r * c;++i)
        if(ans[i] > m)
            m = ans[i];
    std::cout<<m<<std::endl;

    return 0;
}