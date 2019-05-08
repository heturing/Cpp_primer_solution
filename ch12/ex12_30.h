#include <iostream>
#include <vector>
#include <memory>
#include <sstream>
#include <fstream>
#include <map>
#include <set>

using namespace std;

class QueryResult;

class TextQuery{
public:
	using line_no = vector<string>::size_type;
	TextQuery(ifstream &);
	QueryResult query(const string&) const;
private:
	shared_ptr<vector<string>> file; //Input file
	map<string, shared_ptr<set<line_no>>> wm;
};

class QueryResult{
friend ostream& print(ostream &, const QueryResult &);
public:
	QueryResult(string s, shared_ptr<set<TextQuery::line_no>> p, shared_ptr<vector<string>> f) : sought(s), lines(p), file(f) {}
private:
	string sought;
	shared_ptr<set<TextQuery::line_no>> lines;
	shared_ptr<vector<string>> file;
};

TextQuery::TextQuery(ifstream &ifs) : file(new vector<string>){
	string text;
	while(getline(ifs, text)){
		file->push_back(text);
		int n = file->size() - 1;
		istringstream line(text);
		string word;
		while(line >> word){
			auto &lines = wm[word];
			if(!lines){
				lines.reset(new set<line_no>);
			}
			lines->insert(n);
		}
	}
}

QueryResult TextQuery::query(const string &s) const{
	static shared_ptr<set<line_no>> nodata(new set<line_no>);
	
	auto loc = wm.find(s);
	if(loc == wm.end()){
		return QueryResult(s, nodata, file);
	}
	else{
		return QueryResult(s, loc->second, file);
	}
}

ostream& print(ostream &os, const QueryResult &qr){
	os << qr.sought << " occurs " << qr.lines->size() << "times" << endl;
	for(auto num : *(qr.lines)){
		os << "\t(line " << num + 1 << ")" << *(qr.file->begin() + num) << endl;
	}
	return os;
}
