#include <iostream>
#include <Python/Python.h>

//On MacOS, you need to tell g++ about python's framework with -framework Python

using namespace std;

int main(){
	Py_Initialize();

	PyRun_SimpleString("print 'hello'");

	Py_Finalize();
}
