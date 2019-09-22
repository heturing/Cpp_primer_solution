#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class PersonInfo{
	public:
		string name;
		vector<string> phones;
};

ostream& operator<<(ostream& os, const PersonInfo &pi){
		os << "name" << pi.name << endl;
		os << "phones ";
		for(auto c : pi.phones){
			os << c << " ";
		}
		os << endl;

		string name;
		vector<string> phones;
		return os;
};

int main(){
	string line, word;
	vector<PersonInfo> people;
	istringstream record;
	while(getline(cin, line)){
		PersonInfo info;
		record = istringstream(line);
		record >> info.name;
		while(record >> word){
			info.phones.push_back(word);
		}

		people.push_back(info);
	}
	
	for(auto p : people){
		cout << p;
	}
	return 0;
}
