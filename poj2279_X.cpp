#include <iostream>
#include <cstring>

int row,n_total;
int row_len[10],row_max_len[10];
bool flag[5][5] = {false};


bool is_initial(void){
    for(int i = 0;i < row;++i){
        if(row_len[i] != 0){
            return false;
        }
    }
    return true;
}

// bool is_full(void){
//     for(int i = 0;i < row;++i){
//         if(row_len[i] != row_max_len[i])
//             return false;
//     }
//     return true;
// }




int arrange(int n){//i := 0~n - 1，摆i号人 。
    if(n == n_total) return 1;
    else{
        int count = 0;
        for(int i = 0;i < row;i++){
            if(i == 0){
                if(row_len[i] < row_max_len[i]){
                    ++row_len[i];
                    count +=  arrange(n + 1);
                    --row_len[i];
                }
            }
            else{
                if(row_len[i] < row_len[i - 1] && row_max_len[i] > row_len[i]){
                    ++row_len[i];
                    count += arrange(n + 1);
                    --row_len[i];
                }
            }    
        }
        return count;
    }
}

int ans[35] = {0};

int arrange_dp(int n){
    if(n == n_total) {
        if(ans[n] != -1)
            return ans[n];
        else{
            ans[n] = 1;
            return ans[n];
        }    
    }
    else{
        int count = 0;
        for(int i = 0;i < row;i++){
            if(i == 0){
                if(row_len[i] < row_max_len[i]){
                    ++row_len[i];
                    if(ans[n + 1] != -1)
                        count += ans[n + 1];
                    else{
                        ans[n + 1] = arrange(n + 1);
                        count += ans[n + 1];
                    }
                    --row_len[i];    
                }
            }
            else{
                if(row_len[i] < row_len[i - 1] && row_max_len[i] > row_len[i]){
                    ++row_len[i];
                    if(ans[n + 1] == -1){
                        ans[n + 1] = arrange(n + 1);
                        count += arrange(n + 1);
                    }
                    else count += ans[n + 1];
                    --row_len[i];
                }
            }
        }
        return count;
    }
}




            // if(i == 0 && row_max_len[i] > row_len[i]){
            //     ++row_len[i];
            //     count += arrange(n + 1);
            // }


int main(){
    while(std::cin>>row && row != 0){
        n_total = 0;
        std::memset(ans,-1,n_total + 1);
        for(int i = 0;i < row;i++){ 
            std::cin>>row_max_len[i];
            row_len[i] = 0;
            n_total += row_max_len[i];
        }    
        std::cout<<arrange_dp(0)<<std::endl;
    }
    return 0;
}