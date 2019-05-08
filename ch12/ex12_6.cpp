#include <iostream>
#include <vector>
#include <memory>

using namespace std;

vector<int>* test1(){
	return new vector<int>;
}

void read_vector(vector<int>* vp){
	int i;
	while(cin >> i){
		vp->push_back(i);
	}
	return;
}

void print_vector(vector<int>* vp){
	cout << "print" << endl;
	for(auto c : *vp){
		cout << c << endl;
	}
	return;
}

int main(){
	vector<int>* vp = test1();
	read_vector(vp);
	print_vector(vp);
	delete vp;
	return 0;
}
