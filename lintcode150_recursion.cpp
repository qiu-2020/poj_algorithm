#include <iostream>

int N,P[110];
int tmp_max,ans;

//tmp_max[i][j] ： i表示前i个元素，j表示上次买入的序号,0表示没有买入？

void count(int i,int inhand){
    if(i == N){
        if(tmp_max > ans) ans = tmp_max; 
        return;
    }
    //可以卖出,卖出 或 不卖出
    if(inhand != -1 && P[i] > P[inhand]){
        tmp_max += P[i] - P[inhand];
        count(i + 1,-1);
        tmp_max -= P[i] - P[inhand];
        //不卖出
        count(i + 1,inhand);
    } 
    else{
        //不可以卖出，入手或者不入手
        count(i + 1,inhand);
        count(i + 1,i);
    }   
}

int main(){
    std::cin>>N;
    for(int i = 0;i < N;++i)
        std::cin>>P[i];

    count(0,-1);
    std::cout<<ans<<std::endl;

    return 0;
}