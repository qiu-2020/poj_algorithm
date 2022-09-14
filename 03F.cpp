#include <iostream>

int num[10];
int a[10];

bool cal42(int n){
    if(n == 1){
        if(num[0] == 42) return true;
        else return false;
    }
    for(int i = 0;i < n - 1;++i){
        int a1 = num[i] + num[i + 1];
        int a2 = num[i] - num[i + 1];
        int a3 = num[i] * num[i + 1];
        if(num[i] % num[i + 1] == 0)
            int a4 = num[i] / num[i + 1];
        for(int j = i + 2;j < n - 1;++i)
            num[j - 1] = num[j];
        num[i] = a1;    
        bool ans1 = cal42(n - 1);
        num[i] = a2;
        bool ans2 = cal42(n - 1);
        num[i] = a3;
        bool ans3 = cal42(n - 1);
        bool ans4 = false;
        if(num[i] % num[i + 1] == 0)
            ans4 = cal42(n - 1); 
        if(ans1 || ans2 || ans3 || ans4) return true;   
    }

}

int main(){
    int n;
    std::cin>>n;
    for(int i = 0;i < n;++i){
        std::cin>>a[i];
        num[i] = a[i];
    }  
    if(cal42(n))
        std::cout<<"YES"<<std::endl;
    else std::cout<<"NO"<<std::endl;      

    return 0;
}