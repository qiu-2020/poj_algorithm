#include <iostream>
#include <algorithm>

class platform{
public:
    int H;
    int X1;
    int X2;
};

platform p[1010];

bool cmp(platform a,platform b){
    return a.H > a.H;
}

int main(){
    int t,N,X,Y,MAX;
    std::cin>>t;
    for(int i = 0;i < t;i++){
        std::cin>>N>>X>>Y>>MAX;
        for(int j = 0;j < N;j++){
            std::cin>>p[j].X1>>p[j].X2>>p[j].H;
        }
        std::sort(p,p + N,cmp);
        
    }   


    return 0;
}