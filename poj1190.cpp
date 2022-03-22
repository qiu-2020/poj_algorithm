#include <iostream>
#include <cmath>
int N,M;
double minArea,area;
double minL[25];

void DFS(int v_remain,int l_remain,int r,int h){
    if(v_remain == 0 && l_remain == 0){
        if(area < minArea){
            minArea = area;
        }
    }
    if((v_remain != 0 && l_remain == 0) || (v_remain == 0 && l_remain != 0))
        return ;

    if(v_remain > r * r * h) return;
    if(minL[M - l_remain] < v_remain) return;
    else minL[r][l_remain] = v_remain;

    for(int rr = r;rr > l_remain;--rr){
        if(l_remain == M) area += rr * rr;
        for(int hh = h;hh > l_remain;--h){
            area += 2 * hh * rr;
            DFS(v_remain - rr * rr * hh,l_remain - 1,rr - 1,hh - 1);
            area -= 2 *hh *rr;
        }
    }
}

int main(){
    std::cin>>N>>M;
    DFS(N,M,sqrt(N),N);
    std::cout<<minArea<<std::endl;
    return 0;
}