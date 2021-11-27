// vector::begin/end
#include <iostream>
#include <vector>

class node{
public:
    int a,b;
};

int main ()
{
//   std::vector<int> myvector;
//   for (int i=1; i<=5; i++) myvector.push_back(i);

//   std::cout << "myvector contains:";
//   for (std::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
//     std::cout << ' ' << *it;
//   std::cout << '\n';
//   std::cout<<myvector.back()<<std::endl;
    std::vector<node> v;
    node x;
    v.push_back(x);
    std::cout<<v.size()<<std::endl;

  return 0;
}