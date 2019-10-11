#include <iostream>

using namespace std;

template <typename T, U, typename V> void f1(T,U,V);

inline template <typename T> T foo(T, unsigned int *);
