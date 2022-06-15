#include <iostream>
#include <cmath>


int main(){
    int N;
    std::cin>>N;
    int edge_len = sqrt(N);
    int remainer = N - edge_len * edge_len;
    int count = edge_len * edge_len * 2 + 4 * edge_len;




    return 0;
}