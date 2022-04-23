#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Mat{
	int h,w;
public:
	Mat(int height,int width):h(height),w(width)
// 在此处补充你的代码
    {
        
    }

};    
int main()
{
	vector<Mat> m;
	m.push_back(Mat(2,2));
	m.push_back(Mat(3,4));
	m.push_back(Mat(2,2));
	cin >> m[0] >> m[1] >> m[2];
	sort(m.begin(),m.end());
	cout<< m[0] << endl << m[1] << endl << m[2] <<endl;
	cout<<"*************"<<endl;
	sort(m.begin(),m.end(),comparator_1);
	cout<< m[0] << endl << m[1] << endl << m[2] <<endl;
	cout<<"*************"<<endl;
	sort(m.begin(),m.end(),comparator_2());
	cout<< m[0] << endl << m[1] << endl << m[2] <<endl;
	return 0;
}