#include<iostream>
#include "Sales_item.h"

int main(){
  // std::cout<<"hello, world."<<std::endl;
  int v1 = 0, v2 = 0;
  std::cout << "Enter two numbers:" << std::endl;
  std::cin >> v1 >> v2;
  std::cout << "The multiplication of ";
  std::cout << v1;
  std::cout << " and ";
  std::cout << v2;
  std::cout << " is ";
  std::cout << v1 * v2;
  std::cout << std::endl; 
  return 0;
}
