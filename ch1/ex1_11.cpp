#include <iostream>

using namespace std;

int main(){
	int a,b;
	cout << "please input 2 numbers: " << endl;
	cin >> a >> b;
	if(a > b){
		swap(a,b);
	}
	while(a < b){
		cout << a++ << " "; 
	}
	cout << endl;
	return 0;
}
