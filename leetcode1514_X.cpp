#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <utility>

class Solution {
public:
    double maxProbability(int n, std::vector<std::vector<int>>& edges, std::vector<double>& succProb, int start, int end) {
        double dis[n];
        memset(dis,0,sizeof(dis));  
        dis[start] = 1;
        std::vector<std::pair<int,double>> graph[n];
        for(int i = 0;i < edges.size();++i){
            graph[edges[i][0]].push_back(std::make_pair(edges[i][1],succProb[i]));
            graph[edges[i][1]].push_back(std::make_pair(edges[i][0],succProb[i]));
        }
        double max_p = 0;int node_i = start;
        std::priority_queue<std::pair<double,int>> node_queue;
        node_queue.emplace(std::make_pair(1.0,node_i));
        while(!node_queue.empty()){
            std::pair<double,int> node_top = node_queue.top();
            node_i = node_top.second; max_p = node_top.first;
            node_queue.pop();
            for(auto i : graph[node_i]){
                if(dis[i.first] < dis[node_i] * i.second){
                    dis[i.first] = dis[node_i] * i.second;
                    node_queue.emplace(std::make_pair(dis[i.first],i.first));
                }     
            }
        }
        return dis[end];
    }
};

int main(){
    std::vector<std::vector<int>> e1({{0,1},{1,2},{0,2}}),e2({{0,1},{1,2},{0,2}}),e3({{0,1}}),e4({{1,4},{2,4},{0,4},{0,3},{0,2},{2,3}});
    std::vector<double> p1({0.5,0.5,0.2}),p2({0.5,0.5,0.3}),p3({0.5}),p4({0.37,0.17,0.93,0.23,0.39,0.04});
    int n1(3),n2(3),n3(3),n4(5); int s1(0),s2(0),s3(0),s4(3);int ed1(2),ed2(2),ed3(2),ed4(4);
    Solution s;

    std::cout<<s.maxProbability(n1,e1,p1,s1,ed1)<<std::endl;
    std::cout<<s.maxProbability(n2,e2,p2,s2,ed2)<<std::endl;
    std::cout<<s.maxProbability(n3,e3,p3,s3,ed3)<<std::endl;
    std::cout<<s.maxProbability(n4,e4,p4,s4,ed4)<<std::endl;

    return 0;
}