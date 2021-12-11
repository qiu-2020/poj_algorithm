#include <iostream>

const int MAX = 10010;
int len;
int a[MAX] = {0};
int b[MAX] = {0};

int LCIS(int i1,int i2,int last){ //以i1，i2为结尾的最长公共子序列
    if(i1 == 0 || i2 == 0)
        if(a[i1] == b[i2] && a[i1] <= last) return 1;
        else return 0;
    else{
        int tmp = std::max(LCIS(i1 - 1,i2,last),LCIS(i1,i2 - 1,last));
        if(a[i1] == b[i2] && a[i1] <= last)
            return std::max(tmp,1 + LCIS(i1 - 1,i2 - 1,a[i1]));
        else return std::max(tmp,LCIS(i1 - 1,i2 - 1,last));;    
    }    

}

void LCIS_dp(void){
    
}


// int tmp = 0;
// if(last1 == len)
//     tmp = std::max(LCIS(i1 - 1,i2,last1),LCIS(i1,i2 - 1,last1));  
// if(a[i1] == b[i2])
//     return std::max(1 + LCIS(i1 - 1,i2 - 1,i1),tmp);
// else return tmp;


int main(){
    int l1,l2;
    std::cin>>l1>>l2;
    for(int i = 0;i < l1;++i) std::cin>>a[i];
    for(int i = 0;i < l2;++i) std::cin>>b[i];
    len = std::max(l1,l2);
    std::cout<<LCIS(l1 - 1,l2 - 1,10000)<<std::endl;
    return 0;
}