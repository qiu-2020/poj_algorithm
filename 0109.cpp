#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class IntegralImage{
// 在此处补充你的代码
private:
    int _H,_W,_ptr_row;
    int** _ans;
public:
    IntegralImage(int h,int w):_H(h),_W(w),_ptr_row(0){
        _ans = new int* [h];
        for(int i = 0;i < h;++i){
            _ans[i] = new int [w];
        }
    }

    void operator()(int* ptr_row){
        int sum_pre = 0;
        if(_ptr_row == 0){
            sum_pre = ptr_row[0];
            _ans[_ptr_row][0] = sum_pre;
            for(int i = 1;i < _W;++i){
                sum_pre += ptr_row[i];
                _ans[_ptr_row][i] = sum_pre;
            }
            _ptr_row++;
        }
        else{
            sum_pre = ptr_row[0];
            _ans[_ptr_row][0] = _ans[_ptr_row - 1][0] + sum_pre;
            for(int i = 1;i < _W;++i){
                sum_pre += ptr_row[i];
                _ans[_ptr_row][i] = sum_pre + _ans[_ptr_row - 1][i];
            }
            _ptr_row++;
        }    
    }
    int* operator[](int i){
        return _ans[i];
    }

};
int main(){
    int H, W;
    cin >> H >> W;
    int ** image = new int*[H];
    for(int i=0;i<H;++i){
        image[i]=new int[W];
    }
    for(int i=0;i<H;++i)
    for(int j=0;j<W;++j)
        cin >> image[i][j];
    IntegralImage it(H,W);
    for_each(image, image+H, it);
    for(int i=0;i<H;++i){
        for(int j=0;j<W;++j)
            cout<<it[i][j]<<" ";
        cout<<endl;
    }
   
}
