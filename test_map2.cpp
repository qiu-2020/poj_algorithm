#include <iostream>
#include <map>
using namespace std;

int main(){
    map<char,int> m;
    m['a'] ++;
    m['a'] ++;
    std::cout<<m['a']<<std::endl;

    return 0;
}