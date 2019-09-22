#include <iostream>
#include <stdexcept>

using namespace std;

int fact(){
	cout << "give me a number, and I will calculate the factorial of this number for you: " << endl;
	int i; 
	cin >> i;

	int res = 1;
	if(i < 0){
		throw runtime_error("negative number is not allowed.");
	}
	else if(i == 1){
		return 1;
	}
	else{
		while(i > 1){
			res *= i--;
		}
		return res;
	}
}

int main(){
	try{
		cout << fact() << endl;
	}
	catch(runtime_error err){
		cout << err.what() << endl;
		return -1;
	}
	return 0;
}
