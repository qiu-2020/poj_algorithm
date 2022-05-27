#include <iostream>

class Int{
private:
    int val;
public:
    Int(int v):val(v){}
    int get_val(){
        return val;
    }
    friend std::ostream& operator<<(std::ostream& os,Int i){
        os<<i.get_val();
        return os;
    }
    Int operator*(int x){
        return Int(get_val() * x);
    }
};

int main(){
    Int x = Int(3);
    std::cout<<x * 9<<std::endl;


    return 0;
}