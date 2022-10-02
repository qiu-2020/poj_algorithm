#include "FindNumWithMostFactorsConcurrently.h"

using namespace std;

class Solution {
public:
    Solution(){}
    int findNumWithMostFactors(int n, int m) {
        // write your code
        int len_inter = m / n;
        // FindNumWithMostFactorsConcurrently f;
        auto pfind = FindNumWithMostFactorsConcurrently::getInstance();
        for(int i = 0;i < n - 1;++i){
            thread th(&(pfind->searchRange()),0,1);
        }
    }
};

