#include <iostream>
#include <string>
#include "iter.hpp"

template< typename T >
void printElement( T const & x ) {
  std::cout << x << " ";
}

template< typename T >
void addOne( T & x ) {
  x++;
}

int main() {
  std::cout << "ROUND 1: NON CONST " << std::endl;
  int tab[] = { 0, 1, 2, 3, 4 };
  size_t tab_size = 5;

  std::cout << "Before: ";
  iter( tab, tab_size, printElement<int> ); // Calls const overload of iter
  std::cout << std::endl;

  iter( tab, tab_size, addOne<int> ); // Calls non-const overload

  std::cout << "After:  ";
  iter( tab, tab_size, printElement<int> );
  std::cout << std::endl << std::endl;


  std::cout << "ROUND 2: CONST " << std::endl;
  const char c_tab[] = "Hello World!";
  size_t c_tab_size = 12;

  std::cout << "Printing const array: ";
  iter( c_tab, c_tab_size, printElement<char> ); // Must use const overload
  std::cout << std::endl;

  // following line should throw an compiler errorr!!!!!!!!!!!!!!!!!11!
   //iter( c_tab, c_tab_size, addOne<const char> );

  return 0;
}
