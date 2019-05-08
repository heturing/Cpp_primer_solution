#include <iostream>
#include <vector>

using namespace std;

int main(){
	int repetition = 0, max = 0;
	string last = "", current = "";

	while(cin >> current){
		if(last == current || last == ""){
			++repetition;
		}
		else{
			if(repetition > max){
				max = repetition;
			}
			repetition = 1;
		}
		last = current;
	}
	cout << max << endl;
	return 0;
}


