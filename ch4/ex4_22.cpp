#include <iostream>

using namespace std;

int main(){
	int grade = 0;
	cin >> grade;
	string res = (grade > 90) ? "high pass" : (grade < 60) ? "fail" : (grade < 75) ? "low pass" : "pass";
   	cout << res << endl;
	return 0;
}	
