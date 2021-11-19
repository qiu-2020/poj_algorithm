#include <iostream>

int R,C;
short ski_field[102][102] = {0};
short len_ans[102][102] = {0};

void ski(int r,int c,int h){
    if(h >= ski_field[r + 1][c] && h >= ski_field[r - 1][c] && h >= ski_field[r][c + 1] && h >= ski_field[r][c - 1])
        return;
    else{            
        if(h < ski_field[r + 1][c])
            if(1 + len_ans[r][c] > len_ans[r + 1][c]){
                len_ans[r + 1][c] = 1 + len_ans[r][c];
                ski(r+1,c,ski_field[r+1][c]);
            }    
        if(h < ski_field[r - 1][c])
            if(1 + len_ans[r][c] > len_ans[r - 1][c]){
                len_ans[r - 1][c] = 1 + len_ans[r][c];
                ski(r-1,c,ski_field[r-1][c]);
            }   
        if(h < ski_field[r][c + 1])
            if(1 + len_ans[r][c] > len_ans[r][c + 1]){
                len_ans[r][c + 1] = 1 + len_ans[r][c];
                ski(r,c + 1,ski_field[r][c + 1]);
            }
        if(h < ski_field[r][c - 1])
            if(1 + len_ans[r][c] > len_ans[r ][c - 1]){
                len_ans[r][c - 1] = 1 + len_ans[r][c];
                ski(r,c - 1,ski_field[r][c - 1]);
            }            
    }    
}


int main(){

    std::cin>>R>>C;

    for(int i = 1;i <= R;i++){
        for(int j = 1;j <= C;j++){
            std::cin>>ski_field[i][j];
            if(i == 1 ||j ==1 || i==C||j==R)
                len_ans[i][j] = 1;
        }    
    }
    for(int i = 0;i <= R + 1;i++){
        ski_field[i][0] = 0;
        len_ans[i][0] = 0;
        ski_field[i][C+1] = 0;
        len_ans[i][C+1] = 0;
    }
    for(int i = 0;i <=  C + 1;i++){
        ski_field[0][i] = 0;
        len_ans[0][i] = 0;
        ski_field[R+1][i] = 0;
        len_ans[R+1][i] = 0;
    }
    

    // for(int i = 1;i <= R;i++){
    //     ski(i,1,ski_field[i][1]);
    //     ski(i,C,ski_field[i][C]);
    // }
    // for(int i = 1;i <= C;i++){
    //     ski(1,i,ski_field[1][i]);
    //     ski(i,1,ski_field[i][1]);
    // }
    for(int i = 1;i <= R;i++){
        for(int j = 1;j <= C;j++){
            ski(i,j,ski_field[i][j]);
        }
    }
    int max = 0;
    for(int i = 1;i <= R;i++){
        for(int j = 1;j <= C;j++){
            if(len_ans[i][j] >= max)
                max = len_ans[i][j];
        }
    }
    std::cout<<max<<std::endl;
    return 0;
}