#include<iostream>
#include<cstring>
#include<list>
#include<algorithm>
using namespace std;

class TV_Drama{
public:
	char name[100];
	int actor;
	int story;
	int acting_skill;
// 在此处补充你的代码
    TV_Drama(char* n,int a,int s,int a_s):actor(a),story(s),acting_skill(a_s){
        strcpy(name,n);
    }
    bool operator<(const TV_Drama& t){
        return actor >= t.actor;
    }

};

// class Printer{
// public:
//     void operator()(const TV_Drama& t){
//         std::cout<<t.name<<';';
//     }
// };

void Printer(const TV_Drama& t){
    std::cout<<t.name<<';';
}

bool comparator_1(const TV_Drama& t1,const TV_Drama& t2){
    return t1.story >= t2.story;
}

class comparator_2{
public:
	bool operator()(const TV_Drama& t1,const TV_Drama& t2){
		return t1.acting_skill >= t2.acting_skill;
	}	
};

int main(){
	list<TV_Drama> lst;
	int n;
	
	cin>>n;
	char  _name[100];
	int _actor, _story, _acting_skill;
	for (int i=0; i<n; i++){
        cin.ignore();
        cin.getline(_name,100);
        cin>>_actor>>_story>>_acting_skill;
		lst.push_back(TV_Drama(_name, _actor, _story, _acting_skill));
	}

	lst.sort();
	for_each(lst.begin(), lst.end(), Printer);	
	cout<<endl;

	lst.sort(comparator_1);
	for_each(lst.begin(), lst.end(), Printer);	
	cout<<endl;

	lst.sort(comparator_2());
	for_each(lst.begin(), lst.end(), Printer);	
	cout<<endl;

	return 0;
}