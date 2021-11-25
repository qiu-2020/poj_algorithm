#include <iostream>
#include <cstring>

int k;
int a[30];
int ans[35][35];
int missile(int n,int last){//k - 1 ~ n的最长序列
    if(last == 0 && n == k ) return 1;
    else if(last != 0 && n == k ){
        if(a[n] <= a[last]) return 1;
        else return 0;
    }
    else{
        if(last != 0){
            if(a[n] <= a[last])
                return std::max(1 + missile(n + 1,n),missile(n + 1,last));
            else{
                return missile(n + 1,last);
            }    
        }
        else{
            return  std::max(1 + missile(n + 1,n),missile(n + 1,last));
        }
    }
}

void missile_2(int n,int last){
    if(last == 0 && n == k){
        if(ans[n][last] != -1)  return;
        else{
            ans[n][last] = 1;
            return ;
        }
    }
    else if(last != 0 && n == k){
        if(a[n] <= a[last]){
            if(ans[n][last] != -1) return ;
            else{
                ans[n][last] = 1;
                return;
            }
        }
        else{
            ans[n][last] = 0;
        }
    }
    else{
        if(last != 0){
            if(a[n] <= a[last]){
                if(ans[n + 1][n] != -1 && ans[n + 1][last] != -1)
                    ans[n][last] = std::max(1 + ans[n + 1][n],ans[n + 1][last]);
                else{
                    if(ans[n + 1][n] == -1) missile_2(n + 1,n);
                    if(ans[n + 1][last] == -1) missile_2(n + 1,last);
                    ans[n][last] = std::max(1 + ans[n + 1][n],ans[n + 1][last]);
                }    
            }
            else{
                if(ans[n + 1][last] != -1){
                    ans[n][last] = ans[n + 1][last];
                }
                else{
                    missile_2(n + 1,last);
                    ans[n][last] = ans[n + 1][last];
                }    
            }    
        }
        else{
            if(ans[n + 1][n] != -1 && ans[n + 1][last] != -1)
                ans[n][last] = std::max(1 + ans[n + 1][n],ans[n + 1][last]);
            else{
                if(ans[n + 1][n] == -1)
                    missile_2(n + 1,n);
                if(ans[n + 1][last] == -1)
                    missile_2(n + 1,last);
                ans[n][last] = std::max(1 + ans[n + 1][n],ans[n + 1][last]);        
            }    
        }
    }

}

// void missile_3(void){
//     for(int i)
// }   / /  1 4 3 
//       last 
//      0   1   2   3
// n 0    
//   1  2
//   2  2   0
//   3  1   0   1   

int main(){
    std::cin>>k;
    for(int i = 1;i <= k;i++)
        std::cin>>a[i];
    memset(ans,-1,sizeof(ans));    
    missile_2(1,0);
    int tmp = ans[1][0];
    for(int i = 0;i <= k;++i){
        if(tmp < ans[1][i]) tmp = ans[1][i];
    }    
    std::cout<<tmp<<std::endl;

    return 0;
}