#include <iostream>

const int MAX = 110;
int h[MAX][MAX];
int row,col;

class Point{
public:
    int r,c,h;
    bool operator<(const Point& p){
        return h < p.h;
    } 
};

Point[MAX * MAX];

int main(){
//    int row,col;
    std::cin>>row>>col;
    for(int i = 0;i < row;++i){
        for(int j = 0;j < col;++j)
            std::cin>>h[i][j];

    }



    return 0;
}
