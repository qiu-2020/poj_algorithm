#include <iostream>
#include <algorithm>


int main(){
    int a[10] = {5,4,3,2,1};
    std::sort(a,a+3);
    std::sort(a+3,a+5);
    for(int i = 0;i < 5;i++)
        std::cout<<a[i]<<' ';
    std::cout<<std::endl;    

    return 0;
}