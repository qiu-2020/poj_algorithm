#include <iostream>

int a[1010];
int ans[1010],N,ans_m;

void maxlen_dp(){
    ans_m = a[0];
    for(int i = 1;i < N;++i){
        for(int j = i - 1;j >= 0;--j){
            if(a[j] < a[i])
                ans[i] = std::max(ans[j] + a[i],ans[i]);    
            if(ans_m < ans[i]) 
                ans_m = ans[i];   
        }
    }
}


// void max_len(int i,int last){
//     if(i == 0)
//         this_sum = 0;    
//     if(i == N){
//         if(this_sum > ans)
//             ans = this_sum;
//         return;    
//     }
//     if(last == -1){
//         this_sum += a[i];
//         max_len(i + 1,i);
//         this_sum -= a[i];
//         max_len(i + 1,last);
//     }
//     else{
//         if(a[i] > a[last]){
//             this_sum += a[i];
//             max_len(i + 1,i);
//             this_sum -= a[i];
//             max_len(i + 1,last);
//         }
//         else{
//             max_len(i + 1,last);
//         }
//     }
// }

int main(){
    std::cin>>N;
    for(int i = 0;i < N;++i){
        std::cin>>a[i];
        ans[i] = a[i];
    }    
    // max_len(0,-1);  
    maxlen_dp();  
    std::cout<<ans_m<<std::endl;


    return 0;
}