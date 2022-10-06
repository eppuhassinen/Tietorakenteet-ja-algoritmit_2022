/**
 * iteration3.cc
 *
 * Print beginning half of a list
 */

/**
 * DO NOT ADD ANY INCLUDES!!
 */

#include <iostream>
#include <iterator> // for iterators
#include <list> // for lists
using namespace std;


void printHalf(const list<int>& lst)
{
  /**
  * Use iterators to go through the list and print elements
  */

  auto it = lst.begin();
  

  auto endpoint = lst.begin();
  advance(endpoint, distance(lst.begin(), lst.end())/2);

  while (it != endpoint)
  {
    cout << *it << " ";

    
    it++;
  }
}
