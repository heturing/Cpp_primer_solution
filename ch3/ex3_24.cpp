#include <iostream>
#include <vector>

using namespace std;

int main(){
	vector<int> v;
	int i;
	while(cin >> i){
		v.push_back(i);
	}

	for(auto it = v.cbegin(); it != v.cend(); it++){
		int temp = *it;
		if(++it != v.end()){
			temp += *it;
			cout << temp << " ";
		}
		else{
			cout << temp;
			break;
		}
	}
	cout << endl;

	auto beg = v.cbegin();
	auto end = v.cend();

	while(beg != end){
		end--;
		if(beg == end){
			cout << *beg;
			break;
		}
		cout << *beg + *end << " ";
		beg++;
	}

	cout << endl;

	return 0;
}
