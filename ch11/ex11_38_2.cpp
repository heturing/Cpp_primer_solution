#include <iostream>
#include <sstream>
#include <fstream>
#include <unordered_map>
#include <string>
#include <stdexcept>

using namespace std;

unordered_map<string, string> build_map(ifstream &ifs){
	unordered_map<string, string> trans_map;
	string key, value;
	
	while(ifs >> key && getline(ifs, value)){
		if(value.size() > 1){
			trans_map[key] = value.substr(1);
		}
		else{
			throw runtime_error("no rule for " + key);
		}
	}
	return trans_map;
}

const string& transform(const string &s, const unordered_map<string, string> &m){
	auto map_it = m.find(s);
	if(map_it != m.end()){
		return map_it->second;
	}
	else{
		return s;
	}
}


void word_transform(ifstream &map_file, ifstream &input){
	auto trans_map = build_map(map_file);
	string text;

	while(getline(input, text)){
		istringstream iss(text);
		bool is_first = true;
		string word;
		while(iss >> word){
			if(is_first){
				is_first = false;
			}
			else{
				cout << " ";
			}
			cout << transform(word, trans_map);
		}
		cout << endl;
	}
}

int main(){
	ifstream ifs1("./ex11_33_1.txt"), ifs2("./ex11_33_2.txt");
	word_transform(ifs1, ifs2);
	return 0;
}
