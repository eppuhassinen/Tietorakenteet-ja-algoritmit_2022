#include <iterator>
#include <vector>
#include <algorithm>

using namespace std;


/**
 * @brief sort a given vector to an ascending order
 *
 * @param v vector to be sorted
 * @return int EXIT_SUCCESS if everything went OK, EXIT_FAILURE otherwise
 */

int sortAsc(std::vector<int>& v)
{
  // if (v.size() == 0) {return EXIT_FAILURE;}
  sort(v.begin(), v.end());

  return EXIT_SUCCESS;
}


