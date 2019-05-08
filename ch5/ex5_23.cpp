#include <iostream>
#include <stdexcept>

using namespace std;

int main(){
	int a, b;
	double res = 0;
	cout << "give me two numbers" << endl;
	cin >> a >> b;
	try{
		if(b == 0){
			throw runtime_error("cannot divide by 0.");
		res = a / b;
		}
	}
	catch(runtime_error err){
		cout << err.what() << endl;
		return -1;
	}
	cout << " res is " << res << endl;
	return 0;
}

		

