#include <iostream>
#include <cstdlib>
#include <cstring>

const int MAX = 350;
bool flag[MAX];

int main(){
    int n,m,count,i1,i2;
    while(std::cin>>n>>m && (m != 0 && n != 0)){
        memset(flag,0,sizeof(flag));
        count = n;i1 = 0,i2 = 1;
        while(count != 1){
            if(!flag[i1]){
                if(i2%m == 0){
                    count--;
                    flag[i1] = true;
                    ++i2;
                    i2 %= m;
                    ++i1;
                    i1 %= n;
                }
                else{
                    ++i1;
                    i1 %= n;
                    ++i2;
                    i2 %= m;
                }
            }
            else{
                ++i1;
                i1 %= n;
            }
        }
        for(int i = 0;i < n;++i){
            if(!flag[i]) std::cout<<i + 1<<std::endl;
        }
    }

    return 0;
}