#include "./Blob.h"
#include "./BlobPrt.h"

using namespace std;


int main(){
	Blob<int> b{1,3,5};
	BlobPtr<int> bp(b);
	cout << *bp << endl;
	++bp;
	cout << *bp << endl;
}
