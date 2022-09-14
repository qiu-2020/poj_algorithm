#include <iostream>

int h[110];

int max_down(int n){
    int max_len = 0,this_len = 0,j = 0;
    for(int i = 0;i < n;++i){
        j = i;
        this_len = 0;
        while(h[j % n] > h[(j + 1) % n]){
            this_len++;
            j++;
        }
        if(this_len > max_len)
            max_len = this_len;
    }
    return max_len;

}

int main(){
    int n;
    std::cin>>n;
    for(int i = 0;i < n;++i)
        std::cin>>h[i];

    std::cout<<max_down(n)<<std::endl;

    return 0;
}