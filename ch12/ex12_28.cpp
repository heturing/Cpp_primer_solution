#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <sstream>

using namespace std;

int main(){
	// An ifstream for input file.
	ifstream ifs("./ex12_28.txt");
	using size_type = vector<string>::size_type; 
	string line, word;
	vector<string>::size_type line_no = 0;
	map<string, set<size_type>> m;
	vector<string> file_content;

	while(getline(ifs, line)){
	//Get a line from input file, line_no shows current line number.
	file_content.push_back(line);
    istringstream iss(line);
	while(iss >> word){
		//Process each word
		auto it = m.find(word);
		if(it != m.end()){
			//There is a record of word in m, add current line number to the set.
			it->second.insert(line_no);	
		}
		else{
			//No record of word in m, add a pair (word ,{1}) to m
			m[word] = set<size_type>{line_no};
			}
		}
		line_no++;
	}
	

	string search;
	while(true){
		cout << "Input a word your want to query. If you want to quit, input q" << endl;
		if(!(cin >> search) || search == "q") break;
		auto res = m.find(search);
		if(res != m.end()){
			//m contains a record of search.
			auto res_set = res->second;
			cout << "element " << search << " occurs in " << res_set.size() << " lines" <<endl;
		   	for(auto ele : res_set){
				cout << "(line " << ele << ") " << file_content[ele] << endl;
			}	
		}
		else{
			//No record for search
			cerr << "No occurence of " << search << endl;
		}
	}
	return 0;
}
