#include <iostream>

class point{
public:
    int _x,_y;  
    point(int x,int y):_x(x),_y(y){};  
};


int DFS(point pos_this,point pos_last,int n){
    if(n == 0 && (pos_last._x == pos_this._x && pos_last._y == pos_this._y)) return 0;
    else if(n != 0 && (pos_last._x == pos_this._x && pos_last._y == pos_this._y))
        return DFS(point(1,0),pos_this,n - 1) + DFS(point(-1,0),pos_this,n - 1) + DFS(point(0,1),pos_this,n - 1);
    if(n == 0) return 1;
    if(pos_this._x == pos_last._x + 1)
        return DFS(point(pos_this._x + 1,pos_this._y),pos_this,n - 1) + DFS(point(pos_this._x,pos_this._y + 1),pos_this,n - 1);
    if(pos_this._x == pos_last._x - 1)
        return DFS(point(pos_this._x - 1,pos_this._y),pos_this,n - 1) + DFS(point(pos_this._x,pos_this._y + 1),pos_this,n - 1);
    if(pos_this._y == pos_last._y + 1)
        return DFS(point(pos_this._x,pos_this._y + 1),pos_this,n - 1) + DFS(point(pos_this._x + 1,pos_this._y),pos_this,n - 1) + DFS(point(pos_this._x - 1,pos_this._y),pos_this,n - 1);        
}


int main(){
    int n;
    std::cin>>n;
    std::cout<<DFS(point(0,0),point(0,0),n)<<std::endl;


    return 0;
}