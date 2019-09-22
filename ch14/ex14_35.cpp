#include <iostream>

using namespace std;


class ReadString{
public:
	ReadString(istream &i = cin) : in(i) {}
   	string operator()(string s){
		if(getline(in, s)){
			return s;
		}
		return "";
	}	
private:
	istream &in;

};

int main(){
	string s;
	ReadString rs;
	cout <<	rs(s);
	return 0;
}
