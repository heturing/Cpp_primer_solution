#include <iostream>
#include <string>
#include <forward_list>

using namespace std;

void find_and_insert(forward_list<string> &fls, const string s1, const string s2){
	auto prev = fls.before_begin();
	auto curr = fls.begin();
	while(curr != fls.end()){
		if(*curr == s1){
			fls.insert_after(curr, s2);
			return;
		}
		prev = curr;
		curr++;
	}
	if(curr == fls.end()){
		fls.insert_after(prev, s2);
	}
	return;
}

int main(){
	forward_list<string> flstr = {"he", "jia", "qi", "tian"};
	find_and_insert(flstr, "qi", "zhu");
	for(auto c : flstr){
		cout << c << endl;
	}
	return 0;
}
