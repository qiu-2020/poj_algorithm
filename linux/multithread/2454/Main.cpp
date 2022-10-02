#include <fstream>
#include "./Solution.h"
#include <iostream>
#include <thread>
#include <string>
#include <vector>

using namespace std;
const static thread::id mainThreadId = this_thread::get_id();
static ifstream infile;
static ofstream outfile;
static int n, m;

int main(int argc, char* argv[])
{
    string in_path = argv[1];
    string out_path = argv[2];
    infile.open(in_path);
    outfile.open(out_path);
    string s;
    string list[2] = {};
    char c[20];
    infile.getline(c, 20);
    s = c;
    int n = stoi(s);
    infile.getline(c, 20);
    s = c;
    int m = stoi(s);
    FindNumWithMostFactorsConcurrently* instance = FindNumWithMostFactorsConcurrently::getInstance();
    Solution solution;
    int answer = solution.findNumWithMostFactors(n, m);
    outfile << answer << endl;
    infile.close();
    outfile.close();
    return 0;
}