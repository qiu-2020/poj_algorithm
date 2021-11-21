#include <iostream>
#include <algorithm>


class platform{
public:
    int x,y,h;
    bool operator<(const platform p){
        return h < p.h;
    }
}p[1010];
int N,X,Y,MAX;
int min_time(int x,int h,int n){//某块板的左端还是右端,n是编号
    int h0 = 0; bool flag = false;int pn = 0;
    for(int i = n;i >= 0;--i){
        if(x >= p[i].x && x <= p[i].y){
            h0 = h - p[i].h;
            flag = true;
            pn = i;
            break;
        }    
    }
    if(!flag){//落地
        if(h > MAX) return -1;
        else return h;
    }
    if(h0 > MAX) return -1;
    else{
        int t_l = h0 + std::abs(p[pn].x - x),t_r = h0 + std::abs(p[pn].y - x);
        int left = t_l + min_time(p[pn].x,p[pn].h,pn - 1);
        int right = t_r + min_time(p[pn].y,p[pn].h,pn - 1);
        if(left != -1 && right != -1) return std::min(left,right);
        else{
            if(left != -1) return left;
            else return right;
        }
    }
}

int min_time2(){
    
}

int main(){
    int t;
    std::cin>>t;
    for(int i = 0;i < t;++i){
        std::cin>>N>>X>>Y>>MAX;
        for(int j = 0;j < N;++j){
            std::cin>>p[j].x>>p[j].y>>p[j].h;
        }
        std::sort(p,p + N);
        std::cout<<min_time(X,Y,N - 1)<<std::endl;

    }


    return 0;
}