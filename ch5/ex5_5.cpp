#include <iostream>
#include <vector>

using namespace std;

int main(){
	vector<string> v = {"F", "D", "C", "B", "A", "A++"};
	int grade = 0;
	string res = "";
	while(cin >> grade){
		if(grade < 60){
			res = v[0];
		}
		else{
			res = v[(grade - 50) / 10];
		}
		cout << "Your numeric grade is " << grade << ", and your letter grade is " << res << endl; 
	}
	return 0;
}

