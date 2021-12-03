#include <iostream>

int k;
int ans[26][26] = {0};
int a[16] = {0};
int ans_[26] = {0};

int max_len(int i,int last){// i当前考察的数字，j代表上一个选择的数字
    if(i == k){
        if(last != 0)
            if(a[last] >= a[i]) return 1;
            else return 0;
        else{
            return 1;
        }    
    }
    else{
        if(last != 0)
            if(a[last] >= a[i])
                return std::max(1 + max_len(i + 1,i),max_len(i + 1,last));
            else return max_len(i + 1,last);
        else{
            return std::max(1 + max_len(i + 1,i),max_len(i + 1,last));
        }        
    }
}


// int max_len(int e){//以s为终点
//     if(e == k) return 0;
//     else{
//         if(e == 0) return 1;
//         for(int i = e - 1;i >= 0;++i){
//             if(a[i] >= a[e]){
//                 if(ans_[i] + 1 >= ans_[e])
//                     ans_[e] = ans_[i] + 1;
//             }
//         }
//     }
// }

int max_len_dp(void){
    for(int i = 1;i < k;++i){
        for(int j = i - 1;j >= 0;--j){
            if(a[j] >= a[i])
                if(ans_[j] + 1 >= ans_[i])
                    ans_[i] = ans_[j] + 1;
        }
    }
    int tmp = ans_[0];
    for(int i = 0;i < k;++i)
        if(ans_[i] > tmp)
            tmp = ans_[i];
    return tmp;
}

int max_len_recurrent(int);
int max_len_sum(int j,int max_len){
    if(j >= 0){
        if(max_len < max_len_recurrent(j))
            max_len = max_len_recurrent(j);
        max_len_sum(j - 1,max_len);
    }
    else return max_len;
}

int max_len_recurrent(int i){//以i结尾的最长...
    if(i == 0) return 1;
    else{
        int tmp = 0;
        for(int j = i - 1;j >= 0;--j){
            if(a[j] >= a[i]){
                if(max_len_recurrent(j) + 1 > tmp)
                    tmp = max_len_recurrent(j) + 1;
            }
        }
        return tmp;
    }
}

int main(){
    std::cin>>k;
    for(int i = 0;i < k;++i){
        std::cin>>a[i];
        ans_[i] = 1;
    }
    // ans_[0] = 1;
    std::cout<<max_len_sum(k - 1,1)<<std::endl;


    return 0;
}
