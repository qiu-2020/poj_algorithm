#include <iostream>

//bool num[20];

int ItoA(int n,bool num[]){
    int i = 0;
    while(n != 0){
        if(n % 2 != 0)
            num[i++] = true;
        else num[i++] = false;    
        n /= 2;
    }
    return i;
}//0 - i - 1

//  7 111
//  2(2 + 2(0)) + 2 + 2(0) + 2(0)
// 8 1000
// 2(2(2))

void exchange(int n){
    bool num[20],flag = false;
    int l = ItoA(n,num);
    for(int i = l - 1;i >= 0;--i){
        if(num[i]){
            if(flag) std::cout<<'+';
            flag = true;
            std::cout<<'2';
            if(i == 0) std::cout<<"(0)";
            else if(i == 1)  continue;
            else{
                std::cout<<'(';
                exchange(i);
                std::cout<<')';
            }
        }
    }
}

int main(){
    int n;
    std::cin>>n;
    exchange(n);
    std::cout<<std::endl;

    return 0;
}