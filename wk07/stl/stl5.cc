#include <iterator>
#include <vector>
#include <algorithm>

using namespace std;


/**
 * @brief Arrange vector in three subsequent sections:
 *        - those divisible by three (asc order)
 *        - those whose reminder is 1 (asc order)
 *        - those whose reminder is 2 (asc order)
 * @param v a sortable vector
 * @return int EXIT_SUCCESS if everything went OK, EXIT_FAILURE otherwise
 */
int sortMod3(std::vector<int>& v)
{
  vector<int> jee = {};
  sort(v.begin(), v.begin());
  for_each(v.begin(), v.end(), [&jee](auto x){if(x%3 == 0){jee.push_back(x);}});
  for_each(v.begin(), v.end(), [&jee](auto x){if(x%3 == 1){jee.push_back(x);}});
  for_each(v.begin(), v.end(), [&jee](auto x){if(x%3 == 2){jee.push_back(x);}});

  v = jee;
}

