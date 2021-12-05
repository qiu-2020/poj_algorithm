#include <iostream>

int row,n_total;
int row_len[10],row_max_len[10];

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




int arrange(void){// n判断是否都摆完了，剩几个人。

}

            // if(i == 0 && row_max_len[i] > row_len[i]){
            //     ++row_len[i];
            //     count += arrange(n + 1);
            // }


int main(){
    while(std::cin>>row && row != 0){
        n_total = 0;
        for(int i = 0;i < row;i++){ 
            std::cin>>row_max_len[i];
            row_len[i] = 0;
        }    
        std::cout<<arrange(0)<<std::endl;
    }
    return 0;
}