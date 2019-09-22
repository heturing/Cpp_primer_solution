#include <iostream>
#include <vector>

using namespace std;

int main(){
	int i;
	vector<int> v;
	while(cin >> i){
		v.push_back(i);
	}

	cout << "print adjacent" << endl;
	for(vector<int>::size_type sz = 0; sz != v.size(); sz++){
		int temp = v[sz];
		if((++sz) != v.size()){
			temp += v[sz];
		}
		else{
			cout << temp;
			break;
		}
		cout << temp << " ";
	}
	cout << endl;

	cout << "print head and tail" << endl;
	vector<int>::size_type head;
	for(head = 0; head != v.size() / 2; head++){
		int temp = v[head] + v[v.size() - 1 - head];
		cout << temp << " ";
	}
	if(2 * head != v.size()){
		cout << v[head];
	}
	cout << endl;
	return 0;
}
