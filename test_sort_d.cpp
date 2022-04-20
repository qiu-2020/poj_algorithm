#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

template <typename T>
class point{
private:
    T _x,_y;
public:
    point(T x,T y):_x(x),_y(y){}
    bool operator<(const point& p){
        if(_x < p._x) return true;
        else if(_x == p._x){
            if(_y < p._y) return true;
            else return false;
        }
        else return false;
    }  
    T get_x() const{
        return _x;
    }
    T get_y() const{
        return _y;
    }
};

template<typename T1,typename T2>
T1 distance(T2 p_1,T2 p_2){
    return sqrt((p_1.get_x() - p_2.get_x()) * (p_1.get_x() - p_2.get_x()) + (p_1.get_y() - p_2.get_y()) * (p_1.get_y() - p_2.get_y()));
}

template <typename T1,typename T2>
class compare{
private:
    T1 _f;
    T2 _p_ori;
public:
    compare(T1 f,T2 p_ori):_f(f),_p_ori(p_ori){}
    bool operator()(const T2& p1,const T2& p2){
        double dis1 = _f(_p_ori,p1);
        double dis2 = _f(_p_ori,p2);
        if(dis1 < dis2) return true;
        else if(dis1 == dis2){
            if(p1.get_x() < p2.get_x()) return true;
            else return false;
        }
        else return false;
    }
};

int main(){
    point<double> p_ori(0.0,0.0);
    std::vector<point<double>> v_p;
    v_p.push_back(point<double>(1,1));
    v_p.push_back(point<double>(99,1));
    v_p.push_back(point<double>(-1,-3));
    v_p.push_back(point<double>(1,0));

    sort(v_p.begin(),v_p.end(),compare<double (*)(const point<double>&,const point<double>&),point<double>>(distance,p_ori));
    std::cout<<":"<<std::endl;

    return 0;
}