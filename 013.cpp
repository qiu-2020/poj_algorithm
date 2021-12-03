#include <iostream>
#include <string>

std::string s_1,s_2,s_3;
int len1,len2,len3;
//bool ans1[]


bool zipper(int s1,int s3){
    if(s1 == len1)
        return true;
    else if(s1 != len1 && s3 == len3)
        return false;    
    else{
        if(s_1[s1] == s_3[s3]) return zipper(s1 + 1,s3 + 1);
        else{
            return zipper(s1,s3 + 1);
        }
    }    
}

int main(){
    int n;
    std::cin>>n;
    for(int i = 0;i < n;++i){
        std::cin>>s_1>>s_2>>s_3;
        len1 = s_1.size();
        len2 = s_2.size();
        len3 = s_3.size();
        if(zipper(0,0))
            std::cout<<"Data set 1:"<<"yes"<<std::endl;
        else
            std::cout<<"Data set 2:"<<"no"<<std::endl;     
    }

    return 0;
}