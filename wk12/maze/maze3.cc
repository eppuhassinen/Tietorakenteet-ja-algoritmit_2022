#include <iterator>
#include <vector>
#include <algorithm>
#include "maze.hh"

using namespace std;

// Remember to implement your own container here or in another cc file to store the nodes in the maze
// If you define it elsewhere, remember to make sure it's accessible by this file as well.


/**
 * @brief Connect two adjacent nodes together. If the nodes are not adjacent, do nothing
 * 
 * @param fromNode  The node to connect from
 * @param toNode  The node to connect to
 */
void connectNodes(Node& node1, Node& node2) {
    std::cout << "connectNodes not implemented" << std::endl;
    // Student code here to connect the nodes together
    if ((std::abs(node1.loc.first - node2.loc.first) == 1 && node1.loc.second - node2.loc.second == 0)
     || (std::abs(node1.loc.second - node2.loc.second) == 1  && node1.loc.first - node2.loc.first == 0) )

    if (node1.loc.first < node2.loc.first)
    {
        node1.paths[RIGHT] = &node2;
        node2.paths[LEFT] = &node1;
        return;
    }

    if (node1.loc.first > node2.loc.first)
    {
        node1.paths[LEFT] = &node2;
        node2.paths[RIGHT] = &node1;
        return;
    }

    if (node1.loc.second < node2.loc.second)
    {
        node1.paths[ABOVE] = &node2;
        node2.paths[BELOW] = &node1;
        return;
    }

    if (node1.loc.second > node2.loc.second)
    {
        node1.paths[BELOW] = &node2;
        node2.paths[ABOVE] = &node1;
        return;
    }

}
