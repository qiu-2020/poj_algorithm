#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class MedianFinder {
public:
    priority_queue<double,vector<double>,less<double>> b_head;
    //存A[0,..,n/2 - 1]
    priority_queue<double,vector<double>,greater<double>> s_head;
    //存A[n/2,...,n - 1]
    int n;

    MedianFinder(){
        n = 0;
    }
    
    void addNum(double num) {
        if(n == 0){
            b_head.push(num);
            n++;
        }
        else{
            if((n + 1) % 2){
                if(num < b_head.top()){
                    b_head.push(num);
                    n++;
                }
                else{
                    b_head.push(s_head.top());
                    // s_head.push(b_head.top());
                    s_head.pop();
                    s_head.push(num);
                    ++n;
                }
            }
            else{
                if(!s_head.empty() && num > s_head.top()){
                    s_head.push(num);
                    ++n;
                }
                else if(s_head.empty()){
                    s_head.push(num);
                    ++n;
                } 
                else{
                    s_head.push(b_head.top());
                    b_head.pop();
                    b_head.push(num);
                    ++n;
                }
            }
        }
    }
    
    double findMedian() {
        if(n % 2 == 1)
            return b_head.top();
        else return (s_head.top() + b_head.top()) / 2.0;    
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

int main(){
    MedianFinder a;
    a.addNum(1);
    a.addNum(2);
    std::cout<<a.findMedian()<<std::endl;
    a.addNum(3);
    std::cout<<a.findMedian()<<std::endl;



    return 0;
}