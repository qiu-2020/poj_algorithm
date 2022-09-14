#include <iostream>
#include <vector>


int a[100010],n;
int max_profit;


void cal_profit(int i,int last,int this_profit,int count){
    if(i == n - 1 || count == 2){
        if(last != -1 && i == n - 1)
            this_profit += a[i] - a[last];
        if(this_profit > max_profit)
            max_profit = this_profit;    
        return;
    }

    if(last == -1){
        cal_profit(i + 1,last,this_profit,count);
        cal_profit(i + 1,i,this_profit,count);
    }
    else{
        cal_profit(i + 1,-1,this_profit + a[i] - a[last],count + 1);
        cal_profit(i + 1,last,this_profit,count);
    }
}

int ans_e[100010],ans_s[100010];

int profit_dp1(){
    ans_e[0] = 0;
    int mi = 0x3f3f3f3f,ma = -mi;
    mi = std::min(a[0],mi);
    for(int i = 1;i < n;++i){
        mi = std::min(mi,a[i]);
        ans_e[i] = std::max(ans_e[i - 1],a[i] - mi);
    }
    ans_s[n - 1] = 0;
    ma = std::max(ma,a[n - 1]);
    for(int i = n - 2;i >= 0;--i){
        ma = std::max(ma,a[i]);
        ans_s[i] = std::max(ans_s[i + 1],ma - a[i]);
    }
    int ans = 0;
    for(int i = 0;i < n - 1;++i){
        ans = std::max(ans,ans_s[i] + ans_e[i]);
    }
    return ans;
}


int main(){
    int N;
    std::cin>>N;
    for(int i = 0;i < N;++i){
        // std::cin>>n;
        scanf("%d",&n);
        max_profit = 0;
        for(int j = 0;j < n;++j)
            // std::cin>>a[j];
            scanf("%d",&a[j]);
        // cal_profit(0,-1,0,0);
        // std::cout<<max_profit<<std::endl;  
        printf("%d\n",profit_dp1());  
    }        
    return 0;
}