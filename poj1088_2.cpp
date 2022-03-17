#include <iostream>

const int MAX = 10010;

class point{
public:
    int r,c,h;
    bool operator<(const point& p){
        return h < p.h;
    }    
};

point[MAX];

int main(){




    return 0;
}