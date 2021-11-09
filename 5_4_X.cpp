#include <iostream>
#include <algorithm>

const int MAX = 10000;
int num[MAX];
int cmp(int a,int b){
    return a > b;
}
int MergeSortandCount(int left,int right){
    if(left == right) return 0;
    else{
        int mid = (left + right) / 2;
        int left_tmp = MergeSortandCount(left,mid);
        int right_tmp = MergeSortandCount(mid + 1,right);
        std::sort(num + left,num + mid + 1,cmp); std::sort(num + mid + 1,num + right + 1,cmp);
        int tmp_override = 0;
        for(int i = 0;i <= mid; ++i){
            for(int j = mid + 1;j <= right;++j){
                if(num[i] > num[j]){
                    tmp_override += right - j + 1;
                    break;
                }    
            }
        }
        return left_tmp + right_tmp + tmp_override;
    }
}

int main(){
    int n;
    std::cin>>n;
    for(int i = 0;i < n;i++)
        std::cin>>num[i];
    std::cout<<MergeSortandCount(0,n - 1)<<std::endl;


    return 0;
}