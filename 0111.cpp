#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
template <class T>
class CArray3D
{
// 在此处补充你的代码
    class CArray2D{
        int _row,_col;
        T* _arr_2D;
    public:
        CArray2D():_row(0),_col(0),_arr_2D(nullptr){}
        CArray2D(int r,int c,T* ptr_arr):_row(r),_col(c),_arr_2D(ptr_arr){};
        T* operator[](const int& r){
            return _arr_2D + r * _col;
        }
        operator T*(){
            return _arr_2D;
        }
    };
private:
    int _layer,_row,_col;
    T* _arr_3D;
public:
    CArray3D():_layer(0),_row(0),_col(0),_arr_3D(nullptr){};
    CArray3D(int l,int r,int c):_layer(l),_row(r),_col(c){
        _arr_3D = new T [l * r * c];
    };
    CArray2D operator[](const int& l){
        return CArray2D(_row,_col,_arr_3D + l * _row * _col);
    }
    operator T*(){
        return _arr_3D;
    }

};

CArray3D<int> a(3,4,5);
CArray3D<double> b(3,2,2);
void PrintA()
{
    for(int i = 0;i < 3; ++i) {
        cout << "layer " << i << ":" << endl;
        for(int j = 0; j < 4; ++j) {
            for(int k = 0; k < 5; ++k)
                cout << a[i][j][k] << "," ;
            cout << endl;
        }
    }
}
void PrintB()
{
    for(int i = 0;i < 3; ++i) {
        cout << "layer " << i << ":" << endl;
        for(int j = 0; j < 2; ++j) {
            for(int k = 0; k < 2; ++k)
                cout << b[i][j][k] << "," ;
            cout << endl;
        }
    }
}

int main()
{
    
    int No = 0;
    for( int i = 0; i < 3; ++ i )
        for( int j = 0; j < 4; ++j )
            for( int k = 0; k < 5; ++k )
                a[i][j][k] = No ++;
    PrintA();
    memset(a, -1, 60 * sizeof(int));        //注意这里
    memset(a[1][1], 0, 5 * sizeof(int));
    PrintA();
    
    for( int i = 0; i < 3; ++ i )
        for( int j = 0; j < 2; ++j )
            for( int k = 0; k < 2; ++k )
                b[i][j][k] = 10.0 / (i + j + k + 1);
    PrintB();
    int n = a[0][1][2];
    double f = b[0][1][1];
    cout << "****" << endl;
    cout << n << "," << f << endl;
    
    return 0;
}