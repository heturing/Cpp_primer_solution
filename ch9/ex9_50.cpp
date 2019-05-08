#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
	vector<string> v = {"1","2","3","4","5"};
	vector<string> vd = {"1.1","2.2","3.3","4.4","5.5"};
	int sum = 0;
	double sumd = 0;
	for(auto c : v){
		int temp = stoi(c);
		sum += temp;
	}
	cout << sum << endl;

	for(auto c: vd){
		double temp = stod(c);
		sumd += temp;
	}
	cout << to_string(sumd) <<endl;
	return 0;
}
