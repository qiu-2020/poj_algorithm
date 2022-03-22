#include <iostream>

int flag[15][15],m,n,ans;
bool visited[15][15];
bool all_visited(){
    for(int i = 0;i < m;++i){
        for(int j = 0;j < n;++j)
            if(!visited[i][j])
                return false;
    }
    return true;
}

void count(int x,int y,int num){
    if(num == 0){
        ans++;
        return;
    }
    // if(x + 2 <= n - 1 && y + 2 <= m - 1 && !visited[x + 2][y + 2])
    //     count(x + 2,y + 2,num - 1);
    // if(x + 2 <= n - 1 && y - 2 >= )    
}

int main(){
    int T;
    int x,y;
    std::cin>>T;
    while(T--){
        std::cin>>m>>n>>x>>y;
        ans = 0;
        visited[x][y] = true;

    }

    return 0;
}