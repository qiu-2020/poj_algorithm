#include <iostream>
#include <cstring>
using namespace std;

// template <typename T>
class Array2 {
// 在此处补充你的代码
private:
    int _row,_col;
    int* _ptr;
public:
    Array2(int r,int c):_row(r),_col(c){
        _ptr = new int [r * c];
    }    
    Array2(){
        _row = 0;_col = 0;
        _ptr = nullptr;
    }
    int* operator[](int r){
        return _ptr + r * _col;
    }
    int operator()(int r,int c){
        return *(_ptr + r * _col + c);
    }
};

int main() {
    Array2 a(3,4);
    int i,j;
    for(  i = 0;i < 3; ++i )
        for(  j = 0; j < 4; j ++ )
            a[i][j] = i * 4 + j;
    for(  i = 0;i < 3; ++i ) {
        for(  j = 0; j < 4; j ++ ) {
            cout << a(i,j) << ",";
        }
        cout << endl;
    }
    cout << "next" << endl;
    Array2 b;     b = a;
    for(  i = 0;i < 3; ++i ) {
        for(  j = 0; j < 4; j ++ ) {
            cout << b[i][j] << ",";
        }
        cout << endl;
    }
    return 0;
}