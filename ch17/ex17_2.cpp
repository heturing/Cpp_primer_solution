#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

int main(){
	tuple<string, vector<string>, pair<string, int>> t("hejiaqi", {"hejiaqi"}, {"hejiaqi",1});
	cout << get<0>(t) << endl;
	return 0;	
}
