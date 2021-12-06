#include <iostream>

char room[100][100];

void infection(int d){

}

int main(){
    int n,days;
    std::cin>>n;
    for(int i = 0;i < n;++i){
        for(int j = 0;j < n;++j)
            std::cin>>room[i][j];
    }
    std::cin>>days;
    for(int d = 1;d < days;++d){
        for(int i = 0;i < n;++i){
            for(int j = 0;j < n;++j){ 
                if(i - 1 >= 0)
                    if(room[i - 1][j] == '@' && room[i][j] == '.')
                        room[i][j] = '*';
                if(j - 1 >= 0)
                    if(room[i][j - 1] == '@' && room[i][j] == '.')
                        room[i][j] = '*';
                if(i + 1 < n)
                    if(room[i + 1][j] == '@' && room[i][j] == '.')
                        room[i][j] = '*';
                if(j + 1 < n)
                    if(room[i][j + 1] == '@' && room[i][j] == '.')
                        room[i][j]='*';                                        
            }
        }
        for(int t_i = 0;t_i < n;t_i++){
            for(int t_j = 0;t_j < n;t_j++){
                if(room[t_i][t_j] == '*')
                    room[t_i][t_j] = '@';
            }
        }
    }
    int count = 0;
    for(int i = 0;i < n;++i){
        for(int j = 0;j < n;++j){
            if(room[i][j] == '@')
                count++;
        }
    }
    std::cout<<count<<std::endl;


    return 0;
}