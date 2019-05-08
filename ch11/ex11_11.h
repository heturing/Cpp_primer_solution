#ifndef ex11_11
#define ex11_11

#include <iostream>
#include <set>
#include "Sales_item.h"

std::multiset<Sales_item, bool (*)(const Sales_item&, const Sales_item&)> bookstore(compareIsbn);

using my_type = bool (*)(const Sales_item&, const Sales_item&);
#endif
