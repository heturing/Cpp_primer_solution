#include <iostream>
#include <memory>
#include <vector>

using namespace std;

shared_ptr<vector<int>> test1(){
	return make_shared<vector<int>>();
}

void read_vector(shared_ptr<vector<int>> s){
	int i;
	while(cin >> i){
		s->push_back(i);
	}
	return;
}

void print_vector(shared_ptr<vector<int>> s){
	cout << "print" << endl;
	for(auto c : *s){
		cout << c << endl;
	}
	return;
}

int main(){
	shared_ptr<vector<int>> s = test1();
	read_vector(s);
	print_vector(s);
	return 0;
}
