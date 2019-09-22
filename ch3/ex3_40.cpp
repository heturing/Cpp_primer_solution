#include <iostream>
#include <cstring>

using namespace std;

int main(){
	char cs1[] = "hejiaqi";
	char cs2[] = "zhutianqi";

	char cs3[end(cs1) - begin(cs2) + end(cs2) - begin(cs1)];
	strcpy(cs3, cs1);
	strcat(cs3, " ");
	strcat(cs3, cs2);
	for(auto cs : cs3){
		cout << cs;
	}
	cout << endl;
	return 0;

}
