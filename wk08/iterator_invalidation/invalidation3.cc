#include <iterator>
#include <vector>
#include <algorithm>

using namespace std;


/**
 * @brief duplicates even numbers in the vector, removes uneven numbers. Example: {1, 2, 3 4} -> {2, 2, 4, 4}
 *
 * @param v vector to be handled
 */
void duplicateEvenRemoveUneven(std::vector<int>& v) {

    using Iter = std::vector<int>::iterator;

    
    v.reserve(v.size() * 2);
    Iter it = v.begin();
    Iter end = v.end();
    while (it < end){
        if ( *it % 2 == 0 ){
            
            v.insert(it, *it);
            it += 2;
            end++;
        }
        else {
            v.erase(it);
            end--;
        } 
        
    } 
    v.shrink_to_fit();
}

