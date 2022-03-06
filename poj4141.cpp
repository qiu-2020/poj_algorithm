#include <iostream>

const int MAX = 1010;
bool ans[MAX];
//bool isUsed[]
int a[6],count = 0;
int w[6] = {1,2,3,5,10,20};

// bool isUsed(void){
//     for(int i = 0;i < 6;++i){
//         if(a[i] != 0) return false;
//     }
//     return true;
// } 

// void count_weight(){
//     if(isUsed()) return;
//     for(int i = 0;i < 6;++i){
//         if(a[i] != 0){
//             a[i]--;
//             count += w[i];
//             ans[count] = true;
//             count_weight();
//             a[i]++;
//             count -= w[i];
//         }
//     }
// }

void count_mark(int i){//标记到编号为i的砝码
    if(i == 6){
        ans[count] = true;
        return;
    }    
    for(int j = 0;j <= a[i];++j){
    //枚举i号砝码的每种可能的重量
        count += j * w[i];
        count_mark(i + 1);
        count -= j * w[i];
        count_mark(i + 1);   
    }
}

int main(){
    // int count = 0;
    for(int i = 0;i < 6;++i)
        std::cin>>a[i];
    count_mark(0);
    int total = 0;
    for(int i = 1;i <= 1000;++i)
        if(ans[i]) total++;
    std::cout<<"Total="<<total<<std::endl;    

    return 0;
}