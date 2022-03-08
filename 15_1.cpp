#include <iostream>
#include <cstring>

int p[110],n;
int ans[110];
int max_p(int l){
    if(l == 0) return 0;
    int tmp = 0;
    for(int i = 1;i <= l;++i){
        if(p[i] + max_p(l - i) > tmp)
            tmp = p[i] + max_p(l - i);
    }
    return tmp;
}

int max_p_1(int l){
    if(l == 0){
        ans[0] = 0;
        return 0;
    }
    int tmp = 0;
    for(int i = 1;i <= l;++i){
        if(max_p_1(l - i) != -1){
            if(p[i] + ans[l - i] > tmp)
                tmp = p[i] + ans[l - i];
        }
        else{
            if(p[i] + max_p_1(l - i) > tmp)
                tmp = p[i] + max_p_1(l - i);
        }            

    }
    ans[l] = tmp;
    return tmp;
}

int max_dp(int l){
    for(int i = 1;i <= l;++i){//枚举长度
        // int ans[i] = 0;
        for(int j = i;j >= 0;--j){
            ans[i] = std::max(ans[i],ans[j] + p[i - j]);
        }
    }
    return ans[l];

}


int main(){
//    int n;
    int l;
    std::cin>>n>>l;
    for(int i = 1;i <= n;++i)
        std::cin>>p[i];
    memset(ans,0,sizeof(ans));    
    std::cout<<max_dp(l)<<std::endl;

    return 0;
}