#include <iostream>
int N,M;
double minArea,area;

int DFS(int v,int n,int r,int h){
    if(n == 0){
        if(v) return;
        else{
            minArea = std::min(minArea,area); 
            return;
        }
    }
    if(area > minArea) return;
    //剪枝
    if(v < 0) return;
    for(int rr = r;rr >= n;--rr){//半径递减，最高层至少为1
        if(n == M)
            area = rr * rr;
        for(int hh = h;hh >= n;--hh){//高度递减，最高层至少为i
            area += 2 * rr * hh;
            DFS(v - rr * rr * hh,n - 1,rr - 1,hh - 1);
            area -= 2 * rr * hh;
        }    
    }
}

int main(){
    std::cin>>N>>M;


    return 0;
}