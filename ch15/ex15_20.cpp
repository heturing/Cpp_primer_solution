#include <iostream>

using namespace std;

class Base{
	public:
		void pub_mem();
	protected:
		int prot_mem;
	private:
		int priv_mem;
};

class Pub_Derv : public Base{
	public:
		void memfcn(Base &b) {b =*this;}
};

class Priv_Derv : private Base{
	public:
		void memfcn(Base &b) {b =*this;}
};

class Prot_Derv : protected Base{
	public:
		void memfcn(Base &b) {b =*this;}
};

class Derived_from_public : public Pub_Derv{
	public:
		void memfcn(Base &b) {b =*this;}
};

class Derived_from_private : public Priv_Derv{
	public:
		// This function is an error.
		// In this function, we assign an Derived_from_private object to an Base object, which needs implicit conversion from Derived_from_private to Base. Thus, This function must can access its Base part's copy assignment operator. However, Derived_from_private can only use Priv_Derv's public and protected member, while the copy assignment operator of Base becomes private in Priv_Derv
		void memfcn(Base &b) {b =*this;}
};

class Derived_from_protected : public Prot_Derv{
	public:
		void memfcn(Base &b) {b =*this;}
};
