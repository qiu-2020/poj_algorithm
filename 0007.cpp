#include <iostream>
#include <string>
#include <map>
#include <list>
using namespace std;
// 在此处补充你的代码

void QueryResult(map<int, list<int> >::iterator lower,map<int, list<int> >::iterator up){
    while(lower != up){
        std::cout<<lower->first<<':'<<' ';
        for(auto it = lower->second.begin();it != lower->second.end();it++){
            std::cout<<*it<<' ';
        }
        std::cout<<std::endl;
        ++lower;
    }    
}

int main(int argc, char* argv[])
{
	map<int, list<int> > Attendance;
	map<int, list<int> >::iterator it;
	string cmd;
	int date, id, date_lower, date_upper;
	while (cin >> cmd){
		if (cmd == "add"){
			cin >> date >> id;
			it = Attendance.find(date);
			if (it != Attendance.end()){
				it->second.push_back(id);
			}
			else{
				list<int> lst_id;
				lst_id.push_back(id);
				Attendance.insert(make_pair(date,lst_id));
			}
		}
		else if (cmd == "query"){
			cin >> date_lower>>date_upper;
			QueryResult(Attendance.lower_bound(date_lower), Attendance.upper_bound(date_upper));
		}
		else if (cmd == "exit")
			return 0;
	}
	return 0;
}