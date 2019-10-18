#include <iostream>
#include <regex>
#include <stdexcept>

using namespace std;

int main(){
	try{
		string s("[[:alnum:]+\\.(cpp|cxx|cc)", regex::icase);
		regex r(s);
	}
	catch(regex_error e){
		cout << e.what() << " " << e.code() << endl;
	}
	return 0;
}
