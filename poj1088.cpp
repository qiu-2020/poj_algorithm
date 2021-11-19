#include <iostream>
#include <algorithm>


int len_ans[110][110];
int field[110][110];
int R,C;
int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

class point{
public:
    int h,r,c;
    bool operator<(const point p){
        return h < p.h;
    }
}
p[10010];

void sking(void){
    std::sort(p,p + R * C);
    for(int i = 0;i < R * C;i++){
        for(int j = 0;j < 4;j++){
            if(p[i].r == 0 && j == 1 || p[i].r == R - 1 && j == 0 || p[i].c == 0 && j == 3 || p[i].c == C - 1 && j == 2) continue;
            if(field[p[i].r + dir[j][0]][p[i].c + dir[j][1]] > p[i].h){
                len_ans[p[i].r + dir[j][0]][p[i].c + dir[j][1]] = std::max(len_ans[p[i].r][p[i].c] + 1,len_ans[p[i].r + dir[j][0]][p[i].c + dir[j][1]]);
            }
        }
    }
}

int main(){
    std::cin>>R>>C;
    for(int i = 0;i < R;i++){
        for(int j = 0;j < C;j++){
            std::cin>>field[i][j];
            len_ans[i][j] = 1;
            p[i * C + j].h = field[i][j];
            p[i * C + j].r = i;
            p[i * C + j].c = j;
        }
    }
    sking();
    int ans = 1;
    for(int i = 0;i < R;i++){
        for(int j = 0;j < C;j++){
            if(len_ans[i][j] > ans)
                ans = len_ans[i][j];
        }
    }
    std::cout<<ans<<std::endl;

    return 0;
}