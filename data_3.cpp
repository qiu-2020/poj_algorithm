#include <iostream>
#include <cmath>
#include <algorithm>

class Point{
private:
    int _x,_y;
public:
    friend class Triangle;
    Point(int x,int y):_x(x),_y(y){}    
};

class Triangle{
private:
    Point _p1,_p2,_p3;
    float _side1,_side2,_side3;
public:
    Triangle():_p1(0,0),_p2(0,0),_p3(0,0),_side1(0),_side2(0),_side3(0){};
    Triangle(int x1,int y1,int x2,int y2,int x3,int y3):_p1(x1,y1),_p2(x2,y2),_p3(x3,y3){
        // 1,2 1,3 2,3
        _side1 = sqrt((_p1._x - _p2._x) * (_p1._x - _p2._x) + (_p1._y - _p2._y) * (_p1._y - _p2._y));
        _side2 = sqrt((_p1._x - _p3._x) * (_p1._x - _p3._x) + (_p1._y - _p3._y) * (_p1._y - _p3._y));
        _side3 = sqrt((_p2._x - _p3._x) * (_p2._x - _p3._x) + (_p2._y - _p3._y) * (_p2._y - _p3._y));
    }
    bool is_triangel(){
        float side[3] = {_side1,_side2,_side3};
        std::sort(side,side + 3);
        if(side[2] + side[1] <= side[0] || (side[1] - side[0] >= side[2] || side[2] - side[0] >= side[1] || side[2] - side[1] >= side[0])){
            return false;
        }
        else return true;
    }
    float total_length(){
        return _side1 + _side2 + _side3;
    }    
};

int main(){
    int x1,y1,x2,y2,x3,y3;
    std::cin>>x1>>y1>>x2>>y2>>x3>>y3;
    Triangle tri(x1,y1,x2,y2,x3,y3);
    if(tri.is_triangel()) std::cout<<tri.total_length()<<std::endl;
    else std::cout<<"no"<<std::endl;

    return 0;
}