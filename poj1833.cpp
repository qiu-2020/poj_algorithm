#include <iostream>
#include <algorithm>

const int max = 1050;
int a[max];

void next(int n){
    int i = 0,tmp_i = 0;
    for(i = n - 1;i > 0;--i){
        if(a[i] > a[i - 1]){
            tmp_i = i;
            for(int j = i;j < n;++j)
                if(a[j] < a[tmp_i] && a[j] > a[i - 1])
                //找i之后比a[i - 1]大且最小的
                    tmp_i = j;
            std::swap(a[i - 1],a[tmp_i]);
            break;
        }
    }
    std::sort(a + i,a + n);
}

// 1   2   4   3  ->  1   3   2   4
//         i
//       tmp_i

//   2      3      1  ->  3     1     2
//            

int main(){
    int m,n,k;
    std::cin>>m;
    for(int i = 0;i < m;++i){
        std::cin>>n>>k;
        for(int j = 0;j < n;++j){
            std::cin>>a[j];
        }
        for(int t = 0;t < k;++t)
            next(n);
        for(int j = 0;j < n;++j)
            std::cout<<a[j]<<' ';
        std::cout<<std::endl;    
    }


    return 0;
}