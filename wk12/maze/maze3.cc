#include <iterator>
#include <vector>
#include <algorithm>
#include "maze.hh"

using namespace std;

// Remember to implement your own container here or in another cc file to store the nodes in the maze
// If you define it elsewhere, remember to make sure it's accessible by this file as well.
void connectt(Node& node1, Node& node2, string dir, string back_dir)
{
    node1.paths[dir] = &node2;
    node2.paths[back_dir] = &node1;
}

/**
 * @brief Connect two adjacent nodes together. If the nodes are not adjacent, do nothing
 * 
 * @param fromNode  The node to connect from
 * @param toNode  The node to connect to
 */
void connectNodes(Node& node1, Node& node2) {
    std::cout << "connectNodes not implemented" << std::endl;
    // Student code here to connect the nodes together
    if ( (node1.loc.first - node2.loc.first) == 1 ) {
        if ( node1.loc.second - node2.loc.second == 0 ) {
            connectt(node1,node2,RIGHT,LEFT);
        }
    }
    if ( std::abs(node1.loc.second - node2.loc.second) == 1 ) {
        if ( node1.loc.first - node2.loc.first != 0 ) {
            connectt(node1,node2,ABOVE,BELOW);
        }
    }

    if ( (node2.loc.first - node1.loc.first) == -1 ) {
        if ( node1.loc.second - node2.loc.second == 0 ) {
            connectt(node1,node2,LEFT,RIGHT);
        }
    }
    if ( std::abs(node2.loc.second - node1.loc.second) == -1 ) {
        if ( node1.loc.first - node2.loc.first != 0 ) {
            connectt(node1,node2,BELOW,ABOVE);
        }
    }



}

