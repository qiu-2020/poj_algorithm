#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        double p[n];
        for(int i = 0;i < n;++i)
            p[i] = 0.0;
        p[start] = 1.0;
        double tmp[n];
        // for(int i = 0;i < n;++i)
        //     tmp[i] = p[i];
        bool relaxed;
        for(int i = 0;i < edges.size();++i){
            for(int j = 0;j < n;++j)
                tmp[j] = p[j];
            relaxed = false;
            for(int j = 0;j < edges.size();++j){
                if(p[edges[j][1]] < succProb[j] * tmp[edges[j][0]]){
                    p[edges[j][1]] = succProb[j] * tmp[edges[j][0]];
                    relaxed = true;
                }
                if(p[edges[j][0]] < succProb[j] * tmp[edges[j][1]]){
                    p[edges[j][0]] = succProb[j] * tmp[edges[j][1]];
                    relaxed = true;
                }
            }
            if(!relaxed) break;
        }    
        return p[end];
    }
};

int main(){
    vector<vector<int>> e1({{0,1},{1,2},{0,2}}),e2({{0,1},{1,2},{0,2}}),e3({{0,1}});
    vector<double> p1({0.5,0.5,0.2}),p2({0.5,0.5,0.3}),p3({0.5});
    int n1(3),n2(3),n3(3),s1(0),s2(0),s3(0),ed1(2),ed2(2),ed3(2);
    Solution s;
    std::cout<<s.maxProbability(n1,e1,p1,s1,ed1)<<std::endl;
    std::cout<<s.maxProbability(n2,e2,p2,s2,ed2)<<std::endl;
    std::cout<<s.maxProbability(n3,e3,p3,s3,ed3)<<std::endl;
    return 0;
}