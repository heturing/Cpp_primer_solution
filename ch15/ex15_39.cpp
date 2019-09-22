#include "./TextQuery.h"
#include "./Query.h"

using namespace std;

int main(){
	ifstream ifs("./Text.txt");
	TextQuery tq(ifs);
	Query q = Query("fiery") & Query("bird") | Query("wind");
	cout << q << endl;
	print(cout, q.eval(tq)) << endl;
	return 0;
}
