#include <iostream>

int H[110][110];
class location{
public:
    
};

int main(){
    int R,C;
    std::cin>>R>>C;
    for(int i = 0;i < R;++i){
        for(int j = 0;j < C;++j)
            std::cin>>H[i][j];
    }

    return 0;
}