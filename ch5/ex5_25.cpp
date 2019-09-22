#include <iostream>
#include <stdexcept>

using namespace std;

int main(){
	int a, b;
	double res = 0;
	cout << "give me two numbers" << endl;
	while(cin >> a >> b){
		try{
			if(b == 0){
				throw runtime_error("cannot divide by 0.");
			}
			res = a / b;
			cout << "res is " << res << endl;
		}
		catch(runtime_error err){
			cout << err.what() << endl;
			cout << "again (y/n)" << endl;
			string c;
			cin >> c;
			if(c == "n"){
				break;
			}
			else{
				cout << "give me two numbers" << endl;
			}
		}
	}
	return 0;
}

		

