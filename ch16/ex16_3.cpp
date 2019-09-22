#include <iostream>
#include <functional>
#include "../ch7/Sales_data.h"
using namespace std;

template<typename T> int compare(const T &v1, const T &v2){
	if(less<T>()(v1,v2)){
		return -1;
	}
	else if(less<T>()(v2, v1)){
		return 1;
	}
	else{
		return 0;	
	}
}

int main(){
	cout << compare(1,0) << endl;
	cout << compare(string("he"), string("jiaqi")) << endl;
	cout << compare(Sales_data(), Sales_data()) << endl;
	return 0;

}
