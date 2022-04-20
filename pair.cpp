#include <iostream>
#include <string>

// template<typename T>
class Pair{
private:
    std::string _s_id;
    double _score; 
public:   
    Pair(std::string str,double s):_s_id(str),_score(s){}
    bool operator<(const Pair& p){
        return _score < p._score;
    }
    
};


int main(){



    return 0;
}