#include <iostream>

// template<typename T>
// class minor{
// public:
//     // minor(const T& a,const T& b){

//     // }
//     bool operator()(const T& a,const T& b){
//         if(a < b) return true;
//         else return false;
//     }
// };


template <typename T>
T minor(const T& a,const T& b){
    return a < b ? a : b;
};



int main(){
    int a_i,b_i;
    float a_f,b_f;
    std::cin>>a_i>>b_i;
    std::cout<<minor(a_i,b_i)<<std::endl;
    std::cin>>a_f>>b_f;
    std::cout<<minor(a_f,b_f)<<std::endl;


    return 0;
}