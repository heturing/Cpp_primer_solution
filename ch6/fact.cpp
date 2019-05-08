#include "Chapter6.h"

int fact(int n){
	int res = 1;
	while(n != 0){
		res *= n--;
	}
	return res;
}
