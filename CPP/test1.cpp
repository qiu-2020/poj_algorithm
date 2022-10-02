#include <iostream>
#include <cstring>
#include <cmath>
double esp = 1e-6;

int main(){
    double n = 52.63,ans;
    bool flag(false);
    for(int i = 2;i <= 30;++i){
        // if(flag) break;
        for(int j = 1;j < i;++j){
            // if(flag) break;
            ans = double(j) / double(i);
            //0.5263xxxx
            ans += 0.00005;
            ans = (double)((int)(ans * 10000)) / (double)10000;
            if(fabs(ans * 100  - n ) < esp){
            //if(fabs(ans * 100  - n ) < esp){
                std::cout<<j<<'/'<<i<<std::endl;
                // flag = true;
            }    
        }
    }


    return 0;
}