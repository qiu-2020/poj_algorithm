#include <iostream>
#include <iomanip> 
#include <cstring>
using namespace std;
template <class T>
class CArray3D
{
// 在此处补充你的代码
    class CArray2D{
    private:
        T* _ptr;  
		int _row,_col;
	public:
		// CArray2D(int row,int col):_row(row),_col(col){
		// 	_ptr = new T [row * col];
		// }
		CArray2D():_row(0),_col(0){
			_ptr = nullptr;
		}
		CArray2D(T* start_ptr,int row,int col):_ptr(start_ptr),_row(row),_col(col){}
		// ~CArray2D(){
		// 	if(_ptr != nullptr) delete [] _ptr;
		// }
		T* operator[](int row){
			return _ptr + row * _col; 
		}	 
		operator T*(){
			return _ptr;
		} 
    };
private:
    int _layer,_row,_col;
    T* _ptr;
public:
    CArray3D(int l,int r,int c):_layer(l),_row(r),_col(c){
        _ptr = new T [l * r * c];
    }
	CArray3D():_layer(0),_row(0),_col(0){
		_ptr = nullptr;
	}
	~CArray3D(){
		delete [] _ptr;
	}
	CArray2D operator[](int layer){
		return CArray2D(_ptr + layer * _row * _col,_row,_col);
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
    //CArray3D<int> a(3,4,5);
    //CArray3D<double> b(3,2,2);
	int No = 0;
	for( int i = 0; i < 3; ++ i ) {
		a[i];
		for( int j = 0; j < 4; ++j ) {
			a[j][i];
			for( int k = 0; k < 5; ++k )
				a[i][j][k] = No ++;
			a[j][i][i];	
		}
	}
    std::cout<<'!'<<std::endl;
	PrintA();
	memset(a[1],-1 ,20*sizeof(int));	
	memset(a[1],-1 ,20*sizeof(int));
	PrintA(); 
	memset(a[1][1],0 ,5*sizeof(int));	
	PrintA();

	for( int i = 0; i < 3; ++ i )
		for( int j = 0; j < 2; ++j )
			for( int k = 0; k < 2; ++k )
				b[i][j][k] = 10.0/(i+j+k+1);
	PrintB();
	int n = a[0][1][2];
	double f = b[0][1][1];
	cout << "****" << endl;
	cout << n << "," << f << endl;
		
	return 0;
}