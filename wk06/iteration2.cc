/**
 * iteration2.cc
 *
 * Print every second item of a list starting from the first item
 */

/**
 * DO NOT ADD ANY INCLUDES!!
 */

#include <iostream>
#include <iterator> // for iterators
#include <list> // for lists
using namespace std;


void printEverySecond(const list<int>& lst)
{
  /**
  * Use iterators to go through the list and print elements
  */

  auto it = lst.begin();
  unsigned int n = 0;

  while (it != lst.end())
  {
    if (n % 2 == 0) {cout << *it << " ";}

    n++;
    it++;
  }
}
