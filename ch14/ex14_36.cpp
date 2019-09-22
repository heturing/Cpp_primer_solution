#include <iostream>
#include <vector>
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
	vector<string> v;
	string s, temp;
	ReadString rs;
	while((temp =rs(s)) != ""){
		v.push_back(temp);
	}

	for(auto c: v){
		cout << c << endl;
	}
	return 0;
}
