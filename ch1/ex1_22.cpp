#include <iostream>
#include "Sales_item.h"

using namespace std;

int main(){
	Sales_item sum, item;
	if(cin >> sum){
		while(cin >> item){
			if(item.isbn() == sum.isbn()){
				sum += item;
			}
			else{
				return -1;
			}
		}
		cout << sum << endl;
	}
	return 0;
}
