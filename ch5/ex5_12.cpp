#include <iostream>
#include <string>

using namespace std;

int main(){
	string s = "";
	int fCount = 0, lCount = 0, iCount = 0;
	while(cin >> s){
		for(auto iter = s.begin(); iter != s.end(); iter++){
			if(*iter == 'f'){
				if(iter+1 != s.end()){
					switch(*(iter+1)){
						case 'f':
							++fCount;
							++iter;
							break;
						case 'l':
							++lCount;
							++iter;
							break;
						case 'i':
							++iCount;
							++iter;
							break;
						default:
							;
					}
				}
			}
		}
	}
	cout << "There are " << fCount << " ff, " << lCount << " fl, " << iCount << " fi." << endl;
  	return 0;
}	

			
