#include <iostream>
#include <algorithm>


int len_ans[110][110];
int field[110][110];
int R,C;

class point{
public:
    int h,r,c;
}
p[100];

void sking(void){
    std::sort(p,p + R * C + 1);

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



    return 0;
}