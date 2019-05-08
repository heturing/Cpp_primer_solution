#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <memory>
#include <fstream>

using namespace std;

class QueryResult;

class TextQuery{
public:
	using line_no = vector<string>::size_type;
	TextQuery(ifstream &);
	QueryResult query(string s); 
private:
	shared_ptr<vector<string>> file_ptr;
	map<string, shared_ptr<set<line_no>>> m_ptr;
};

class QueryResult{
public:
	QueryResult(string s, shared_ptr<set<TextQuery::line_no>> ln, shared_ptr<vector<string>> inp) : search(s), input_ptr(inp), index_ptr(ln) {}
private:
	string search;
	shared_ptr<vector<string>> input_ptr;
	shared_ptr<set<TextQuery::line_no>> index_ptr;
};
