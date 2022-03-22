#include <iostream>
#include <cstring>

bool chessboard[10][10];
int tmp[10],ans;
int n,k;

void count(int row,int num){
//摆放第i行    
    if(num > 0 && row == n) return;
    else if(num == 0 || row == n){
        ans++;
        return;
    }
    //在第row行摆放    
    for(int c = 0;c < n;++c){
        if(!chessboard[row][c]) continue;
        if(row == 0){
            tmp[row] = c;
            count(row + 1,num - 1);
            tmp[row] = -1;
        }
        else{
            bool flag = false;
            for(int r = row - 1;r >= 0;--r)
                if(tmp[r] == c){
                    flag = true;
                    break;
                }    
            if(!flag){
                tmp[row] = c;
                count(row + 1,num - 1);
                tmp[row] = -1;
            }
        }
    }
    //不在row行摆放
    count(row + 1,num);    
}

int main(){
    char input_tmp;
    while(std::cin>>n>>k && (n != -1 && k != -1)){
        for(int i = 0;i < n;++i){
            for(int j = 0;j < n;++j){
                std::cin>>input_tmp;
                if(input_tmp == '.') chessboard[i][j] = false;
                else chessboard[i][j] = true;
            }
        }
        // memset(chessboard,0,sizeof(chessboard));
        memset(tmp,0xcf,sizeof(tmp));
        ans = 0;
        count(0,k);
        std::cout<<ans<<std::endl;
    }

    return 0;
}