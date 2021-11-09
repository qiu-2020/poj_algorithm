#include <iostream>

const int MAX = 1000;
int nums[MAX] = {0};
int ans[MAX];
int n = 0;

void max_len(void){
        for(int i = 2;i < n;++i){
            int max_i = 1;
            for(int j = i - 1;j >= 0;--j){
                if(nums[j] < nums[i]){
                    if(ans[j] + 1 >= max_i)
                        max_i = ans[j] + 1;
                }
            }
            ans[i] = max_i;
        }
}

int main(){
//    int n;
    std::cin>>n;

    for(int i = 0;i < n;i++)
        std::cin>>nums[i];
    int tmp = ans[0];
    max_len();
    for(int i = 0;i < n;i++)
        if(ans[i] > tmp)
            tmp = ans[i];
    std::cout<<tmp<<std::endl;        

    return 0;
}