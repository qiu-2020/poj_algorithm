#include <iostream>
#include <cstring>




int main(){
    int a[3][4][5];
    // for(int i = 0;i < 3;++i)
    memset(a,0xff,sizeof(a));
    std::cout<<*a[5][1]<<std::endl;

}